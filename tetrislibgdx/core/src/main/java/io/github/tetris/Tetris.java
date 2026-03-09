package io.github.tetris;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Random;

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

    ArrayList<Piece> pieces = new ArrayList<Piece>();

    Queue<Integer> pieceQueue = new LinkedList<>();
    

    public Tetris(){
        for(int i = 0;i < gridWidth; i++){
            for(int j = 0; j < gridHeight; j++){
                grid[i][j] = 0;
            }
        }

        spawnPiece();
    }

    public void spawnPiece(){
        //TODO: make the spawnPiece come from a list of pieces and not just random.

        int num = getNextPieceNum();
        Vector2 spawnPosition = new Vector2(4,19);
        Piece protPiece = new Piece(num, this, spawnPosition);
        if(isSpawnBlocked(protPiece, spawnPosition)){
            //game over
            gameOver();
            //System.out.println(isSpawnBlocked(protPiece, spawnPosition));
            //System.out.println("Game Over");
        } else {
            piece = new Piece(num, this, spawnPosition);
        }

        //piece = new Piece(new Random().nextInt(7) + 1, this, new Vector2(4, 19));
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

                //TODO: if for each piece type and color
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
            grid[x][y] = piece.num;
        }
        cleanLine();
        System.out.println("lockou a peça");
    }

    public void hardDrop(){
        Boolean canFall = true;

        while(canFall){
            if(piece.canFall()){
                //System.out.println("caindo");
            } else {
                canFall = false;
            }
        }
    }


    public void cleanLine(){
        
        for(int i = 0; i <= gridHeight - 1; i++){
            boolean lineFull = true;
            for(int j = 0; j < gridWidth; j++){
                if(grid[j][i] == 0){
                    lineFull = false;
                    break;
                }
            }
            if(lineFull){
                removeline(i--);
            }
        }
    }

    public void removeline(int lineIndex){
        for(int i = lineIndex; i < gridHeight - 1; i++){
            for(int j = 0; j < gridWidth; j++){
                grid[j][i] = grid[j][i + 1];
            }
        }
        for(int j = 0; j < gridWidth; j++){
            grid[j][gridHeight - 1] = 0;
        }
    }

    public Boolean isSpawnBlocked(Piece piece, Vector2 spawnPosition){
        for(Vector2 block : piece.blocks){
            int x = (int)(spawnPosition.x + block.x);
            int y = (int)(spawnPosition.y + block.y);

            if(x < 0 || x >= gridWidth || y < 0 ){
                return true;
            }

            if(y >= gridHeight){
                continue;
            }

            System.out.println("x: " + x + " y: " + y);
            if(grid[x][y] >= 1){
                return true;
            }
        }
        return false;
    }

    public void gameOver(){
        for(int i = 0; i < gridWidth; i++){
            for(int j = 0; j < gridHeight; j++){
                if(grid[i][j] >= 1){
                    grid[i][j] = 9;
                    //TODO: MAKE A COLOR FOR THE LOCKED BLOCKS AND NOT JUST MAKE THEM ALL RED
                }
            }
        }
    }

    public void refillPieceQueue(){
        pieceQueue.add(1);
        pieceQueue.add(2);
        pieceQueue.add(3);
        pieceQueue.add(4);
        pieceQueue.add(5);
        pieceQueue.add(6);
        pieceQueue.add(7);
        Collections.shuffle((List<Integer>) pieceQueue);
    }

    public int getNextPieceNum(){
        if(pieceQueue.isEmpty()){
            refillPieceQueue();
        }
        return pieceQueue.poll();
    }

    
}
