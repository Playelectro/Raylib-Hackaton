#include <raylib.h>
#include "src/engine/actors/headers/actor.h"
#include "src/engine/components/headers/position_component.h"

#include "src/engine/systems/headers/system_manager.h"

SystemManager* manager;

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
    
    manager = new SystemManager();

    Actor* actor = new Actor();


    while (!WindowShouldClose())
    {
        manager->Update();

        BeginDrawing();
            ClearBackground(darkGreen);
            
            BeginMode3D(camera);

            // Draw 3D

            
            EndMode3D();
        EndDrawing();
    }

    delete manager;
    delete actor;
    CloseWindow();
    return 0;
}