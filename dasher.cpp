#include "raylib.h"

int main()
{
    // window
    const int windowWidth = 512;
    const int windowHeight = 380;

    InitWindow(windowWidth, windowHeight, "Dasher");

    // acceleration due to gravity (pixels/frame)/frame
    const int gravity = 1;

    Texture2D scarfy = LoadTexture("textures/scarfy.png");

    // rect dimensions
    const int width = 50;
    const int height = 80;

    int posY = windowHeight - height;
    int velocity = 0;

    bool isInAir = false;

    const int jumpVel = -22;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Perform ground check
        if (posY >= windowHeight - height)
        {
            // rect is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            //  apply gravity
            velocity += gravity;
            isInAir = true;
        }

        // jump check
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update position
        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}