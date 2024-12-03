#include "raylib.h"

int main()
{
    // window
    const int windowWidth = 512;
    const int windowHeight = 380;

    InitWindow(windowWidth, windowHeight, "Dasher");

    // acceleration due to gravity (pixels/s)/s
    const int gravity = 1000;

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;

    Vector2 scarfyPos;
    scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    // rect dimensions
    int velocity = 0;

    bool isInAir = false;

    // pixels per second
    const int jumpVel = -600;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        const float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        // Perform ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            // rect is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            //  apply gravity
            velocity += gravity * dt;
            isInAir = true;
        }

        // jump check
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update position
        scarfyPos.y += velocity * dt;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();

    return 0;
}