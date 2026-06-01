public class InputProcessor extends InputAdapter {
    private Tetris tetris;

    public InputProcessor(Tetris tetris) {
        this.tetris = tetris;
    }

    @Override
    public boolean keyDown(int keycode) {

        if (keycode == Input.Keys.UP || keycode == Input.Keys.W) {
            tetris.piece.blocks = tetris.piece.rotate();
        }

        if (keycode == Input.Keys.DOWN || keycode == Input.Keys.S) {
            tetris.piece.move(new Vector2(0, -1));
        }

        if (keycode == Input.Keys.LEFT || keycode == Input.Keys.A) {
            tetris.piece.move(new Vector2(-1, 0));
        }

        if (keycode == Input.Keys.RIGHT || keycode == Input.Keys.D) {
            tetris.piece.move(new Vector2(1, 0));
        }

        if (keycode == Input.Keys.SPACE) {
            tetris.hardDrop();
            tetris.lockPiece();
            tetris.spawnPiece();
        }
        return false;
    }

}
