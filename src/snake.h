#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "winsys.h"
#include "screen.h"
#include "cpoint.h"
#include <vector>
class CSnake:public CFramedWindow
{
private:
  

public:
  CSnake(CRect r, char _c = ' ');
  void paint();
};

#endif
