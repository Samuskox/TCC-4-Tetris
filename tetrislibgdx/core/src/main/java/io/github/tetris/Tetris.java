package io.github.tetris;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.math.Vector2;

import space.earlygrey.shapedrawer.ShapeDrawer;

public class Tetris {
    int cellSize = 32;
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
        drawLines(shapeDrawer);
        shapeDrawer.setColor(Color.RED);
        for(int i = 0; i < gridWidth; i++){
            for (int j = 0; j < gridHeight; j++) {
                if (grid[i][j] > 1){
                    shapeDrawer.filledRectangle(
                        (i * cellSize) + Gdx.graphics.getWidth()/2 - (gridWidth * cellSize)/2,
                         (j * cellSize), cellSize - (spaceBetweenCells * 2),
                          cellSize - (spaceBetweenCells * 2), Color.RED);
                }
            }
        }
    }

    public void drawLines(ShapeDrawer shapeDrawer){
        shapeDrawer.setColor(Color.WHITE);
        float offsetX = Gdx.graphics.getWidth()/2f 
                    - (gridWidth * cellSize)/2f;
        for(int i = 0; i <= gridWidth; i++){
            shapeDrawer.line(offsetX + (i * cellSize), 0, offsetX + (i * cellSize), gridHeight * cellSize);
        }
        for(int j = 0; j <= gridHeight; j++){
            shapeDrawer.line(offsetX, j * cellSize, offsetX + (gridWidth * cellSize), j * cellSize);
        }
    }
    
}
