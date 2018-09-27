#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<string.h>

#define PI 3.147


void clockshape();
void Today_date();
void system_tym();
void sec_hand();
void min_hand();
void hr_hand();

int r,x,y;
float A;
 struct time t;

void main()
 {
  int gdriver=DETECT,gmode,errorcode;
  initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
  errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error  code */
    }


       while(1)
	 {
	 gettime(&t);
	 system_tym();
	 Today_date();
	 clockshape();
	 setcolor(GREEN);
	 sec_hand();
	 setcolor(RED);
	 min_hand();
	 setcolor(BLUE);
	 hr_hand();
	sleep(1);
	 cleardevice();
	  if(kbhit())
	  {
	  exit(0);
	  }

	}

 }




 void Today_date()
 {
       time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    setcolor(WHITE);
    strftime(s, sizeof(s), "%d", tm);
    settextstyle(DEFAULT_FONT,0,1);
    outtextxy(10,20,s);
    strftime(s, sizeof(s), "%b", tm);
    outtextxy(30,20,s);
    outtextxy(60,20,"2018");
    outtextxy(95,20,",");
    strftime(s, sizeof(s), "%A", tm);
    outtextxy(105,20,s);

}

void system_tym()
 { int sec,min,hr;
   sec=t.ti_sec;
   min=t.ti_min;
   hr=t.ti_hour;
   char s[20],m[20],h[20];
   itoa(sec, s, 10);
   itoa(min,m,10);
   itoa(hr,h,10);
    setcolor(YELLOW);
    settextstyle(TRIPLEX_FONT,0,1);
    outtextxy(10,50,h);
    outtextxy(40,50,":");
    outtextxy(48,50,m);
    outtextxy(75,50,":");
    outtextxy(85,50,s);

}


void sec_hand()
{

 r=80;
 x=250;y=220;
 int sec;
 sec=t.ti_sec;
 A=sec*(PI/30)-(PI/2);           /* determining the angle of the line with respect to vertical */
 line(250,220,x+r*cos(A),y+r*sin(A));

}

void min_hand()
 {

     r=80;x=250;y=220;
     int min;
    min=t.ti_min;
    A=min*(PI/30)-(PI/2);
    line(250,220,x+r*cos(A),y+r*sin(A));

}

void hr_hand()
 {
  r=50;
  int hr,min;
 x=250;y=220;
 hr=t.ti_hour;
 min=t.ti_min;

 /* determining the angle of the line with respect to vertical */
 if(hr<=12)A=(hr*(PI/6)-(PI/2))+((min/12)*(PI/30));
 if(hr>12) A=((hr-12)*(PI/6)-(PI/2))+((min/12)*(PI/30));

 line(250,220,x+r*cos(A),y+r*sin(A));
}




void clockshape()
 {

      setcolor(11);
      setfillstyle(SOLID_FILL,11);
      circle(250,220,150);
      floodfill(250,220,11);
      setcolor(LIGHTGRAY);
      setfillstyle(SOLID_FILL,LIGHTGRAY);
      circle(250,220,130);
      floodfill(250,220,LIGHTGRAY);
      setcolor(3);
      setfillstyle(SOLID_FILL,3);
      circle(250,220,10);
      floodfill(250,220,3);
      settextstyle(4,0,5);
      setcolor(1);
      outtextxy(220,100,"12");
      outtextxy(240,280,"6");
      outtextxy(340,200,"3");
      outtextxy(150,200,"9");
      setcolor(YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(300,140,5);
      floodfill(300,140,YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(335,175,5);
      floodfill(335,175,YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(335,275,5);
      floodfill(335,275,YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(300,305,5);
      floodfill(300,305,YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(185,145,5);
      floodfill(185,145,YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(160,180,5);
      floodfill(160,180,YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(170,270,5);
      floodfill(170,270,YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      circle(200,305,5);
floodfill(200,305,YELLOW);
  setcolor(YELLOW);
 circle(500,100,25);
 setfillstyle(SOLID_FILL,YELLOW);
 floodfill(500,100,YELLOW);
 setcolor(BLACK);
 setfillstyle(SOLID_FILL,BLACK);
 fillellipse(485,90,2,6);
 fillellipse(510,90,2,6);
 ellipse(500,100,205,355,20,9);
 ellipse(500,100,205,335,20,10);
 ellipse(500,100,205,335,20,11);



}
