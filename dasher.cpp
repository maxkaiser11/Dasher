#include "raylib.h"

int main()
{
    // window
    const int windowWidth = 512;
    const int windowHeight = 380;

    InitWindow(windowWidth, windowHeight, "Dasher");

    // acceleration due to gravity (pixels/s)/s
    const int gravity = 1000;

    // Player variables
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;

    Vector2 scarfyPos;
    scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    // Nebula variables
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebRec{0.f, 0.f, nebula.width / 8, nebula.height / 8};
    Vector2 nebPos{windowWidth, windowHeight - nebRec.height};

    // nebula x velocity (p/s)
    int nebVel = -600;

    // animation frame
    int frame = 0;
    const float updateTime = 1.f / 12.f;
    float runningTime = 0;

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
            if (runningTime >= updateTime)
            {
                runningTime = 0;
                // update animation frame
                scarfyRec.x = frame * scarfyRec.width;
                frame++;
                if (frame > 5)
                {
                    frame = 0;
                }
            }
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

        // update nebula position
        nebPos.x += nebVel * dt;

        // update scarfy position
        scarfyPos.y += velocity * dt;

        runningTime += dt;

        // Draw Nebula
        DrawTextureRec(nebula, nebRec, nebPos, WHITE);

        // Draw Scarfy
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();

    return 0;
}