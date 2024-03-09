#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>

int Pagetrack = 0; // pagetrack for changing the state//0 for home page,1 for main page,2 for highscore

// int x = 300, y = 300, r = 20;
int timer1, timer2;
int sound = 1;
int timer = -1;                               // for the blocks speed
int counter = -1;                             // for selecting level state
char username[60];                            // for taking the name of user
int counter1 = 0, counter2 = 0, score = 0, j; // counter for exit the game for the mistakes
                                              /*
                                                function iDraw() is called again and again by the system.
                                              
                                                */
char playername[60];
int ind = -1;
int score2;
char scor[1020]; // for displaying score and storing score as character
int bx = 200, by = 405, r1 = 8;
// char homescreen;
int rx = 200, ry = 2, f = 1, i = 0;
int x[7] = {300, 190, 100, 400, 490, 590, 350}; // 30,100,300,200,150
int y[7] = {0, -100, -200, -300, -400, -500, -600};
int moveTimer;
int dx = 50, dy = 10;
void resetgamedata();

void update() // this function for collision
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
  if (by < -15)
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

// void highscore()
// {

// }

void homePage()
{
  iShowBMP(0, 0, "home.bmp"); // homepage background
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
  iSetColor(0, 0, 0);
  // iText(450,50,"Instructed By");
  // iText(450,40,"MUSTARI SADIA Mam");
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
void resetgamedata()
{  timer=-1;
  counter1 = 0;
  counter2 = 0;
  score = 0;
  ind = -1;
  strcpy(playername, "");
  y[0]=0;
  y[1] = -100;
  y[2] = -200;
  y[3] = -300;
  y[4] = -400;
  y[5] = -500;
  y[6] = -600;
  x[0] = 300;
  x[1] = 190;
  x[2] = 100;
  x[3] = 400;
  x[4] = 490;
  x[5] = 590;
  x[6] = 350;
  bx = 200;
  by = 405;
  //timer = -1;
}

void mainpage()
{
  iShowBMP(0, 0, "playscreen.bmp"); // background while game is on
  update();                         // for collison
  sidecheck();
  lowercheck();
  scoreupdate();
  if (counter1 + counter2 > 4)
  {
    // strcpy(name2,name)
    score2 = score;
    Pagetrack = 6; // page track 6 is enter name...
    sound = 2;
  }
  for (int j = 0; j < 5; j++)
  {
    iFilledRectangle(x[j], y[j], dx, dy);
  }
  iSetColor(255, 0, 255);
  iFilledCircle(bx, by, r1);
  sprintf(scor, "%d", score);
  iText(500, 380, "Score:");
  iText(560, 380, scor);
  // Pagetrack=5;
}

// void store_score(char *file, char *name, int score){
//   FILE *score_file = fopen(file,'a');
//   fprintf(score_file,"%s,%d",name,score);
//   fclose(score_file);
// }

void instruction()
{
  iShowBMP(0, 0, "instruction.bmp");
  // iShowBMP2(0,0,"bb.bmp",0);
  // iSetColor(255,0,0);
  // iText(35,360,"RETURN");
  // iText(50,350,"1.Use k button for left shifting");
  // iShowBMP(29,331,"bb.bmp");
  // iShowBMP2(29,331,"bb.bmp",255);
  // iShowBMP2(29, 331, "backbutton.bmp",255);
  // iShowBMP(29,331,"back.bmp");
  // iShowBMP(29,331,"back.bmp");
  // printf("1.");
}

void showhighscore()
{
  iShowBMP(0, 0, "highscorepage.bmp");
  FILE *ftr;
  char name[5][60];
  int highscore[5];
  ftr = fopen("highscores.txt", "r");
  int index = 0;
  while (fscanf(ftr, "%s %d", name[index], &highscore[index]) != EOF)
  {
    index++;
    if (index == 5)
      break;
  } //
  fclose(ftr);
  for (int i = 0; i < 5; i++)
  {
    iText(180, 128 + i * 40, name[4 - i], GLUT_BITMAP_TIMES_ROMAN_24);
  }
  iSetColor(255, 255, 0);
  for (int i = 0; i < 5; i++)
  {
    char store[10]; // 5 names and 5 score
    sprintf(store, "%d", highscore[4 - i]);
    iText(380, 128 + i * 40, store, GLUT_BITMAP_TIMES_ROMAN_24);
  }
}
void scorestore()
{
  FILE *ftr;
  char name[5][60];
  int highscore[5];
  ftr = fopen("highscores.txt", "r");
  int index = 0;
  while (fscanf(ftr, "%s %d", name[index], &highscore[index]) != EOF)
  {
    index++;
  } //
  fclose(ftr);
  int comp = 0;
  for (int i = 0; i < 5; i++)
  {
    if (comp)
      break;
    if (score >= highscore[i])
    {
      comp = 1;
      for (int j = 4; j > i; j--)
      {
        strcpy(name[j], name[j - 1]);
        highscore[j] = highscore[j - 1];
      }
      highscore[i] = score;
      strcpy(name[i], username);
    }
  }
  FILE *ftr2;
  ftr2 = fopen("highscore.txt", "w");
  for (int i = 0; i < 5; i++)
  {
    fprintf(ftr2, "%s %d\n", name[i], highscore[i]);
  }
  fclose(ftr2);
  // mainpage();
}

void gameover()
{
  sprintf(scor, "%d", score2);
 // printf("score %s\n", scor);
  iSetColor(0, 0, 0);

  iShowBMP(0, 0, "gameover.bmp");
  iText(200, 300, "YOUR SCORE IS:", GLUT_BITMAP_TIMES_ROMAN_24);
  iText(400, 300, scor, GLUT_BITMAP_TIMES_ROMAN_24);
  resetgamedata();

  // place the gameover icon here
}

void levelstate()
{
  iShowBMP(0, 0, "levelpage.bmp");
  if (timer == 1 || timer == 2 || timer == 3) //
  {
    Pagetrack = 5;
  }
  // if(counter==2)//medium level
  // {
  //    timer=180;
  //    iResumeTimer(0);
  // iResumeTimer(1);
  // iResumeTimer(2);
  // iResumeTimer(3);
  // iResumeTimer(4);
  // iResumeTimer(5);
  // iResumeTimer(6);
  // mainpage();
  // }
  // if(counter==3)//difficult level
  // {
  //   timer=50;
  //   iResumeTimer(0);
  // iResumeTimer(1);
  // iResumeTimer(2);
  // iResumeTimer(3);
  // iResumeTimer(4);
  // iResumeTimer(5);
  // iResumeTimer(6);
  // mainpage();
  // }
}
// void midpage()
// {
//   iShowBMP(0,0,"midpage.bmp");
//   if(counter==1)
//   {
//     iResumeTimer(0);
//     iResumeTimer(1);
//     iResumeTimer(2);
//     iResumeTimer(3);
//     iResumeTimer(4);
//     iResumeTimer(5);
//     iResumeTimer(6);
//     mainpage();
//   }
// }
int isgameover = 0;
void iDraw() //// //place your drawing codes here //it will always called
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
  }
  if (Pagetrack == 1)
  {
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);
    //  scorestore();
    // mainpage();
    levelstate();
    // midpage();
    // mainpage();//game page
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
    // highscore();
    showhighscore();
  }
  if (Pagetrack == 3)
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
  if (Pagetrack == 4)
  {
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);

    gameover();
  }
  if (Pagetrack == 5)
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
  if (Pagetrack == 6)
  {
    iShowBMP(0, 0, "entername.bmp");
    iSetColor(0, 0, 0);
    iText(180, 194, playername, GLUT_BITMAP_TIMES_ROMAN_24);
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
    if (((mx > 188 && mx < 420 && my > 17 && my < 61)) && Pagetrack == 0) // 188 420 //61 17 for y//||(mx > 259 && mx < 367 && my > 136 && my < 244)
    {
      Pagetrack = 1;
    }
    if ((mx > 116 && mx < 295 && my > 82 && my < 111) && Pagetrack == 0) // for highscore screen
    {
      Pagetrack = 2;
    }
    if ((mx > 295 && mx < 494 && my > 82 && my < 111) && Pagetrack == 0) // for instruction screen
    {
      Pagetrack = 3;
    }
    if ((mx > 124 && mx < 486 && my > 37 && my < 83) && Pagetrack == 4) // for gameover screen to restart
    {
       timer=-1;
      Pagetrack = 1;
     
    }
    if ((mx > 37 && mx < 95 && my > 342 && my < 374) && Pagetrack == 3) // backing from instruction screen to home screen
    {
      Pagetrack = 0;
    }
    if ((mx > 39 && mx < 95 && my > 336 && my < 376) && Pagetrack == 2) // backing from highscore screen to home screen
    {
      Pagetrack = 0;
    }
    if ((mx > 135 && mx < 455 && my > 15 && my < 50) && Pagetrack == 4) // for gameover screen to main menue
    {
      resetgamedata();
      Pagetrack = 0;
    }
    // if((mx>187 && mx<424 && my >286 && my <293)&&Pagetrack==4)  // Retying after game over
    // {
    //    Pagetrack = 1;
    // }
    // if((mx>132 && mx<472 && my >6 && my <293)&&Pagetrack==4)  // back to home screen after game over
    // {
    //    Pagetrack = 0;
    // }
     if((mx>39 && mx<95 && my >336 && my <376)&&Pagetrack==1)  // backing from level page to home screen
    {
       Pagetrack = 0;
    }
    // if((mx>147 && mx<259 && my >196 && my <253)&&Pagetrack==1)  // yes for mainpage
    // {
    //    counter=1;
    // }
    //  if((mx>322 && mx<447 && my >144 && my <208)&&Pagetrack==1)  // No  for back to homescreen
    // {
    //    Pagetrack=0;
    // }
    if ((mx > 180 && mx < 307 && my > 248 && my < 321) && Pagetrack == 1) // for easy state
    {
      timer = 1;
    }
    if ((mx > 277 && mx < 431 && my > 171 && my < 256) && Pagetrack == 1) // for medium state
    {
      timer = 2;
    }
    if ((mx > 180 && mx < 312 && my > 93 && my < 170) && Pagetrack == 1) // for difficult state
    {
      timer = 3;
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
void modifyscoreboard()
{
//  printf("Modify scoreboard is called\n");
  FILE *fptr;
  char names[100][50];
  int HighScores[100];
  fptr = fopen("highscores.txt", "r");
  int i = 0;
  while (fscanf(fptr, "%s %d", names[i], &HighScores[i]) != EOF)
  {
    i++;
    if (i >= 100)
      break;
  } // now we have extracted score data from highscore file
  fclose(fptr);

  // new playername ar score ke add korbo
  int j;
  for (j = i - 1; j >= 0; j--)
  {
    if (score2 > HighScores[j])
    {
      strcpy(names[j + 1], names[j]);
      HighScores[j + 1] = HighScores[j];
    }
    else
    {
      break;
    }
  }
  strcpy(names[j + 1], playername);
  HighScores[j + 1] = score2;

  // now we have our sorted arrays with the new score added
  // modified scoreboard ekhon txt file e push korbo
  fptr = fopen("highscores.txt", "w");
  for (int k = 0; k < i + 1 && k < 100; ++k)
  {
    fprintf(fptr, "%s %d\n", names[k], HighScores[k]);
  }
  fclose(fptr);
 // printf("NOw score is \n");
 for (int i = 0; i < 5; i++)
  {
    printf("%s %d\n", names[i], HighScores[i]);
  } 
}

void iKeyboard(unsigned char key)
{
  if (key == 'k' || key == 'K' && (Pagetrack == 5))
  {
    if (timer == 1)
    {
      bx += 22;
    }
    if (timer == 2)
    {
      bx += 17;
    }
    if (timer == 3)
    {
      bx += 14;
    }
  }
  if (key == 's' || key == 'S' && (Pagetrack == 5))
  {
    if (timer == 1)
    {
      bx -= 22;
    }
    if (timer == 2)
    {
      bx -= 17;
    }
    if (timer == 3)
    {
      bx -= 14;
    }
  }
  // taking name from user and storing it in playername array
  if (Pagetrack == 6)
  {
    if (ind != -1 && key == '\b')
    {
      ind--;
      playername[ind + 1] = '\0';
    }
    else if (ind != -1 && key == '\r') // enter pressed
    {
      modifyscoreboard();
      Pagetrack = 4;
    }
    else if (key != '\r')
    {
      playername[ind + 1] = key;
      playername[ind + 2] = '\0';
      ind++;
    }
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

  if(key==GLUT_KEY_RIGHT && Pagetrack == 5){
    if (timer == 1)
    {
      bx += 22;
    }
    if (timer == 2)
    {
      bx += 17;
    }
    if (timer == 3)
    {
      bx += 14;
    }
  }
  if(key==GLUT_KEY_LEFT && Pagetrack == 5){
    if (timer == 1)
    {
      bx -= 22;
    }
    if (timer == 2)
    {
      bx -= 17;
    }
    if (timer == 3)
    {
      bx -= 14;
    }
    
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

int main()
{

  if (Pagetrack != 4)
  {
    PlaySound("startingMusic.wav", NULL, SND_ASYNC | SND_LOOP);
  }

  // place your own initialization codes here.
  timer1 = iSetTimer(35, rundown);
  iSetTimer(100, mover1);
  iSetTimer(100, mover2);
  iSetTimer(100, mover3);
  iSetTimer(100, mover4);
  iSetTimer(100, mover5);
  iSetTimer(100, mover6);
  iSetTimer(100, mover7);
  int highscorestore = score;
  iInitialize(600, 400, "Rapid Roll");
  return 0;
}
