#include "raylib.h"

int main()
{
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "MoonPatrol");

    Vector2 CubePlayer = { 360, 480 };
    Vector2 ObstacleRectangle = { 900, 470 };
    bool KeyPressed = false;
    int timer = 0;
    bool Negtimer = false;
    int timerObs =0;


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        


        if (KeyPressed == false)
        {
         if (IsKeyPressed(KEY_A))
            {
             KeyPressed = true;
             timer = 10;
            }
        }

        if (KeyPressed == true)
        {
            if (Negtimer == false)
            {



                if (timer >= 0)
                {
                    CubePlayer.y -= 10;
                    timer--;

                }
                if (timer == 0)
                {
                    Negtimer = true;
                    timer = 10;
                }
            }
            
            
            if (Negtimer == true)
            {
                if (timer >= 0)
                {
                    CubePlayer.y += 10;
                        timer--;
                }
                if (timer == 0)
                {
                    Negtimer = false;
                    timer = 0;
                    KeyPressed = false;
                }
            }
          
           
        }

     //   timerObs++;

       // if (timerObs == 60)
      //  {
                if (ObstacleRectangle.x > 0)
                {
                    ObstacleRectangle.x-=12;
                 }
                if (ObstacleRectangle.x <= 0)
                    {
                    ObstacleRectangle.x = 900;
                    }
           //     timerObs = 0;
      //  }
        

        BeginDrawing();

        ClearBackground(GRAY);
        DrawRectangle(CubePlayer.x, CubePlayer.y, 20, 20, BLUE);
        DrawRectangle(ObstacleRectangle.x, ObstacleRectangle.y, 20, 60, GREEN);

        DrawText("Version 0.1", 900, 700, 20, RED);
    
    
        EndDrawing();
    }
    CloseWindow();
    return 0;
}