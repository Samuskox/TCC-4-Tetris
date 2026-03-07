package io.github.tetris;

import com.badlogic.gdx.ApplicationAdapter;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.utils.ScreenUtils;
import space.earlygrey.shapedrawer.ShapeDrawer;

/** {@link com.badlogic.gdx.ApplicationListener} implementation shared by all platforms. */
public class Main extends ApplicationAdapter {
    private SpriteBatch batch;
    private TextureRegion image;
    private ShapeDrawer shapeDrawer;
    private InputProcessor inputProcessor;

    


    private Tetris tetris;

    // float gridPixelWidth = tetris.gridWidth * tetris.cellSize;
    // float startX = (Gdx.graphics.getWidth() - gridPixelWidth) / 2f;
    // float padding = tetris.spaceBetweenCells;
    // float cellSizeWithSpace = tetris.cellSize - (padding * 2);

    @Override
    public void create() {
        batch = new SpriteBatch();
        image = new TextureRegion(new Texture("blankTexture.png"));
        shapeDrawer = new ShapeDrawer(batch, image);
        tetris = new Tetris();
        
        inputProcessor = new InputProcessor(tetris);
        Gdx.input.setInputProcessor(inputProcessor);
        test();
    }

    @Override
    public void render() {
        ScreenUtils.clear(0.15f, 0.15f, 0.2f, 1f);
        batch.begin();
        batch.setColor(Color.WHITE);
        shapeDrawer.setColor(Color.YELLOW);
        tetris.drawGrid(shapeDrawer);
        tetris.piece.draw(shapeDrawer);

        batch.end();
    }

    @Override
    public void dispose() {
        batch.dispose();
    }

    public void test(){
        tetris.grid[0][0] = 1;
        tetris.grid[3][7] = 1;
    }
}
