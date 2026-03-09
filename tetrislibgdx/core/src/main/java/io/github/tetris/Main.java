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

    //private float delta = Gdx.graphics.getDeltaTime();
    private float fallTimer = 0;
    private float fallInterval = 1.0f;

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
        //System.out.println("delta: " + Gdx.graphics.getDeltaTime());
        fallTimer += Gdx.graphics.getDeltaTime();
        if(fallTimer >= fallInterval){
            //System.out.println("one seconds passing");
            //System.out.println("time reseting");
            fallTimer = 0;
            tetris.piece.canFall();

        }

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

        for(int i = 0; i < tetris.gridWidth; i++){
            for(int j = 0; j < tetris.gridHeight; j++){
                tetris.grid[i][j] = 0;
            }
        }

        for(int i = 0; i < tetris.gridWidth - 1; i++){
            for(int j = 0; j < 3; j++){
                tetris.grid[i][j] = 1;
            }
        }
    }
}
