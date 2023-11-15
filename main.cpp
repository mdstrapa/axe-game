#include "raylib.h"

int main(){

    // window demensios
    int windowWidth{350};
    int windowHeight{200};

    InitWindow(windowWidth,windowHeight,"Marcos' window");

    // circles coordinates
    int circleX{175};
    int circleY{100};
    float circleRadius{25};

    SetTargetFPS(60);
    
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);

        // Game logig begins
        DrawCircle(circleX,circleY,circleRadius,BLUE);

        if(IsKeyDown(KEY_D) && circleX < 350){
            circleX = circleX + 10;
        }

        if(IsKeyDown(KEY_A && circleX > 0)){
            circleX = circleX - 10;
        }

        // Game logic ends
        EndDrawing();
    }
}