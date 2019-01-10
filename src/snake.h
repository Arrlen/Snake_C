#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include "screen.h"
#include "cpoint.h"
#include <vector>
class CSnake:public CFramedWindow
{
private:
  vector <CPoint> snakebody;
  CPoint food;
  int dirx,diry,gamemode,points;

public:
  CSnake(CRect r, char _c = ' ');
  void paint();
  bool handleEvent(int key);
  void drawsnake();
  void snakemovement();
  void snaketeleport();
  void foodgenerator();
  void snakeeat();
  void snakesuicide();
};

#endif
