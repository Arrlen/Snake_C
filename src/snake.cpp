#include "snake.h"
#include "screen.h"
#include <time.h>
#include <unistd.h>
CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
   snakebody.push_back(CPoint(15,15));
   snakebody.push_back(CPoint(15,16));
   dirx=1,diry=0;
   gamemode=1;
   points=1;
   food.x=10;
   food.y=5;
}
void CSnake::paint(){
    CFramedWindow::paint();
    gotoyx(geom.topleft.y-1,geom.topleft.x);
    printl(" Level: %d ",points);
    if(gamemode==1){
    gotoyx(geom.topleft.y+4,geom.topleft.x+4);
    printl("h - toggle help");
    gotoyx(geom.topleft.y+5,geom.topleft.x+4);
    printl("p - pause/play");
    gotoyx(geom.topleft.y+6,geom.topleft.x+4);
    printl("r - restart");
    gotoyx(geom.topleft.y+7,geom.topleft.x+4);
    printl("q - quit the Snake game");
    gotoyx(geom.topleft.y+8,geom.topleft.x+4);
    printl("use keys to move snake");
    gotoyx(geom.topleft.y+9,geom.topleft.x+4);
    printl("or window (in pause)");
    gotoyx(geom.topleft.y+12,geom.topleft.x+4);
    printl("****   *****  *****  *    *   *****");
    gotoyx(geom.topleft.y+13,geom.topleft.x+4);
    printl("*      *   *  *   *  *   *    *");
    gotoyx(geom.topleft.y+14,geom.topleft.x+4);
    printl("****   *   *  *****  ****     *****");
    gotoyx(geom.topleft.y+15,geom.topleft.x+4);
    printl("   *   *   *  *   *  *   *    *");
    gotoyx(geom.topleft.y+16,geom.topleft.x+4);
    printl("****   *   *  *   *  *    *   *****");
    }
    else if(gamemode==2){
    gotoyx(geom.topleft.y+12,geom.topleft.x+4);
    printl("*****  *****  *   *  *****  *****");
    gotoyx(geom.topleft.y+13,geom.topleft.x+4);
    printl("*   *  *   *  *   *  *      *");
    gotoyx(geom.topleft.y+14,geom.topleft.x+4);
    printl("*****  *****  *   *  *****  *****");
    gotoyx(geom.topleft.y+15,geom.topleft.x+4);
    printl("*      *   *  *   *      *  *");
    gotoyx(geom.topleft.y+16,geom.topleft.x+4);
    printl("*      *   *  *****  *****  *****");
    }
    else if(gamemode==3){
    usleep(120000-(5000*points));
    snakemovement();
    drawsnake();
    gotoyx(geom.topleft.y+food.y,geom.topleft.x+food.x);
    printc('*');
    snakesuicide();
    snakeeat();
    }
    else if(gamemode==4){
    gotoyx(geom.topleft.y+5,geom.topleft.x+4);
    printl("Your goal is to get as big as you can ");
    gotoyx(geom.topleft.y+6,geom.topleft.x+4);
    printl("X - this is your head ");
    gotoyx(geom.topleft.y+7,geom.topleft.x+4);
    printl("o - this is the rest of your body");
    gotoyx(geom.topleft.y+8,geom.topleft.x+4);
    printl("Press r to return to main menu");
    
   }
   else if(gamemode==5){
   gotoyx(geom.topleft.y+4,geom.topleft.x+4);
   printl("YOUR SCORE %d",points);
   gotoyx(geom.topleft.y+6,geom.topleft.x+4);
    printl("*****  *****  ** **  *****");
    gotoyx(geom.topleft.y+7,geom.topleft.x+4);
    printl("*      *   *  * * *  *    ");
    gotoyx(geom.topleft.y+8,geom.topleft.x+4);
    printl("*****  *****  *   *  *****");
    gotoyx(geom.topleft.y+9,geom.topleft.x+4);
    printl("*   *  *   *  *   *  *    ");
    gotoyx(geom.topleft.y+10,geom.topleft.x+4);
    printl("*****  *   *  *   *  *****");
    gotoyx(geom.topleft.y+12,geom.topleft.x+4);
    printl("***** *       *  *****  *****");
    gotoyx(geom.topleft.y+13,geom.topleft.x+4);
    printl("*   *  *     *   *      *   *");
    gotoyx(geom.topleft.y+14,geom.topleft.x+4);
    printl("*   *   *   *    *****  *****");
    gotoyx(geom.topleft.y+15,geom.topleft.x+4);
    printl("*   *    * *     *      *   *");
    gotoyx(geom.topleft.y+16,geom.topleft.x+4);
    printl("*****     *      *****  *    *");
   }
}
bool CSnake::handleEvent(int key){
    
    if(key==KEY_UP){
      if(diry!=1){
       dirx=0,diry=-1;
      }
    }
    else if(key==KEY_LEFT){
       if(dirx!=1){
       dirx=-1,diry=0;
       }
    }
    else if(key==KEY_RIGHT){
       if(dirx!=-1){
       dirx=1,diry=0;
       }
    }
    else if(key==KEY_DOWN){
       if(diry!=-1){
       dirx=0,diry=1;
       }
    }
    else if(key=='p'){
        if(gamemode==1){
         gamemode=3;
        }
        else if(gamemode==3){
         gamemode=2;
        }
        else if(gamemode==2){
         gamemode=3;
    }else
    return false;
    }
    else if(key=='h'&&gamemode==1){
            gamemode=4;
    }
    else if(key=='r'){
    snakebody.clear();
    snakebody.push_back(CPoint(15,15));
    snakebody.push_back(CPoint(15,16));
    dirx=1,diry=0;
    gamemode=1;
    points=1;

    }
    return true;
}
void CSnake::snakemovement(){
     for(int i=snakebody.size()-1;i>=1; i--){
        snakebody[i]=snakebody[i-1];
     }
     snakebody[0].x=snakebody[0].x+dirx;
     snakebody[0].y=snakebody[0].y+diry;
     snaketeleport();
     
}
void CSnake::snaketeleport(){
     if(snakebody[0].x<=0) snakebody[0].x=geom.size.x-2;
     if(snakebody[0].y<=0) snakebody[0].y=geom.size.y-2;
     if(snakebody[0].x>=geom.size.x-1) snakebody[0].x=1;
     if(snakebody[0].y>=geom.size.y-1) snakebody[0].y=1;

}
void CSnake::drawsnake(){
     gotoyx(geom.topleft.y+snakebody[0].y,geom.topleft.x+snakebody[0].x);
     printc('X');
     for(unsigned int i=1;i<snakebody.size();i++){
         gotoyx(geom.topleft.y+snakebody[i].y,geom.topleft.x+snakebody[i].x);
         printc('o');
     }
     
}
void CSnake::foodgenerator(){
     srand(time(NULL));
     food.x=rand()%geom.size.x-1;
     food.y=rand()%geom.size.y-1;
     unsigned int i=0;
     while(i<snakebody.size()){
         if(snakebody[i].x==food.x && snakebody[i].y==food.y){
             food.x=rand()%(geom.size.x-2)+1;
             food.y=rand()%(geom.size.y-2)+1;
             
         }
         i++;
     }
     
}
void CSnake::snakeeat(){
     if(snakebody[0].x==food.x && snakebody[0].y==food.y){
        points=points+1;
        snakebody.push_back(snakebody[snakebody.size()-1]);
        foodgenerator();
        
     }
}
void CSnake::snakesuicide(){
      unsigned int i=1;
      while(i<snakebody.size()){
         if(snakebody[0].x==snakebody[i].x && snakebody[0].y==snakebody[i].y){
             gamemode=5;
            
             
         }
         i++;
     }
    
}

