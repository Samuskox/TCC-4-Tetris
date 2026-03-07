package io.github.tetris;

import com.badlogic.gdx.Input;
import com.badlogic.gdx.InputAdapter;
import com.badlogic.gdx.math.Vector2;

public class InputProcessor extends InputAdapter {
    private Tetris tetris;
    public InputProcessor(Tetris tetris){
        this.tetris = tetris;
    }
    
    @Override
    public boolean keyDown (int keycode) {

        if (keycode == Input.Keys.UP || keycode == Input.Keys.W){
            System.out.println("Rotate");
            tetris.piece.blocks = tetris.piece.rotate();
        }

        if (keycode == Input.Keys.DOWN || keycode == Input.Keys.S){
            tetris.piece.move(new Vector2(0, -1));
            System.out.println("x: " + tetris.piece.position.x + " y: " + tetris.piece.position.y);
        }

        if(keycode == Input.Keys.LEFT || keycode == Input.Keys.A){
            tetris.piece.move(new Vector2(-1, 0));
            System.out.println("x: " + tetris.piece.position.x + " y: " + tetris.piece.position.y);
        }

        if(keycode == Input.Keys.RIGHT || keycode == Input.Keys.D){
            tetris.piece.move(new Vector2(1, 0));
            System.out.println("x: " + tetris.piece.position.x + " y: " + tetris.piece.position.y);
        }

        if(keycode == Input.Keys.SPACE){
            tetris.lockPiece();
            tetris.spawnPiece();
        }
        
		return false;
	}

}
