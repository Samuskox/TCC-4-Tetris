package io.github.tetris;

import com.badlogic.gdx.Input;
import com.badlogic.gdx.InputAdapter;

public class InputProcessor extends InputAdapter {
    private Tetris tetris;
    public InputProcessor(Tetris tetris){
        this.tetris = tetris;
    }
    
    @Override
    public boolean keyDown (int keycode) {

        if (keycode == Input.Keys.UP || keycode == Input.Keys.W){
            System.out.println("UP");
        }

        if (keycode == Input.Keys.DOWN || keycode == Input.Keys.S){
            tetris.piece.move(0, -1);
            System.out.println("x: " + tetris.piece.position.x + " y: " + tetris.piece.position.y);
        }

        if(keycode == Input.Keys.LEFT || keycode == Input.Keys.A){
            tetris.piece.move(-1, 0);
            System.out.println("x: " + tetris.piece.position.x + " y: " + tetris.piece.position.y);
        }

        if(keycode == Input.Keys.RIGHT || keycode == Input.Keys.D){
            tetris.piece.move(1, 0);
            System.out.println("x: " + tetris.piece.position.x + " y: " + tetris.piece.position.y);
        }

        if(keycode == Input.Keys.SPACE){
            System.out.println("SPACE");
        }
        
		return false;
	}

}
