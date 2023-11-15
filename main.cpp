#include "raylib.h"

int main(){

    // window demensios
    int windowWidth{800};
    int windowHeight{450};

    InitWindow(windowWidth,windowHeight,"Marcos' window");

    // circles coordinates
    int circleX{windowHeight / 2};
    int circleY{windowHeight / 2};
    int circleRadius{25};

    // circle edges
    int lCircleX{circleX - circleRadius};
    int rCircleX{circleX + circleRadius};
    int uCircleY{circleY - circleRadius};
    int bCircleY{circleY + circleRadius};

    // axe coordinates
    int axeX{windowWidth / 2};
    int axeY{0};
    int axeLength{50};

    // axe edges
    int lAxeX{axeX};
    int rAxeX{axeX + axeLength};
    int uAxeY{axeY};
    int bAxeY{axeY + axeLength};

    int direction{10};

    bool collisionWithAxe{false};

    SetTargetFPS(60);
    
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(WHITE);


        if(collisionWithAxe){
            DrawText("A collision happened! Game over for you!!",200,200,20,RED);
            ClearBackground(ORANGE);
        }else{
            // Game logig begins

            // Update the edges
            lCircleX = circleX - circleRadius;
            rCircleX = circleX + circleRadius;
            uCircleY = circleY - circleRadius;
            bCircleY = circleY + circleRadius;
            lAxeX = axeX;
            rAxeX = axeX + axeLength;
            uAxeY = axeY;
            bAxeY = axeY + axeLength;

            // update colision with axe
            collisionWithAxe = 
                    (bAxeY >= uCircleY) && 
                    (uAxeY <= bCircleY) && 
                    (lAxeX <= rCircleX) && 
                    (rAxeX >= lCircleX);


            DrawCircle(circleX,circleY,circleRadius,BLUE);
            DrawRectangle(axeX,axeY,axeLength,axeLength,RED);

            axeY += direction;
            if (axeY > (windowHeight - axeLength) || axeY < 0 ){
                direction = -direction;
            }

            if(IsKeyDown(KEY_D) && circleX < (windowWidth - circleRadius)){
                circleX += 10;
            }

            if(IsKeyDown(KEY_A) && circleX > (0 + circleRadius)){
                circleX -= 10;
            }

            // Game logic ends
        }
        
        EndDrawing();

    }
}