#include <raylib.h>
#include <rlgl.h>

int main()
{
    // Base colour background
    Color darkGreen = Color{0, 0, 0, 255};

    // Window sizes
    const int screenWidth = 800;
    const int screenHeight = 600;

    
    // Init window
    InitWindow(screenWidth, screenHeight, "Base Application");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    // Init 3D camera
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;          


    float spin =0.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(darkGreen);
            
            BeginMode3D(camera);

            // Draw 3D
            //sebi seful nostru

            EndMode3D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}