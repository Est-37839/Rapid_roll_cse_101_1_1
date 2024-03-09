#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
int Pagetrack = 0; // pagetrack for changing the state//0 for home page,1 for main page,2 for highscore

// int x = 300, y = 300, r = 20;
int timer1, timer2,speed=100;//speed for increasing speed of the blocks after a certain time
int counter1 = 0, counter2 = 0, score = 0, j; // counter for exit the game for the mistakes
/*
  function iDraw() is called again and again by the system.

  */
 int musicOn=1;
char scor[1020]; // for displaying score and storing score as character
int bx = 200, by = 405, r1 = 8;
// char homescreen;
int rx = 200, ry = 2, f = 1, i = 0;
int x[7] = {300, 190, 100, 400, 490, 590, 350}; // 30,100,300,200,150
int y[7] = {0, -100, -200, -300, -400, -500, -600};
int moveTimer;
int dx = 50, dy = 10;

void update()// this function for collision
{ 
  if (bx >= x[0] && bx <= x[0] + dx && (by - r1 == y[0] || (by - r1 < y[0] && by - r1 > y[0] - dy)))
  {
    by += 5;
  }
  if (bx >= x[1] && bx <= x[1] + dx && (by - r1 == y[1] || (by - r1 < y[1] && by - r1 > y[1] - dy)))
  {
    by += 5;
  }
  if (bx >= x[2] && bx <= x[2] + dx && (by - r1 == y[2] || (by - r1 < y[2] && by - r1 > y[2] - dy)))
  {
    by += 5;
  }
  if (bx >= x[3] && bx <= x[3] + dx && (by - r1 == y[3] || (by - r1 < y[3] && by - r1 > y[3] - dy)))
  {
    by += 5;
  }
  if (bx >= x[4] && bx <= x[4] + dx && (by - r1 == y[4] || (by - r1 < y[4] && by - r1 > y[4] - dy)))
  {
    by += 5;
  }
  if (bx >= x[5] && bx <= x[5] + dx && (by - r1 == y[5] || (by - r1 < y[5] && by - r1 > y[5] - dy)))
  {
    by += 5;
  }
  if (bx >= x[6] && bx <= x[6] + dx && (by - r1 == y[6] || (by - r1 < y[6] && by - r1 > y[6] - dy)))
  {

    by += 5;
  }
}

void sidecheck() // it will be implemented if the ball go out of the screen
{
  if (bx > 600 || bx < 0)
  {
    bx = 200, by = 405;
    counter1++;
  }
}
void lowercheck() // if the ball get out of lower side of the screen
{
  if (by < 0)
  {
    by = 405;
    counter2++;
  }
  if (by > 405)
  {
    bx = bx + 60;
    counter2++;
  }
}


void highscore()
{

}


void homePage()
{
  iShowBMP(0, 0, "home.bmp");//homepage background
  musicOn=1;
  // if (Pagetrack == 2)
  // {
  //   iPauseTimer(0);
  //   iPauseTimer(1);
  //   iPauseTimer(2);
  //   iPauseTimer(3);
  //   iPauseTimer(4);
  //   iPauseTimer(5);
  //   iPauseTimer(6);
  //   highscore();
  // }
  
}


void scoreupdate() // for updating score
{
  for (j = 0; j < 7; j++)
    if (bx >= x[j] && bx <= x[j] + dx && (by - r1 == y[j] || (by - r1 < y[j] && by - r1 > y[j] - dy)))
    {
      score += 1;
      break;
    }
}


void mainpage()
{
  iShowBMP(0, 0, "playscreen.bmp");//background while game is on
  
  update(); // for collison
  sidecheck();
  lowercheck();
  scoreupdate();
  if (counter1 == 3 || counter2 == 3)
    exit(0);
  for (int j = 0; j < 5; j++)
  {
    iFilledRectangle(x[j], y[j], dx, dy);
  }
  iSetColor(255,0,255);
  iFilledCircle(bx, by, r1);
  sprintf(scor, "%d", score);
  iText(500, 380, "Score:");
  iText(560, 380, scor);
}


void instruction()
{
    iShowBMP(0, 0, "playscreen.bmp");
    iSetColor(255,0,0);
    iText(35,360,"RETURN");
 //iShowBMP(29,331,"bb.bmp");
 //iShowBMP2(29,331,"bb.bmp",255);
    //iShowBMP2(29, 331, "backbutton.bmp",255);
   //iShowBMP(29,331,"back.bmp");
    //iShowBMP(29,331,"back.bmp");
    //printf("1.");
}


void iDraw()//// //place your drawing codes here //it will always called 
{
  iClear();
  if (Pagetrack == 0)
  {
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);
   
    homePage();
    //PlaySound("bgmusic2.wav",NULL,SND_ASYNC);
  }
  if (Pagetrack == 1)
  {
    iResumeTimer(0);
    iResumeTimer(1);
    iResumeTimer(2);
    iResumeTimer(3);
    iResumeTimer(4);
    iResumeTimer(5);
    iResumeTimer(6);

    mainpage();
  }
  if (Pagetrack == 2) // for checking who is the highest scorer
  {
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);
    highscore();
  }
  if(Pagetrack == 3)
  {
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);
    instruction();
  }

  // iShowBMP(0,0,"homescreen.bmp");
  iSetColor(0, 255, 0);

  // iText(300,300,%d,GLUT_BITMAP_TIMES_ROMAN_24);
  // for(i=0;i<50;i++)
  // {
  // 	iFilledRectangle(rx,ry, 60, 7);

  // }
  // iFilledRectangle(100, ry, 60, 7);
  //  iSetColor(20, 200, 0);
  //  iText(40, 40, "Welcome to the platform game");
  // iCircle(bx,by,r1);

  // if(by<-7)exit(0);
  // if(by>405)exit(0);
}
// void iText()

// void createbar()//for creating bars to keep the ball lift
// 	void idraw()
// {    iClear();
// 	iSetColor(255, 255, 255);
// 	iFilledRectangle(rx, ry, 60, 7);
// }

/*
  function iMouseMove() is called when the user presses and drags the mouse.
  (mx, my) is the position where the mouse pointer is.
  */
// int mx=bx,my=by;


void iMouseMove(int mx, int my)
{ 
  printf("x = %d, y= %d\n", mx, my);
  bx += 10;
  by += 10;
  // place your codes here
}

/*
  function iMouse() is called when the user presses/releases the mouse.
  (mx, my) is the position where the mouse pointer is.
  */


void iMouse(int button, int state, int mx, int my)
{
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    if (((mx > 188 && mx < 420 && my > 17 && my < 61)||(mx > 259 && mx < 367 && my > 136 && my < 244)) && Pagetrack==0) // 188 420 //61 17 for y
    {
      Pagetrack = 1;
    }
    if((mx>116 && mx<295 && my >82 && my <111)&& Pagetrack==0)//for highscore screen
    {
       Pagetrack = 2;
    }
     if((mx>295 && mx<494 && my >82 && my <111)&&Pagetrack==0)  // for intruction screen
    {
       Pagetrack = 3;
    }
  }
  
  // if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  // {
  //   // place your codes here
  //   bx -= 10;
  //   // by -= 10;
  // }
}

/*
  function iKeyboard() is called whenever the user hits a key in keyboard.
  key- holds the ASCII value of the key pressed.
  */


void iKeyboard(unsigned char key)
{
  if (key == 'k' || key == 'K')
  {
    bx += 22;
  }
  if (key == 's' || key == 'S')
  {
    bx -= 22;
  }
  if (key == 'q' || key == 'Q')
  {
    exit(0);
  }
  // place your codes for other keys here
}


/*
  function iSpecialKeyboard() is called whenver user hits special keys like-
  function keys, home, end, pg up, pg down, arraows etc. you have to use
  appropriate constants to detect them. A list is:
  GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
  GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
  GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
  GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
  */


void iSpecialKeyboard(unsigned char key)
{

  if (key == GLUT_KEY_END)
  {
    exit(0);
  }
  // place your codes for other keys here
}


void rundown()
{
  by -= 5;
}


void mover1()
{
  if (y[0] >= 400)
  {
    y[0] = 0;
  }
  else
  {
    y[0] += 5;
  }
}


void mover2()
{
  if (y[1] >= 400)
  {
    y[1] = 0;
  }
  else
  {
    y[1] += 5;
  }
}


void mover3()
{
  if (y[2] >= 400)
  {
    y[2] = 0;
  }
  else
  {
    y[2] += 5;
  }
}


void mover4()
{
  if (y[3] >= 400)
  {
    y[3] = 0;
  }
  else
  {
    y[3] += 5;
  }
}


void mover5()
{
  if (y[4] >= 400)
  {
    y[4] = 0;
  }
  else
  {
    y[4] += 5;
  }
}


void mover6()
{
  if (y[5] >= 400)
  {
    y[5] = 0;
  }
  else
  {
    y[5] += 5;
  }
}


void mover7()
{
  if (y[6] >= 400)
  {
    y[6] = 0;
  }
  else
  {
    y[6] += 5;
  }
}


void blockspeed()
{
  speed+=1000;
  
}
 
int main()
{ int n;
  // place your own initialization codes here.
  iSetTimer(1000,blockspeed);
  timer1 = iSetTimer(35, rundown);
  iSetTimer(speed, mover1);
  iSetTimer(speed, mover2);
  iSetTimer(speed, mover3);
  iSetTimer(speed, mover4);
  iSetTimer(speed, mover5);
  iSetTimer(speed, mover6);
  iSetTimer(speed, mover7);
  int highscorestore = score;
  //  int m,c=score;
  //   char name[100];
  //    char filename[100]="E:\\projectfolder\\highscore.txt";
  //    FILE *ptr=fopen(filename,"r");
     
  //    fscanf(ptr,"%d",&m);
  //    printf("%d",m);
  //    if(c>=m)
  //    {
  //       scanf("%s",name);
  //        FILE *ptr1=fopen(filename,"w");
  //       fprintf(ptr1,"%d",c);
  //       fprintf(ptr1,"\n");
  //       fprintf(ptr1,"%s",name);
  //       fclose(ptr1);
  //    }
  //    fclose(ptr);
  iInitialize(600, 400, "Rapid Roll");
    PlaySound("bgmusic2.wav",NULL,SND_ASYNC);
  return 0;
}
