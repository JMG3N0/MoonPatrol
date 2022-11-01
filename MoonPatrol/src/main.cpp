#include "raylib.h"

int main()
{
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "MoonPatrol");

    float InitialPosPla[2] = {360, 480};
    float InitialPosObs[2] = {900, 470};

    Rectangle CubePlayer = { InitialPosPla[0], InitialPosPla[1], 20, 20 };
    Rectangle ObstacleRectangle = { InitialPosObs[0], InitialPosObs[1], 20, 60 };
    bool KeyPressed = false;
    int timer = 0;
    bool Negtimer = false;
    int timerObs =0;
    int seconds = 0;
    int minutes = 0;
    int counter = 0;


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if (counter < 60)
        {
            counter++;
        }
        if (counter == 60)
        {
            seconds++;
            counter = 0;
        }
        if (seconds == 60)
        {
            minutes++;
            seconds = 0;
        }


        if (KeyPressed == false)
        {
         if (IsKeyPressed(KEY_W))
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

               if (ObstacleRectangle.x > 0)
                {
                    ObstacleRectangle.x-=12;
                }
                if (ObstacleRectangle.x <= 0)
                {
                    ObstacleRectangle.x = 900;
                }
       

                if (CheckCollisionRecs(CubePlayer, ObstacleRectangle) == true)
                {
                    CubePlayer.x = InitialPosPla[0];
                    CubePlayer.y = InitialPosPla[1];
                    ObstacleRectangle.x = InitialPosObs[0];
                    ObstacleRectangle.y = InitialPosObs[1];
                    seconds = 0;
                    minutes = 0;
                    counter = 0;
                }

                
               

        BeginDrawing();

        ClearBackground(GRAY);
        DrawRectangle(CubePlayer.x, CubePlayer.y, 20, 20, BLUE);
        DrawRectangle(ObstacleRectangle.x, ObstacleRectangle.y, 20, 60, GREEN);

        DrawText("Version 0.1", 900, 700, 20, RED);
        DrawText(TextFormat("%02i", minutes), 450,200, 20, GREEN);
        DrawText(TextFormat(":%02i", seconds), 473,200, 20, GREEN);
        
    
        EndDrawing();
    }
    CloseWindow();
    return 0;
}