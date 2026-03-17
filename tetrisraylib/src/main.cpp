/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"

#include "resource_dir.h"
#include "game.h"
#include <ctime>
#include <cstdlib>



int main ()
{
	srand(time(NULL));

	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(700, 650, "Hello Raylib");
	SearchAndSetResourceDir("resources");

	Game game;
	
	// game loop
	while (!WindowShouldClose())
	{
		game.inputs();
		game.update();

		// drawing
		BeginDrawing();

		ClearBackground(BLACK);
		game.draw();

		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
