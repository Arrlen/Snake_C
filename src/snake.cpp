#include "snake.h"
#include "screen.h"

CSnake::CSnake(CRect r, char _c /*=' '*/):
  CFramedWindow(r, _c)
{
   

}
void CSnake::paint(){
    CFramedWindow::paint();
    gotoyx(geom.topleft.y-1,geom.topleft.x);
    printl(" Level: %d ",1);
    gotoyx(geom.topleft.y+4,geom.topleft.x+4);
    printl("h - toggle help");
    gotoyx(geom.topleft.y+5,geom.topleft.x+4);
    printl("p - pause/play");
    gotoyx(geom.topleft.y+6,geom.topleft.x+4);
    printl("r - restart");
    gotoyx(geom.topleft.y+7,geom.topleft.x+4);
    printl("use keys to move snake");
    gotoyx(geom.topleft.y+8,geom.topleft.x+4);
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
