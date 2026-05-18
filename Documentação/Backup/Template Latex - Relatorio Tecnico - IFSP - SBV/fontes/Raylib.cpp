#include "raylib.h"

int main() {
    // Determina a altura e largura da janela
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Inicializa a janela
    InitWindow(screenWidth, screenHeight, "My Game");

    // Configura quantos quadros por segundo
    SetTargetFPS(60);

    // O Loop do jogo
    while (!WindowShouldClose() /*WindowShouldClose retorna 
    verdadeiro se esc é apertado e fecha a janela*/) {

        // Configura o Canva
        BeginDrawing();
        // Limpa o canva para não haver erros
        ClearBackground(RAYWHITE);

        // ...
        // Lógica do jogo é inserida aqui
        // ...

        // Fecha o canva
        EndDrawing();
    }
    CloseWindow();
    return 0;
}