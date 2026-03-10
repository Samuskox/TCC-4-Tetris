package io.github.tetris;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.math.Vector2;

import space.earlygrey.shapedrawer.ShapeDrawer;

public class Piece {
    //TO DO: make this more efficient by using a single array of Vector2s and just rotating them instead of having 7 different arrays for each piece
    // TODO: Put this o piece when instantiating the piece instead of having 7 different arrays for each piece and a switch statement in the constructor
    Color color;
    Vector2[] blocks;
    Vector2 position;
    int num;
    Tetris tetris;
    

    Vector2[] iP = {
            new Vector2(-1, 0),
            new Vector2(0, 0),
            new Vector2(1, 0),
            new Vector2(2, 0)
    };

    Vector2[] sP = {
            new Vector2(0, 0),
            new Vector2(1, 0),
            new Vector2(0, 1),
            new Vector2(-1, 1)
    };

    Vector2[] zP = {
            new Vector2(0, -1),
            new Vector2(0, 0),
            new Vector2(-1, 0),
            new Vector2(-1, 1)
    };

    Vector2[] tP = {
            new Vector2(0, -1),
            new Vector2(0, 0),
            new Vector2(1, 0),
            new Vector2(0, 1)
    };

    Vector2[] oP = {
            new Vector2(0, 0),
            new Vector2(0, 1),
            new Vector2(1, 0),
            new Vector2(1, 1)
    };

    Vector2[] lP = {
            new Vector2(-1, 0),
            new Vector2(0, 0),
            new Vector2(1, 0),
            new Vector2(1, 1)
    };

    Vector2[] jP = {
            new Vector2(-1, 0),
            new Vector2(0, 0),
            new Vector2(1, 0),
            new Vector2(-1, 1)
    };


    public Piece(int num, Tetris tetris, Vector2 pos){
        this.num = num;
        this.tetris = tetris;
        this.position = new Vector2(pos.x, pos.y);
        System.out.println("Num:"+num);
        switch(num){
            case 1:
                blocks = iP;
                color = Color.CYAN;
                break;
            case 2:
                blocks = sP;
                color = Color.GREEN;
                break;
            case 3:
                blocks = zP;
                color = Color.RED;
                break;
            case 4:
                blocks = tP;
                color = Color.PURPLE;
                break;
            case 5:
                blocks = oP;
                color = Color.YELLOW;
                break;
            case 6:
                blocks = lP;
                color = Color.ORANGE;
                break;
            case 7:
                blocks = jP;
                color = Color.BLUE;
                break;
        }
    }

    public void draw(ShapeDrawer shapeDrawer){
        float offsetX = Gdx.graphics.getWidth()/2f - (tetris.gridWidth * tetris.cellSize)/2f;
        float size   = tetris.cellSize - (tetris.spaceBetweenCells * 2);
        shapeDrawer.setColor(color);
        for(Vector2 block : blocks){
            shapeDrawer.filledRectangle(
            offsetX + (position.x + block.x) * tetris.cellSize,
            ((position.y + block.y) * tetris.cellSize) + 1,
            size,
            size);
        }
    }

    public void move(Vector2 direction){
        Vector2 newPosition = new Vector2(position.x + direction.x, position.y + direction.y);
        if (!isValidMove(newPosition, blocks)){
            return;
        }

        //System.out.println("Valid move");
        position.x += direction.x;
        position.y += direction.y;
        tetris.lockTimer = 0;
    }

    public boolean isValidMove(Vector2 targetPosition, Vector2[] targetBlocks){
        for(Vector2 block : targetBlocks){
            int newX = (int)(targetPosition.x + block.x);
            int newY = (int)(targetPosition.y + block.y);

            if(newX < 0 || newX >= tetris.gridWidth || newY < 0){
                return false;
            }
            if(newY >= tetris.gridHeight){
                continue;
            }

            if(tetris.grid[newX][newY] > 0){
                return false;
            }
        }
        return true;
    }

    public Vector2[] rotate(){
        Vector2[] newBlocks = new Vector2[blocks.length];
        for(int i = 0; i < blocks.length; i++){
            newBlocks[i] = new Vector2(blocks[i].y, -blocks[i].x);
        }
        if (isValidMove(position, newBlocks)){
            tetris.lockTimer = 0;
            return newBlocks;
        }
        if (isValidMove(new Vector2(position.x + 1, position.y), newBlocks)){
            position.x += 1;
            tetris.lockTimer = 0;
            return newBlocks;
        }
        if (isValidMove(new Vector2(position.x - 1, position.y), newBlocks)){
            position.x -= 1;
            tetris.lockTimer = 0;
            return newBlocks;
        }
        if(isValidMove(new Vector2(position.x, position.y + 1), newBlocks)){
            position.y += 1;
            tetris.lockTimer = 0;
            return newBlocks;
        }
        return blocks;
    }

    public Boolean canFall(){
        if(isValidMove(new Vector2(position.x, position.y - 1), blocks)){
            //System.out.println("fallindo");
            move(new Vector2(0,-1));
            return true;
        }
        return false;
        
    }
}
