#include <raylib.h>
#include "system_manager.h"
#include "texture_registry.h"
#include "context_state.h"
#include "start_menu_states.h"

int main()
{

    // Base colour background
    Color darkGreen = Color{ 0, 0, 0, 255 };

    // Window sizes
<<<<<<< Updated upstream
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    

   ///const int screenWidth = 800;
  /// const int screenHeight = 600;
=======
  // const int screenWidth = GetScreenWidth();
  // const int screenHeight = GetScreenHeight();
    

   const int screenWidth = 800;
   const int screenHeight = 600;
>>>>>>> Stashed changes
    
    // Init window
    InitWindow(screenWidth, screenHeight, "SIMA");
   // SetWindowState(FLAG_FULLSCREEN_MODE);
    
    SetTargetFPS(60);

    // Init 3D camera
    

    ContextState::getInstance()->SetState(new StartMenuState());
    ContextState::getInstance()->InitState();

    while (!WindowShouldClose())
    {
  
        BeginDrawing();
        ClearBackground(darkGreen);

        SystemManager::getInstance()->Update();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}