package io.github.tetris;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.math.Vector2;

import space.earlygrey.shapedrawer.ShapeDrawer;

public class Piece {

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
        switch(num){
            case 0:
                blocks = iP;
                break;
            case 1:
                blocks = sP;
                break;
            case 2:
                blocks = zP;
                break;
            case 3:
                blocks = tP;
                break;
            case 4:
                blocks = oP;
                break;
            case 5:
                blocks = lP;
                break;
            case 6:
                blocks = jP;
                break;
        }
    }

    public void draw(ShapeDrawer shapeDrawer){
        float offsetX = Gdx.graphics.getWidth()/2f - (tetris.gridWidth * tetris.cellSize)/2f;
        float size   = tetris.cellSize - (tetris.spaceBetweenCells * 2);

        for(Vector2 block : blocks){
            shapeDrawer.filledRectangle(
                offsetX + (position.x + block.x) * tetris.cellSize,
                (position.y + block.y) * tetris.cellSize,
                size,
                size);
        }
    }

    public void move(int dx, int dy){
        if (!isValidMove(dx, dy)){
            return;
        }

        System.out.println("Valid move");
        position.x += dx;
        position.y += dy;
    }

    public boolean isValidMove(int dx, int dy){
        for(Vector2 block : blocks){
            int newX = (int)(position.x + block.x + dx);
            int newY = (int)(position.y + block.y + dy);

            if(newX < 0 || newX >= tetris.gridWidth || newY < 0 || newY >= tetris.gridHeight){
                return false;
            }

            if(tetris.grid[newX][newY] > 0){
                return false;
            }
        }
        return true;
    }
}
