package io.github.tetris;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.math.Vector2;

import space.earlygrey.shapedrawer.ShapeDrawer;

public class Tetris {
    int cellSize = 24;
    int spaceBetweenCells = 1;
    int gridWidth = 10;
    int gridHeight = 20;
    int grid[][] = new int[gridWidth][gridHeight];

    Piece piece;

    public Tetris(){
        

        for(int i = 0;i < gridWidth; i++){
            for(int j = 0; j < gridHeight; j++){
                grid[i][j] = 0;
            }
        }

        spawnPiece();
    }

    public void spawnPiece(){
        piece = new Piece(3, this, new Vector2(4, 19));
    }

    public void drawGrid(ShapeDrawer shapeDrawer){
        
        shapeDrawer.setColor(Color.RED);
        for(int i = 0; i < gridWidth; i++){
            for (int j = 0; j < gridHeight; j++) {
                if (grid[i][j] >= 1){
                    shapeDrawer.filledRectangle(
                        (i * cellSize) + Gdx.graphics.getWidth()/2 - (gridWidth * cellSize)/2,
                         (j * cellSize), cellSize - (spaceBetweenCells * 2),
                          (cellSize - (spaceBetweenCells * 2)) + 1,
                           Color.RED);
                }
            }
        }
        drawLines(shapeDrawer);
    }

    public void drawLines(ShapeDrawer shapeDrawer){
        shapeDrawer.setColor(Color.WHITE);
        float offsetX = (Gdx.graphics.getWidth()/2f 
                    - (gridWidth * cellSize)/2f) - 1;
        for(int i = 0; i <= gridWidth; i++){
            shapeDrawer.line(offsetX + (i * cellSize), 0, offsetX + (i * cellSize), gridHeight * cellSize, 2);
        }
        for(int j = 0; j <= gridHeight; j++){
            shapeDrawer.line(offsetX, (j * cellSize), offsetX + (gridWidth * cellSize), j * cellSize, 2);
        }

        //shapeDrawer.line(offsetX, offsetX, offsetX, offsetX, offsetX);
    }

    public void lockPiece(){
        for(Vector2 block : piece.blocks){
            int x = (int)(piece.position.x + block.x);
            int y = (int)(piece.position.y + block.y);
            grid[x][y] = 1;
        }
        System.out.println("lockou a peça");
    }
    
}
