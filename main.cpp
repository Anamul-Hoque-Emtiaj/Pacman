/*
                Assalamo alaikum
                CSE-102 Term Project
            Name: Anamul Hoque Emtiaj
            S.ID:1905113

*/
# include "iGraphics.h"
#include<math.h>
#include<string.h>

double x=100,y=150,Ball_X,Ball_Y,Binky_X,Binky_Y,Pinky_X,Pinky_Y,Inky_X,Inky_Y,Clyde_X,Clyde_Y;
double btx,bty,itx,ity,ptx,pty,ctx,cty,ghost_speed,Pacman_Speed;
int i,j,Ball_Direction,point,t,f;
int Pinky_Direction,Inky_Direction,Clyde_Direction,Binky_Direction;
int bi,pi,in,cy,btf,btd,btt,itf,itd,itt,ptf,ptd,ptt,ctf,ctd,ctt;
int Pinky_Mood,Binky_Mood,Inky_Mood,Clyde_Mood,Power_Mood,Time,life,p300,p750,p1500,p2000;
int Binky_Power_Mood,Inky_Power_Mood,Pinky_Power_Mood,Clyde_Power_Mood,ghost_count,c;
int pa_in,pi_in,bi_in,in_in,cl_in,fruit,Dead;
int ghost_eat_point_X,ghost_eat_point_Y,ghost_eat_point,flug,fflug,ffcount,fcount,T,Dc;
FILE *file;
char pt[10],Player_Name[30],High_score[10];
int len=0;

bool intro=true,menu=false,play=false,gameover=false,Continue=false,highscore=false;
bool instruction1=false,instruction2=false,setting=false,Exit=false,sound=true,pause=false;
bool intro_left=true,intro_right=false,intro_final=false;
int intro_left_x=485,intro_left_y=390,intro_right_x=0,intro_right_y=390;
int In=0,m_move=0,high_score,save_game;
/*
Direction 1=left,2=up,3=right,4=down
x,y-maze left buttom orner co-ordinate
Ball_X,Ball_Y- Pacman position Co-ordinate,Ball_Direction-pacman direction
t-temporary variable for pacman
f-store special key comand for pacman Direction
bi-temporary variable for Blinky///pi,in,cy
btf-blinky eye flug(is active or not),btx,bty-blinky eye position,btd-blinky eye direction,btt=temporary variable for BE
Power_Mood=is power pellet eatten or not
Binky_Mood-is Blinky active or its eye
Binky_Power_Mood-when power_mood & Binky_Mood active(not eatten by pacman at power mood)
Time-store Power Mood time
p300,p750,p1500,p2000-temporary variable for fixing position at the time of ghost speed change
ghost_count-how many ghost eatten at every power mood(when power pellet eatten)
c-how many pac-dot eatten
pa_in-pacman img index for bmp rendering///pi_in,bi_in,in_in,cl_in
fruit- is fruit eatten or not
Dead-is pacman dead or not
Dc-dead count(index) for dead bmp rendering
ghost_eat_point_X,Y-position of showing point bmp when ghost eatten
ghost_eat_point-how many point found(200 or 400 or 800 or 1600)
flug-will show ghost_eat point bmp or not
fcount-time of showing ghost_eat_point
fflug-will show fruit_eat point bmp or not
ffcount-time of showing fruit_eat_point
T-time of game( become zero at every dead,level up & new game)
pt-point char array
len-player name lenght
intro_left_X,Y-for intro page left animation
In-intro page index for rendering
m_move-menu page option number for draw rectangle
save_game-is any save game available or not
*/
///path of bmp image
char pacman_left[2][30]= {"img\\pa1-1.bmp","img\\pa1-2.bmp"};
char pacman_right[2][30]= {"img\\pa3-1.bmp","img\\pa3-2.bmp"};
char pacman_up[2][30]= {"img\\pa2-1.bmp","img\\pa2-2.bmp"};
char pacman_down[2][30]= {"img\\pa4-1.bmp","img\\pa4-2.bmp"};

char binky_left[2][30]= {"img\\r1-1.bmp","img\\r1-2.bmp"};
char binky_right[2][30]= {"img\\r3-1.bmp","img\\r3-2.bmp"};
char binky_up[2][30]= {"img\\r2-1.bmp","img\\r2-2.bmp"};
char binky_down[2][30]= {"img\\r4-1.bmp","img\\r4-2.bmp"};

char pinky_left[2][30]= {"img\\p1-1.bmp","img\\p1-2.bmp"};
char pinky_right[2][30]= {"img\\p3-1.bmp","img\\p3-2.bmp"};
char pinky_up[2][30]= {"img\\p2-1.bmp","img\\p2-2.bmp"};
char pinky_down[2][30]= {"img\\p4-1.bmp","img\\p4-2.bmp"};

char inky_left[2][30]= {"img\\g1-1.bmp","img\\g1-2.bmp"};
char inky_right[2][30]= {"img\\g3-1.bmp","img\\g3-2.bmp"};
char inky_up[2][30]= {"img\\g2-1.bmp","img\\g2-2.bmp"};
char inky_down[2][30]= {"img\\g4-1.bmp","img\\g4-2.bmp"};

char clyde_left[2][30]= {"img\\o1-1.bmp","img\\o1-2.bmp"};
char clyde_right[2][30]= {"img\\o3-1.bmp","img\\o3-2.bmp"};
char clyde_up[2][30]= {"img\\o2-1.bmp","img\\o2-2.bmp"};
char clyde_down[2][30]= {"img\\o4-1.bmp","img\\o4-2.bmp"};

char frogen_initial[2][30]= {"img\\pm1-1.bmp","img\\pm1-2.bmp"};
char frogen_final[2][30]= {"img\\pm1-1.bmp","img\\pm2-2.bmp"};

char eye[4][30]= {"img\\e1.bmp","img\\e2.bmp","img\\e3.bmp","img\\e4.bmp"};
char dead[9][30]= {"img\\pd1.bmp","img\\pd2.bmp","img\\pd3.bmp","img\\pd4.bmp","img\\pd5.bmp","img\\pd6.bmp","img\\pd7.bmp","img\\pd8.bmp","img\\pd9.bmp"};

char Intro_left[2][30]= {"img\\intro_left-1.bmp","img\\intro_left-2.bmp"};
char Intro_right[2][30]= {"img\\intro_right-1.bmp","img\\intro_right-2.bmp"};

///function prototype
void PacmanControll();
void BinkyDecision(); ///Blinky
void BinkyControll();
void InkyDecision();
void InkyControll();
void PinkyDecision();
void PinkyControll();
void ClydeDecision();
void ClydeControll();
void BEDecision(); ///BE=Blinky Eye
void BEControll();
void IEDecision();
void IEControll();
void PEDecision();
void PEControll();
void CEDecision();
void CEControll();
void Position();
void Controll();
void Count();

int Point[21][19];
int maze[21][19]
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0},
    {0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0},
    {0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0},
    {0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0},
    {0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0},
    {0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0},
    {-1,-1,-1,0,1,0,1,1,1,1,1,1,1,0,1,0,-1,-1,-1},
    {0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0},
    {1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1},
    {0,0,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0},
    {-1,-1,-1,0,1,0,1,1,1,1,1,1,1,0,1,0,-1,-1,-1},
    {0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0},
    {0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0},
    {0,1,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,1,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0},
    {0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

void bgmusic()
{
    PlaySound("music\\bgmusic.wav", NULL, SND_LOOP | SND_ASYNC);
}

void death_sound()
{
    PlaySound("music\\pacman_death.wav", NULL, SND_ASYNC);
}

void eatghost_sound()
{
    PlaySound("music\\pacman_eatghost.wav", NULL, SND_ASYNC);
}

///initialize fixed value after death,level up & starting
void starting()
{
    Ball_X=9*15,Ball_Y=15*5,Binky_X=9*15,Binky_Y=13*15,Pinky_X=8*15,Pinky_Y=11*15,Inky_X=9*15,Inky_Y=11*15,Clyde_X=10*15,Clyde_Y=11*15;
    Ball_Direction=1,Pinky_Direction=3,Inky_Direction=2,Clyde_Direction=1,Binky_Direction=1;
    Pinky_Mood=1,Binky_Mood=1,Inky_Mood=1,Clyde_Mood=1,Power_Mood=0,Dead=0,Dc=0,btf=0,ctf=0,ptf=0,itf=0;
    Binky_Power_Mood=0,Inky_Power_Mood=0,Pinky_Power_Mood=0,Clyde_Power_Mood=0,T=0,fruit=0;
    pa_in=0,pi_in=0,bi_in=0,in_in=0,cl_in=0,flug=0,fflug=0,ffcount=0,fcount=0,ghost_count=0;
    if(sound)
        PlaySound("music\\pacman_beginning.wav", NULL, SND_ASYNC);
}

///for start new game
void filled_new_game()
{
    file=fopen("point.txt","r");
    for(i=0; i<21; i++)
    {
        for(j=0; j<19; j++)
        {
            fscanf(file,"%d",&Point[i][j]);
        }
    }
    fclose(file);
    point=0,life=3,p300=0,p750=0,p1500=0,p2000=0,c=0;
    for(i=0; i<len; i++)
        Player_Name[i]='\0';
    for(i=0; i<10; i++)
        pt[i]='\0';
    len=0,save_game=0;
}

///saved game to continue later
void savedGame()
{
    file=fopen("load_game.txt","w");
    fprintf(file,"1 ");
    fprintf(file,"%d %d ",point,life);
    fprintf(file,"%d %d %d %d ",p300,p750,p1500,p2000);
    fprintf(file,"%d %d ",Dead,Dc);
    fprintf(file,"%d %d %d ",fruit,fflug,ffcount);
    fprintf(file,"%lf %lf ",ghost_speed,Pacman_Speed);
    fprintf(file,"%lf %lf %d ",Ball_X,Ball_Y,Ball_Direction);
    fprintf(file,"%lf %lf %d ",Binky_X,Binky_Y,Binky_Direction);
    fprintf(file,"%lf %lf %d ",Inky_X,Inky_Y,Inky_Direction);
    fprintf(file,"%lf %lf %d ",Pinky_X,Pinky_Y,Pinky_Direction);
    fprintf(file,"%lf %lf %d ",Clyde_X,Clyde_Y,Clyde_Direction);
    fprintf(file,"%d ",Power_Mood);
    fprintf(file,"%d %d %d ",Binky_Mood,Binky_Power_Mood,btf);
    fprintf(file,"%d %d %d ",Inky_Mood,Inky_Power_Mood,itf);
    fprintf(file,"%d %d %d ",Pinky_Mood,Pinky_Power_Mood,ptf);
    fprintf(file,"%d %d %d ",Clyde_Mood,Clyde_Power_Mood,ctf);
    if(Power_Mood==1)
    {
        fprintf(file,"%d %d ",Time,ghost_count);
        fprintf(file,"%d %d ",flug,fcount);
        if(btf==1)
        {
            fprintf(file,"%lf %lf %d ",btx,bty,btd);
        }
        if(itf==1)
        {
            fprintf(file,"%lf %lf %d ",itx,ity,itd);
        }
        if(ptf==1)
        {
            fprintf(file,"%lf %lf %d ",ptx,pty,ptd);
        }
        if(ctf==1)
        {
            fprintf(file,"%lf %lf %d ",ctx,cty,ctd);
        }
    }
    fclose(file);
    file=fopen("load_point.txt","w");
    fprintf(file,"%d ",c);
    for(i=0; i<21; i++)
    {
        for(j=0; j<19; j++)
        {
            fprintf(file,"%d ",Point[i][j]);
        }
    }
    fclose(file);
}

///load save game
void loadGame()
{
    file=fopen("load_game.txt","r");
    fscanf(file,"%d",&save_game);
    fscanf(file,"%d %d ",&point,&life);
    fscanf(file,"%d %d %d %d ",&p300,&p750,&p1500,&p2000);
    fscanf(file,"%d %d ",&Dead,&Dc);
    fscanf(file,"%d %d %d ",&fruit,&fflug,&ffcount);
    fscanf(file,"%lf %lf ",&ghost_speed,&Pacman_Speed);
    fscanf(file,"%lf %lf %d ",&Ball_X,&Ball_Y,&Ball_Direction);
    fscanf(file,"%lf %lf %d ",&Binky_X,&Binky_Y,&Binky_Direction);
    fscanf(file,"%lf %lf %d ",&Inky_X,&Inky_Y,&Inky_Direction);
    fscanf(file,"%lf %lf %d ",&Pinky_X,&Pinky_Y,&Pinky_Direction);
    fscanf(file,"%lf %lf %d ",&Clyde_X,&Clyde_Y,&Clyde_Direction);
    fscanf(file,"%d ",&Power_Mood);
    fscanf(file,"%d %d %d ",&Binky_Mood,&Binky_Power_Mood,&btf);
    fscanf(file,"%d %d %d ",&Inky_Mood,&Inky_Power_Mood,&itf);
    fscanf(file,"%d %d %d ",&Pinky_Mood,&Pinky_Power_Mood,&ptf);
    fscanf(file,"%d %d %d ",&Clyde_Mood,&Clyde_Power_Mood,&ctf);
    if(Power_Mood==1)
    {
        fscanf(file,"%d %d ",&Time,&ghost_count);
        fscanf(file,"%d %d ",&flug,&fcount);
        if(btf==1)
        {
            fscanf(file,"%lf %lf %d ",&btx,&bty,&btd);
        }
        if(itf==1)
        {
            fscanf(file,"%lf %lf %d ",&itx,&ity,&itd);
        }
        if(ptf==1)
        {
            fscanf(file,"%lf %lf %d ",&ptx,&pty,&ptd);
        }
        if(ctf==1)
        {
            fscanf(file,"%lf %lf %d ",&ctx,&cty,&ctd);
        }
    }
    fclose(file);
    file=fopen("load_point.txt","r");
    fscanf(file,"%d ",&c);
    for(i=0; i<21; i++)
    {
        for(j=0; j<19; j++)
        {
            fscanf(file,"%d ",&Point[i][j]);
        }
    }
    fclose(file);
    if(Power_Mood==0)
    {
        Time=0,flug=0,ghost_count=0,fcount=0;
    }
    for(i=0; i<len; i++)
        Player_Name[i]='\0';
    for(i=0; i<10; i++)
        pt[i]='\0';
    len=0,save_game=0;
    if(sound)
        PlaySound("music\\pacman_beginning.wav", NULL, SND_ASYNC);
    pa_in=0,pi_in=0,bi_in=0,in_in=0,cl_in=0,T=0;
}

typedef struct
{
    char name[30];
    char score[10];
} Highscore;
Highscore h[11];

void getHighscore()
{
    file=fopen("highscore.txt","r");
    for(i=0; i<10; i++)
    {
        fgets(h[i].name,30,file);
    }
    for(i=0; i<10; i++)
    {
        fgets(h[i].score,10,file);
    }
    fclose(file);
}

void putHighscore()
{
    file=fopen("highscore.txt","w");
    for(i=0; i<10; i++)
    {
        fputs(h[i].name,file);
    }
    for(i=0; i<10; i++)
    {
        fputs(h[i].score,file);
    }
    fclose(file);
}

void Sort_Highscore()
{
    char t1[10],t2[30];
    for(i=0; i<11; i++)
    {
        for(j=i+1; j<11; j++)
        {
            if(atoi(h[i].score)<atoi(h[j].score))
            {
                strcpy(t1,h[i].score);
                strcpy(t2,h[i].name);
                strcpy(h[i].score,h[j].score);
                strcpy(h[i].name,h[j].name);
                strcpy(h[j].score,t1);
                strcpy(h[j].name,t2);
            }
        }
    }
}

int reverse_direction(int d)
{
    if(d==1)
        return 3;
    else if(d==2)
        return 4;
    else if(d==3)
        return 1;
    else if(d==4)
        return 2;
}

///reverse direction at power mood
void Reverse()
{
    Binky_Direction=reverse_direction(Binky_Direction);
    Pinky_Direction=reverse_direction(Pinky_Direction);
    Inky_Direction=reverse_direction(Inky_Direction);
    Clyde_Direction=reverse_direction(Clyde_Direction);
}

void iDraw()
{
    iClear();
    if(intro)
    {
        iShowBMP(0,0,"img\\intro.bmp");
        if(In==1)
            iShowBMP2(0,0,"img\\click.bmp",0);
        if(intro_left)
        {
            iShowBMP2(intro_left_x,intro_left_y,Intro_left[In],0);
            iSetColor(255,0,0);
            iFilledCircle(65,440,7.5);
        }
        if(intro_right)
            iShowBMP2(intro_right_x,intro_right_y,Intro_right[In],0);
        if(intro_final)
            iShowBMP2(0,390,"img\\intro_final.bmp",0);
    }
    if(menu)
    {
        iShowBMP(0,0,"img\\menu.bmp");
        iSetColor(255,0,0);
        if(m_move==1)
            iRectangle(137,435,230,66);
        else if(m_move==2)
            iRectangle(139,352,226,63);
        else if(m_move==3)
            iRectangle(139,268,226,62);
        else if(m_move==4)
            iRectangle(140,186,224,63);
        else if(m_move==5)
            iRectangle(139,103,228,61);
        else if(m_move==6)
            iRectangle(139,23,223,59);
    }
    if(play)
    {
        for(i=0; i<21; i++)
        {
            for(j=0; j<19; j++)
            {
                if(maze[i][j]==0)
                {
                    iSetColor(50,100,50);
                    iFilledRectangle(x+15*j,y+15*i,15,15);
                }
                else
                {
                    iSetColor(0,0,0);
                    iFilledRectangle(x+15*j,y+15*i,15,15);
                }
                if(Point[i][j]==1)
                {
                    iSetColor(255,255,255);
                    iFilledCircle(x+15*j+7.5,y+15*i+7.5,2);
                }
                else if(Point[i][j]==2)
                {
                    iSetColor(255,0,0);
                    iFilledCircle(x+15*j+7.5,y+15*i+7.5,3.5);
                }
            }
        }
        if(Dead==1)
            iShowBMP2(x+Ball_X,y+Ball_Y,dead[Dc],0);
        else
        {
            if(Ball_Direction==1)
                iShowBMP2(x+Ball_X,y+Ball_Y,pacman_left[pa_in],0);
            else if(Ball_Direction==2)
                iShowBMP2(x+Ball_X,y+Ball_Y,pacman_up[pa_in],0);
            else if(Ball_Direction==3)
                iShowBMP2(x+Ball_X,y+Ball_Y,pacman_right[pa_in],0);
            else
                iShowBMP2(x+Ball_X,y+Ball_Y,pacman_down[pa_in],0);
        }
        if(Pinky_Mood==1)
        {
            if(Pinky_Power_Mood==0)
            {
                if(Pinky_Direction==1)
                    iShowBMP2(x+Pinky_X,y+Pinky_Y,pinky_left[pi_in],0);
                else if(Pinky_Direction==2)
                    iShowBMP2(x+Pinky_X,y+Pinky_Y,pinky_up[pi_in],0);
                else if(Pinky_Direction==3)
                    iShowBMP2(x+Pinky_X,y+Pinky_Y,pinky_right[pi_in],0);
                else
                    iShowBMP2(x+Pinky_X,y+Pinky_Y,pinky_down[pi_in],0);
            }
            else
            {
                if(Time<10)
                    iShowBMP2(x+Pinky_X,y+Pinky_Y,frogen_initial[pi_in],0);
                else if(Time>=10&&Time<15)
                    iShowBMP2(x+Pinky_X,y+Pinky_Y,frogen_final[pi_in],0);
            }
        }
        else
        {
            iShowBMP2(x+ptx,y+pty,eye[ptd-1],0);
        }

        if(Inky_Mood==1)
        {
            if(Inky_Power_Mood==0)
            {
                if(Inky_Direction==1)
                    iShowBMP2(x+Inky_X,y+Inky_Y,inky_left[in_in],0);
                else if(Inky_Direction==2)
                    iShowBMP2(x+Inky_X,y+Inky_Y,inky_up[in_in],0);
                else if(Inky_Direction==3)
                    iShowBMP2(x+Inky_X,y+Inky_Y,inky_right[in_in],0);
                else
                    iShowBMP2(x+Inky_X,y+Inky_Y,inky_down[in_in],0);
            }
            else
            {
                if(Time<10)
                    iShowBMP2(x+Inky_X,y+Inky_Y,frogen_initial[in_in],0);
                else if(Time>=10&&Time<15)
                    iShowBMP2(x+Inky_X,y+Inky_Y,frogen_final[in_in],0);
            }
        }
        else
        {
            iShowBMP2(x+itx,y+ity,eye[itd-1],0);
        }

        if(Binky_Mood==1)
        {
            if(Binky_Power_Mood==0)
            {
                if(Binky_Direction==1)
                    iShowBMP2(x+Binky_X,y+Binky_Y,binky_left[bi_in],0);
                else if(Binky_Direction==2)
                    iShowBMP2(x+Binky_X,y+Binky_Y,binky_up[bi_in],0);
                else if(Binky_Direction==3)
                    iShowBMP2(x+Binky_X,y+Binky_Y,binky_right[bi_in],0);
                else
                    iShowBMP2(x+Binky_X,y+Binky_Y,binky_down[bi_in],0);
            }
            else
            {
                if(Time<10)
                    iShowBMP2(x+Binky_X,y+Binky_Y,frogen_initial[bi_in],0);
                else if(Time>=10&&Time<15)
                    iShowBMP2(x+Binky_X,y+Binky_Y,frogen_final[bi_in],0);
            }
        }
        else
        {
            iShowBMP2(x+btx,y+bty,eye[btd-1],0);
        }

        if(Clyde_Mood==1)
        {
            if(Clyde_Power_Mood==0)
            {
                if(Clyde_Direction==1)
                    iShowBMP2(x+Clyde_X,y+Clyde_Y,clyde_left[cl_in],0);
                else if(Clyde_Direction==2)
                    iShowBMP2(x+Clyde_X,y+Clyde_Y,clyde_up[cl_in],0);
                else if(Clyde_Direction==3)
                    iShowBMP2(x+Clyde_X,y+Clyde_Y,clyde_right[cl_in],0);
                else
                    iShowBMP2(x+Clyde_X,y+Clyde_Y,clyde_down[cl_in],0);
            }
            else
            {
                if(Time<10)
                    iShowBMP2(x+Clyde_X,y+Clyde_Y,frogen_initial[cl_in],0);
                else if(Time>=10&&Time<15)
                    iShowBMP2(x+Clyde_X,y+Clyde_Y,frogen_final[cl_in],0);
            }
        }
        else
        {
            iShowBMP2(x+ctx,y+cty,eye[ctd-1],0);
        }

        if(fruit==1)
            iShowBMP2(x+12*15,y+10*15,"img\\fruit.bmp",0);
        if(fflug==1)
            iShowBMP2(x+12*15,y+10*15,"img\\po100.bmp",0);
        if(flug==1)
        {
            if(ghost_eat_point==200)
                iShowBMP2(x+ghost_eat_point_X,y+ghost_eat_point_Y,"img\\po200.bmp",0);
            else if(ghost_eat_point==400)
                iShowBMP2(x+ghost_eat_point_X,y+ghost_eat_point_Y,"img\\po400.bmp",0);
            else if(ghost_eat_point==800)
                iShowBMP2(x+ghost_eat_point_X,y+ghost_eat_point_Y,"img\\po800.bmp",0);
            else if(ghost_eat_point==1600)
                iShowBMP2(x+ghost_eat_point_X,y+ghost_eat_point_Y,"img\\po1600.bmp",0);
        }
        if(T<4)
            iShowBMP2(x+100,y+135,"img\\ready.bmp",0);
        iSetColor(255,255,255);
        iFilledRectangle(x+9*15,y+12*15+5,15,5);
        for(i=0; i<life; i++)
            iShowBMP2(100+i*15+5,130,"img\\pa3-2.bmp",0);

        iText(100,475,"Point",GLUT_BITMAP_HELVETICA_18);
        itoa(point,pt,10);
        iText(150,475,pt,GLUT_BITMAP_HELVETICA_18);
        iText(210,475,"Highscore",GLUT_BITMAP_HELVETICA_18);
        if(high_score>point)
            iText(300,475,High_score,GLUT_BITMAP_HELVETICA_18);
        else
            iText(300,475,pt,GLUT_BITMAP_HELVETICA_18);
        if(!pause)
            iShowBMP2(340,455,"img\\resume.bmp",0);
        else
        {
            iShowBMP2(340,455,"img\\pause.bmp",0);
            iShowBMP2(67,157,"img\\paused.bmp",0);
        }
    }
    if(gameover)
    {
        iShowBMP(0,0,"img\\game_over.bmp");
        iSetColor(255,255,0);
        iText(270,263,pt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
        iText(285,200,Player_Name,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(Continue)
    {
        iShowBMP2(67,157,"img\\continue.bmp",0);
    }
    if(highscore)
    {
        getHighscore();
        iShowBMP(0,0,"img\\highscore.bmp");
        iText(25,450,"1.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,410,"2.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,370,"3.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,330,"4.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,290,"5.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,250,"6.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,210,"7.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,170,"8.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,130,"9.",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25,90,"10.",GLUT_BITMAP_TIMES_ROMAN_24);
        for(i=0; i<10; i++)
        {
            if(i==9)
                iText(55,450-i*40,h[i].name,GLUT_BITMAP_TIMES_ROMAN_24);
            else
                iText(45,450-i*40,h[i].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(365,450-i*40,h[i].score,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
    if(instruction1)
        iShowBMP(0,0,"img\\instruction1.bmp");
    if(instruction2)
        iShowBMP(0,0,"img\\instruction2.bmp");
    if(setting)
        iShowBMP(0,0,"img\\setting.bmp");
    if(Exit)
        iShowBMP2(67,157,"img\\exit.bmp",0);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(intro)
        {
            if(mx>=0&&mx<=485&&my>=0&&my<=615)
            {
                intro=false;
                menu=true;
                bgmusic();
            }
        }
        if(menu)
        {
            if(m_move!=1&&!Exit&&mx>=138&&mx<=368&&my>=435&&my<=501&&!Continue)
                m_move=1;
            else if(m_move!=2&&!Exit&&mx>=138&&mx<=368&&my>=352&&my<=415&&!Continue)
                m_move=2;
            else if(m_move!=3&&!Exit&&mx>=138&&mx<=368&&my>=268&&my<=330&&!Continue)
                m_move=3;
            else if(m_move!=4&&!Exit&&mx>=138&&mx<=368&&my>=186&&my<=250&&!Continue)
                m_move=4;
            else if(m_move!=5&&!Exit&&mx>=138&&mx<=368&&my>=103&&my<=164&&!Continue)
                m_move=5;
            else if(m_move!=6&&!Exit&&mx>=138&&mx<=368&&my>=23&&my<=82&&!Continue)
                m_move=6;
            else if(m_move==1&&mx>=138&&mx<=368&&my>=435&&my<=501)
            {
                getHighscore();
                high_score=atoi(h[0].score);
                itoa(high_score,High_score,10);
                filled_new_game();
                starting();
                play=true;
                save_game=0;
                file=fopen("load_game.txt","w");
                fprintf(file,"0");
                fclose(file);
                menu=false;
                m_move=0;
            }
            else if(m_move==2&&mx>=138&&mx<=368&&my>=352&&my<=415)
            {
                m_move=0;
                if(save_game==1)
                {
                    menu=false;
                    getHighscore();
                    high_score=atoi(h[0].score);
                    itoa(high_score,High_score,10);
                    loadGame();
                    play=true;
                    save_game=0;
                    file=fopen("load_game.txt","w");
                    fprintf(file,"0");
                    fclose(file);
                }
                else
                {
                    Continue=true;
                }
            }
            else if(m_move==3&&mx>=138&&mx<=368&&my>=268&&my<=330)
            {
                highscore=true;
                menu=false;
                m_move=0;
            }
            else if(m_move==4&&mx>=138&&mx<=368&&my>=186&&my<=250)
            {
                instruction1=true;
                menu=false;
                m_move=0;
            }
            else if(m_move==5&&mx>=138&&mx<=368&&my>=103&&my<=164)
            {
                setting=true;
                menu=false;
                m_move=0;
            }
            else if(m_move==6&&mx>=138&&mx<=368&&my>=23&&my<=82)
            {
                Exit=true;
                m_move=0;
            }
            else
                m_move=0;
        }
        if(play)
        {
            if(mx>=320&&mx<=385&&my>=465&&my<=530)
            {
                if(!pause)
                {
                    pause=true;
                    iPauseTimer(0);
                    savedGame();
                    save_game=1;
                }
            }

        }
        if(pause)
        {
            if(mx>=145&&mx<=335&&my>=290&&my<=335)
            {
                iResumeTimer(0);
                pause=false;
            }
            if(mx>=145&&mx<=335&&my>=220&&my<=265)
            {
                iResumeTimer(0);
                pause=false;
                play=false;
                menu=true;
                if(sound)
                    bgmusic();
            }
        }
        if(gameover)
        {
            if(mx>=38&&mx<=205&&my>=34&&my<=71)
            {
                gameover=false;
                if(sound)
                    bgmusic();
                menu=true;
                strcat(pt,"\n\0");
                strcat(Player_Name,"\n\0");
                strcpy(h[10].score,pt);
                strcpy(h[10].name,Player_Name);
                Sort_Highscore();
                putHighscore();
            }
            if(mx>=313&&mx<=449&&my>=34&&my<=72)
            {
                gameover=false;
                strcat(pt,"\n\0");
                strcat(Player_Name,"\n\0");
                strcpy(h[10].score,pt);
                strcpy(h[10].name,Player_Name);
                Sort_Highscore();
                putHighscore();
                getHighscore();
                high_score=atoi(h[0].score);
                itoa(high_score,High_score,10);
                filled_new_game();
                starting();
                play=true;
            }
            save_game=0;
            file=fopen("load_game.txt","w");
            fprintf(file,"0");
            fclose(file);
        }
        if(Continue)
        {
            if(mx>=102&&mx<=192&&my>=196&&my<=245)
            {
                Continue=false;
                menu=false;
                getHighscore();
                high_score=atoi(h[0].score);
                itoa(high_score,High_score,10);
                filled_new_game();
                starting();
                play=true;
            }
            if(mx>=285&&mx<=371&&my>=196&&my<=243)
                Continue=false;
        }
        if(highscore)
        {
            if(mx>=24&&mx<=114&&my>=23&&my<=56)
            {
                highscore=false;
                menu=true;
            }
        }
        if(instruction1)
        {
            if(mx>=370&&mx<=450&&my>=28&&my<=65)
            {
                instruction1=false;
                instruction2=true;
            }
        }
        if(instruction2)
        {
            if(mx>=36&&mx<=208&&my>=33&&my<=80)
            {
                instruction2=false;
                menu=true;
            }
        }
        if(setting)
        {
            if(mx>=61&&mx<=157&&my>=43&&my<=103)
            {
                setting=false;
                menu=true;
            }
            if(mx>=292&&mx<=375&&my>=356&&mx<=424&&!sound)
            {
                bgmusic();
                sound=true;
            }
            if(mx>=291&&mx<=375&&my>=258&&my<=327&&sound)
            {
                PlaySound("music\\2.wav", NULL, SND_SYNC);
                sound=false;
            }
        }
        if(Exit)
        {
            if(mx>=129&&mx<=204&&my>=225&&my<=272)
                exit(0);
            else if(mx>=274&&mx<=344&&my>=229&&my<=267)
            {
                Exit=false;
                menu=true;
            }
        }
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(gameover)
    {
        Player_Name[len++]=key;
    }
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
    if(key == GLUT_KEY_LEFT)
    {
        f=1;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        f=3;
    }
    if(key == GLUT_KEY_UP)
    {
        f=2;
    }
    if(key == GLUT_KEY_DOWN)
    {
        f=4;
    }
}

void PacmanControll()
{
    if(f==1&&Ball_X==((int)Ball_X/15)*15&&Ball_Y==((int)Ball_Y/15)*15&&maze[(int)Ball_Y/15][((int)Ball_X/15)-1]==1)
        Ball_Direction=1;
    else if(f==2&&Ball_X==((int)Ball_X/15)*15&&Ball_Y==((int)Ball_Y/15)*15&&maze[((int)Ball_Y/15)+1][(int)Ball_X/15]==1)
        Ball_Direction=2;
    else if(f==3&&Ball_X==((int)Ball_X/15)*15&&Ball_Y==((int)Ball_Y/15)*15&&maze[(int)Ball_Y/15][((int)Ball_X/15)+1]==1)
        Ball_Direction=3;
    else if(f==4&&Ball_X==((int)Ball_X/15)*15&&Ball_Y==((int)Ball_Y/15)*15&&maze[((int)Ball_Y/15)-1][(int)Ball_X/15]==1&&!(Ball_X==9*15&&Ball_Y==13*15))
        Ball_Direction=4;
    if(Ball_Direction==1&&Dead!=1)
    {
        t=ceil(Ball_X/15)-1;
        if(maze[(int)Ball_Y/15][t]==1)
        {
            if(Point[(int)Ball_Y/15][(int)Ball_X/15]==2) ///power pellet
            {
                point+=50;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                Power_Mood=1;
                Binky_Power_Mood=1,Inky_Power_Mood=1,Pinky_Power_Mood=1,Clyde_Power_Mood=1,ghost_count=0;
                if(T>=7)
                    Reverse();
                Position();
                Time=0;
                c++;
            }
            else if(Point[(int)Ball_Y/15][(int)Ball_X/15]==1) ///pac-dot
            {
                point+=10;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                c++;
            }
            Ball_X-=Pacman_Speed;
        }
        else if(Ball_Y==11*15&&Ball_X<=5)
        {
            Ball_X=18*15;
        }
    }
    else if(Ball_Direction==2&&Dead!=1)
    {
        t=floor(Ball_Y/15)+1;
        if(maze[t][(int)Ball_X/15]==1)
        {

            if(Point[(int)Ball_Y/15][(int)Ball_X/15]==2)
            {
                point+=50;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                Power_Mood=1;
                Binky_Power_Mood=1,Inky_Power_Mood=1,Pinky_Power_Mood=1,Clyde_Power_Mood=1,ghost_count=0;
                Position();
                if(T>=7)
                    Reverse();
                Time=0;
                c++;
            }
            else if(Point[(int)Ball_Y/15][(int)Ball_X/15]==1)
            {
                point+=10;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                c++;
            }
            Ball_Y+=Pacman_Speed;
        }
    }
    else if(Ball_Direction==3&&Dead!=1)
    {
        t=floor(Ball_X/15)+1;
        if(maze[(int)Ball_Y/15][t]==1)
        {
            if(Point[(int)Ball_Y/15][(int)Ball_X/15]==2)
            {
                point+=50;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                Power_Mood=1;
                Binky_Power_Mood=1,Inky_Power_Mood=1,Pinky_Power_Mood=1,Clyde_Power_Mood=1,ghost_count=0;
                Position();
                if(T>=7)
                    Reverse();
                Time=0;
                c++;
            }
            else if(Point[(int)Ball_Y/15][(int)Ball_X/15]==1)
            {
                point+=10;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                c++;
            }
            else if(Ball_Y==11*15&&Ball_X>=17*15+5)
            {
                Ball_X=0;
            }
            Ball_X+=Pacman_Speed;
        }
    }
    else if(Ball_Direction==4&&Dead!=1)
    {
        t=ceil(Ball_Y/15)-1;
        if(maze[t][(int)Ball_X/15]==1)
        {
            if(Point[(int)Ball_Y/15][(int)Ball_X/15]==2)
            {
                point+=50;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                Power_Mood=1;
                Binky_Power_Mood=1,Inky_Power_Mood=1,Pinky_Power_Mood=1,Clyde_Power_Mood=1,ghost_count=0;
                Position();
                if(T>=7)
                    Reverse();
                Time=0;
                c++;
            }
            else if(Point[(int)Ball_Y/15][(int)Ball_X/15]==1)
            {
                point+=10;
                Point[(int)Ball_Y/15][(int)Ball_X/15]=0;
                c++;
            }
            Ball_Y-=Pacman_Speed;
        }
    }
    if(fruit==1&&abs(Ball_X-12*15)<=5&&abs(Ball_Y-10*15)<=5)
    {
        if(sound)
            PlaySound("music\\pacman_eatfruit.wav", NULL, SND_ASYNC);
        point+=100;
        fruit=0;
        ffcount=0;
        fflug=1;
    }
    pa_in++;
    if(pa_in==2)
        pa_in=0;
}

///directly chase pacman
void BinkyDecision()
{
    if(Binky_X==9*15&&Binky_Y==11*15) ///at home
        Binky_Direction=2;

    else if(Binky_Power_Mood==0)///normal time
    {
        if(maze[((int)Binky_Y/15)][((int)Binky_X/15)-1]==1&&Binky_Direction!=3&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_X<=Binky_X)
            Binky_Direction=1;
        else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)+1]==1&&Binky_Direction!=1&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_X>=Binky_X)
            Binky_Direction=3;
        else if(maze[((int)Binky_Y/15)-1][((int)Binky_X/15)]==1&&Binky_Direction!=2&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_Y<=Binky_Y)
            Binky_Direction=4;
        else if(maze[((int)Binky_Y/15)+1][((int)Binky_X/15)]==1&&Binky_Direction!=4&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_Y>=Binky_Y)
            Binky_Direction=2;

        else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)-1]==1&&Binky_Direction!=3&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=1;
        else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)+1]==1&&Binky_Direction!=1&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=3;
        else if(maze[((int)Binky_Y/15)-1][((int)Binky_X/15)]==1&&Binky_Direction!=2&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=4;
        else if(maze[((int)Binky_Y/15)+1][((int)Binky_X/15)]==1&&Binky_Direction!=4&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=2;
    }
    else if(Binky_Power_Mood==1) ///when power pellet eat
    {
        if(maze[((int)Binky_Y/15)][((int)Binky_X/15)-1]==1&&Binky_Direction!=3&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_X>=Binky_X)
            Binky_Direction=1;
        else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)+1]==1&&Binky_Direction!=1&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_X<=Binky_X)
            Binky_Direction=3;
        else if(maze[((int)Binky_Y/15)-1][((int)Binky_X/15)]==1&&Binky_Direction!=2&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_Y>=Binky_Y)
            Binky_Direction=4;
        else if(maze[((int)Binky_Y/15)+1][((int)Binky_X/15)]==1&&Binky_Direction!=4&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15))&&Ball_Y<=Binky_Y)
            Binky_Direction=2;

        else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)-1]==1&&Binky_Direction!=3&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=1;
        else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)+1]==1&&Binky_Direction!=1&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=3;
        else if(maze[((int)Binky_Y/15)-1][((int)Binky_X/15)]==1&&Binky_Direction!=2&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=4;
        else if(maze[((int)Binky_Y/15)+1][((int)Binky_X/15)]==1&&Binky_Direction!=4&&(((int)Binky_X/15)==(Binky_X/15))&&(((int)Binky_Y/15)==(Binky_Y/15)))
            Binky_Direction=2;
    }
}

void BinkyControll()
{
    if((abs(Binky_X-Ball_X)<=15&&abs(Binky_Y-Ball_Y)==0)||(abs(Binky_X-Ball_X)==0&&abs(Binky_Y-Ball_Y)<=15))///pacman touch Blinky
    {
        if(Power_Mood==1&&Binky_Power_Mood==1) ///at power mood blinky eatten by pacman
        {
            btx=((int)Binky_X/15)*15;
            bty=((int)Binky_Y/15)*15;
            btf=1;
            BEDecision();
            Sleep(200);
            point+=pow(2,ghost_count)*200;
            ghost_eat_point=pow(2,ghost_count)*200;
            ghost_eat_point_X=Binky_X;
            ghost_eat_point_Y=Binky_Y;
            flug=1;
            fcount=0;
            ghost_count++;
            Binky_Power_Mood=0;
            Binky_Mood=0;
            if(sound)
                eatghost_sound();
        }
        else ///pacman dead
        {
            if(Dead==0)
            {
                if(sound)
                    death_sound();
                life--;
                Dead=1;
            }
        }
    }

    if(Binky_Direction==1&&Dead!=1)
    {
        bi=ceil(Binky_X/15)-1;
        if(Binky_Y==11*15&&Binky_X<=7.5)
        {
            Binky_X=18*15;
            Binky_Direction==1;
        }
        else if(maze[(int)Binky_Y/15][bi]==1)
        {
            Binky_X-=ghost_speed;
        }
        BinkyDecision();
    }
    else if(Binky_Direction==2&&Dead!=1)
    {
        bi=floor(Binky_Y/15)+1;
        if(maze[bi][(int)Binky_X/15]==1)
        {
            Binky_Y+=ghost_speed;
        }
        BinkyDecision();
    }
    else if(Binky_Direction==3&&Dead!=1)
    {
        bi=floor(Binky_X/15)+1;
        if(Binky_Y==11*15&&Binky_X>=18*15-7.5)
        {
            Binky_X=0;
            Binky_Direction==3;
        }
        else if(maze[(int)Binky_Y/15][bi]==1)
        {
            Binky_X+=ghost_speed;
        }
        BinkyDecision();
    }
    else if(Binky_Direction==4&&Dead!=1)
    {
        bi=ceil(Binky_Y/15)-1;
        if(maze[bi][(int)Binky_X/15]==1)
        {
            Binky_Y-=ghost_speed;
        }
        BinkyDecision();
    }
    bi_in++;
    if(bi_in==2)
        bi_in=0;
}

///chase pacman by trying to remain reverse direction
void InkyDecision()
{
    int i;
    if(Ball_Direction==1)
        i=3;
    else if(Ball_Direction==3)
        i=1;
    else if(Ball_Direction==2)
        i=4;
    else if(Ball_Direction==4)
        i=2;

    if(Inky_X==9*15&&Inky_Y==11*15)
        Inky_Direction=2;

    else if(Inky_Power_Mood==0)
    {
        if(maze[((int)Inky_Y/15)-1][((int)Inky_X/15)]==1&&Inky_Direction!=2&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_Y<=Inky_Y)
            Inky_Direction=4;
        else if(maze[((int)Inky_Y/15)+1][((int)Inky_X/15)]==1&&Inky_Direction!=4&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_Y>=Inky_Y)
            Inky_Direction=2;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)-1]==1&&Inky_Direction!=3&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_X<=Inky_X)
            Inky_Direction=1;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)+1]==1&&Inky_Direction!=1&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_X>=Inky_X)
            Inky_Direction=3;

        else if(maze[((int)Inky_Y/15)-1][((int)Inky_X/15)]==1&&Inky_Direction!=2&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&i==4)
            Inky_Direction=4;
        else if(maze[((int)Inky_Y/15)+1][((int)Inky_X/15)]==1&&Inky_Direction!=4&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&i==2)
            Inky_Direction=2;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)-1]==1&&Inky_Direction!=3&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&i==1)
            Inky_Direction=1;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)+1]==1&&Inky_Direction!=1&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&i==3)
            Inky_Direction=3;


        else if(maze[((int)Inky_Y/15)-1][((int)Inky_X/15)]==1&&Inky_Direction!=2&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=4;
        else if(maze[((int)Inky_Y/15)+1][((int)Inky_X/15)]==1&&Inky_Direction!=4&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=2;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)-1]==1&&Inky_Direction!=3&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=1;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)+1]==1&&Inky_Direction!=1&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=3;
    }
    else if(Inky_Power_Mood==1)
    {
        if(maze[((int)Inky_Y/15)-1][((int)Inky_X/15)]==1&&Inky_Direction!=2&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_Y>=Inky_Y)
            Inky_Direction=4;
        else if(maze[((int)Inky_Y/15)+1][((int)Inky_X/15)]==1&&Inky_Direction!=4&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_Y<=Inky_Y)
            Inky_Direction=2;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)-1]==1&&Inky_Direction!=3&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_X>=Inky_X)
            Inky_Direction=1;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)+1]==1&&Inky_Direction!=1&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15))&&Ball_X<=Inky_X)
            Inky_Direction=3;

        else if(maze[((int)Inky_Y/15)-1][((int)Inky_X/15)]==1&&Inky_Direction!=2&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=4;
        else if(maze[((int)Inky_Y/15)+1][((int)Inky_X/15)]==1&&Inky_Direction!=4&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=2;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)-1]==1&&Inky_Direction!=3&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=1;
        else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)+1]==1&&Inky_Direction!=1&&(((int)Inky_X/15)==(Inky_X/15))&&(((int)Inky_Y/15)==(Inky_Y/15)))
            Inky_Direction=3;
    }
}

void InkyControll()
{
    if((abs(Inky_X-Ball_X)<=15&&abs(Inky_Y-Ball_Y)==0)||(abs(Inky_X-Ball_X)==0&&abs(Inky_Y-Ball_Y)<=15))
    {
        if(Power_Mood==1&&Inky_Power_Mood==1)
        {
            itx=((int)Inky_X/15)*15;
            ity=((int)Inky_Y/15)*15;
            itf=1;
            IEDecision();
            point+=pow(2,ghost_count)*200;
            Sleep(200);
            ghost_eat_point=pow(2,ghost_count)*200;
            ghost_eat_point_X=Inky_X;
            ghost_eat_point_Y=Inky_Y;
            flug=1;
            fcount=0;
            ghost_count++;
            Inky_Power_Mood=0;
            Inky_Mood=0;
            if(sound)
                eatghost_sound();
        }
        else
        {
            if(Dead==0)
            {
                if(sound)
                    death_sound();
                life--;
                Dead=1;
            }
        }
    }
    if(Inky_Direction==1&&Dead!=1)
    {
        in=ceil(Inky_X/15)-1;
        if(Inky_Y==11*15&&Inky_X<=7.5)
        {
            Inky_X=18*15;
            Inky_Direction==1;
        }
        else if(maze[(int)Inky_Y/15][in]==1)
            Inky_X-=ghost_speed;
        InkyDecision();
    }
    else if(Inky_Direction==2&&Dead!=1)
    {
        in=floor(Inky_Y/15)+1;
        if(maze[in][(int)Inky_X/15]==1)
            Inky_Y+=ghost_speed;
        InkyDecision();
    }
    else if(Inky_Direction==3&&Dead!=1)
    {
        in=floor(Inky_X/15)+1;
        if(Inky_Y==11*15&&Inky_X>=18*15-7.5)
        {
            Inky_X=0;
            Inky_Direction==3;
        }
        else if(maze[(int)Inky_Y/15][in]==1)
            Inky_X+=ghost_speed;
        InkyDecision();
    }
    else if(Inky_Direction==4&&Dead!=1)
    {
        in=ceil(Inky_Y/15)-1;
        if(maze[in][(int)Inky_X/15]==1)
            Inky_Y-=ghost_speed;
        InkyDecision();
    }
    in_in++;
    if(in_in==2)
        in_in=0;
}

///chase pacman by tring to remain same direction
void PinkyDecision()
{
    int p;
    p=Ball_Direction;
    if(Pinky_X==9*15&&Pinky_Y==11*15)
        Pinky_Direction=2;

    else if(Pinky_Power_Mood==0)
    {
        if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)+1]==1&&Pinky_Direction!=1&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&p==3)
            Pinky_Direction=3;
        else if(maze[((int)Pinky_Y/15)-1][((int)Pinky_X/15)]==1&&Pinky_Direction!=2&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&p==4)
            Pinky_Direction=4;
        else if(maze[((int)Pinky_Y/15)+1][((int)Pinky_X/15)]==1&&Pinky_Direction!=4&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&p==2)
            Pinky_Direction=2;
        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)-1]==1&&Pinky_Direction!=3&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&p==1)
            Pinky_Direction=1;

        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)+1]==1&&Pinky_Direction!=1&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_X>=Pinky_X)
            Pinky_Direction=3;
        else if(maze[((int)Pinky_Y/15)-1][((int)Pinky_X/15)]==1&&Pinky_Direction!=2&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_Y<=Pinky_Y)
            Pinky_Direction=4;
        else if(maze[((int)Pinky_Y/15)+1][((int)Pinky_X/15)]==1&&Pinky_Direction!=4&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_Y>=Pinky_Y)
            Pinky_Direction=2;
        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)-1]==1&&Pinky_Direction!=3&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_X<=Pinky_X)
            Pinky_Direction=1;

        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)+1]==1&&Pinky_Direction!=1&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=3;
        else if(maze[((int)Pinky_Y/15)-1][((int)Pinky_X/15)]==1&&Pinky_Direction!=2&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=4;
        else if(maze[((int)Pinky_Y/15)+1][((int)Pinky_X/15)]==1&&Pinky_Direction!=4&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=2;
        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)-1]==1&&Pinky_Direction!=3&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=1;
    }
    else if(Pinky_Power_Mood==1)
    {

        if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)+1]==1&&Pinky_Direction!=1&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_X<=Pinky_X)
            Pinky_Direction=3;
        else if(maze[((int)Pinky_Y/15)-1][((int)Pinky_X/15)]==1&&Pinky_Direction!=2&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_Y>=Pinky_Y)
            Pinky_Direction=4;
        else if(maze[((int)Pinky_Y/15)+1][((int)Pinky_X/15)]==1&&Pinky_Direction!=4&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_Y<=Pinky_Y)
            Pinky_Direction=2;
        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)-1]==1&&Pinky_Direction!=3&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15))&&Ball_X>=Pinky_X)
            Pinky_Direction=1;

        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)+1]==1&&Pinky_Direction!=1&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=3;
        else if(maze[((int)Pinky_Y/15)-1][((int)Pinky_X/15)]==1&&Pinky_Direction!=2&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=4;
        else if(maze[((int)Pinky_Y/15)+1][((int)Pinky_X/15)]==1&&Pinky_Direction!=2&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=2;
        else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)-1]==1&&Pinky_Direction!=3&&(((int)Pinky_X/15)==(Pinky_X/15))&&(((int)Pinky_Y/15)==(Pinky_Y/15)))
            Pinky_Direction=1;
    }
}

void PinkyControll()
{
    if((abs(Pinky_X-Ball_X)<=15&&abs(Pinky_Y-Ball_Y)==0)||(abs(Pinky_X-Ball_X)==0&&abs(Pinky_Y-Ball_Y)<=15))
    {
        if(Power_Mood==1&&Pinky_Power_Mood==1)
        {
            ptx=((int)Pinky_X/15)*15;
            pty=((int)Pinky_Y/15)*15;
            ptf=1;
            PEDecision();
            point+=pow(2,ghost_count)*200;
            Sleep(200);
            ghost_eat_point=pow(2,ghost_count)*200;
            ghost_eat_point_X=Pinky_X;
            ghost_eat_point_Y=Pinky_Y;
            flug=1;
            fcount=0;
            ghost_count++;
            Pinky_Power_Mood=0;
            Pinky_Mood=0;
            if(sound)
                eatghost_sound();
        }
        else
        {
            if(Dead==0)
            {
                if(sound)
                    death_sound();
                life--;
                Dead=1;
            }
        }
    }
    if(Pinky_Direction==1&&Dead!=1)
    {
        pi=ceil(Pinky_X/15)-1;
        if(Pinky_Y==11*15&&Pinky_X<=7.5)
        {
            Pinky_X=18*15;
            Pinky_Direction==1;
        }
        else if(maze[(int)Pinky_Y/15][pi]==1)
            Pinky_X-=ghost_speed;
        PinkyDecision();
    }
    else if(Pinky_Direction==2&&Dead!=1)
    {
        pi=floor(Pinky_Y/15)+1;
        if(maze[pi][(int)Pinky_X/15]==1)
            Pinky_Y+=ghost_speed;
        PinkyDecision();
    }
    else if(Pinky_Direction==3&&Dead!=1)
    {
        pi=floor(Pinky_X/15)+1;
        if(Pinky_Y==11*15&&Pinky_X>=18*15-7.5)
        {
            Pinky_X=0;
            Pinky_Direction==3;
        }
        else if(maze[(int)Pinky_Y/15][pi]==1)
            Pinky_X+=ghost_speed;
        PinkyDecision();
    }
    else if(Pinky_Direction==4&&Dead!=1)
    {
        pi=ceil(Pinky_Y/15)-1;
        if(maze[pi][(int)Pinky_X/15]==1)
            Pinky_Y-=ghost_speed;
        PinkyDecision();
    }
    pi_in++;
    if(pi_in==2)
        pi_in=0;
}

///chase pacman by trying to remain right angle direction
void ClydeDecision()
{
    int c;
    if(Ball_Direction==1||Ball_Direction==3)
    {
        if(Ball_Y>Clyde_Y)
            c=2;
        else
            c=4;
    }
    else
    {
        if(Ball_X>Clyde_X)
            c=3;
        else
            c=1;
    }

    if(Clyde_X==9*15&&Clyde_Y==11*15)
        Clyde_Direction=2;

    else if(Clyde_Power_Mood==0)
    {
        if(maze[((int)Clyde_Y/15)+1][((int)Clyde_X/15)]==1&&Clyde_Direction!=4&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&c==2)
            Clyde_Direction=2;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)+1]==1&&Clyde_Direction!=1&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&c==3)
            Clyde_Direction=3;
        else if(maze[((int)Clyde_Y/15)-1][((int)Clyde_X/15)]==1&&Clyde_Direction!=2&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&c==4)
            Clyde_Direction=4;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)-1]==1&&Clyde_Direction!=3&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&c==1)
            Clyde_Direction=1;


        else if(maze[((int)Clyde_Y/15)+1][((int)Clyde_X/15)]==1&&Clyde_Direction!=4&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&Ball_Y>=Clyde_Y)
            Clyde_Direction=2;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)+1]==1&&Clyde_Direction!=1&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&Ball_X>=Clyde_X)
            Clyde_Direction=3;
        else if(maze[((int)Clyde_Y/15)-1][((int)Clyde_X/15)]==1&&Clyde_Direction!=2&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&Ball_Y<=Clyde_Y)
            Clyde_Direction=4;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)-1]==1&&Clyde_Direction!=3&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&Ball_X<=Clyde_X)
            Clyde_Direction=1;


        else if(maze[((int)Clyde_Y/15)+1][((int)Clyde_X/15)]==1&&Clyde_Direction!=4&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=2;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)+1]==1&&Clyde_Direction!=1&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=3;
        else if(maze[((int)Clyde_Y/15)-1][((int)Clyde_X/15)]==1&&Clyde_Direction!=2&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=4;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)-1]==1&&Clyde_Direction!=3&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=1;
    }
    else if(Clyde_Power_Mood==1)
    {
        if(maze[((int)Clyde_Y/15)+1][((int)Clyde_X/15)]==1&&Clyde_Direction!=4&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y*1.00/15))&&Ball_Y>=Clyde_Y)
            Clyde_Direction=2;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)+1]==1&&Clyde_Direction!=1&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&Ball_X>=Clyde_X)
            Clyde_Direction=3;
        else if(maze[((int)Clyde_Y/15)-1][((int)Clyde_X/15)]==1&&Clyde_Direction!=2&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&Ball_Y<=Clyde_Y)
            Clyde_Direction=4;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)-1]==1&&Clyde_Direction!=3&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15))&&Ball_X<=Clyde_X)
            Clyde_Direction=1;


        else if(maze[((int)Clyde_Y/15)+1][((int)Clyde_X/15)]==1&&Clyde_Direction!=4&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=2;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)+1]==1&&Clyde_Direction!=1&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=3;
        else if(maze[((int)Clyde_Y/15)-1][((int)Clyde_X/15)]==1&&Clyde_Direction!=2&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=4;
        else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)-1]==1&&Clyde_Direction!=3&&(((int)Clyde_X/15)==(Clyde_X/15))&&(((int)Clyde_Y/15)==(Clyde_Y/15)))
            Clyde_Direction=1;
    }
}

void ClydeControll()
{
    if((abs(Clyde_X-Ball_X)<=15&&abs(Clyde_Y-Ball_Y)==0)||(abs(Clyde_X-Ball_X)==0&&abs(Clyde_Y-Ball_Y)<=15))
    {
        if(Power_Mood==1&&Clyde_Power_Mood==1)
        {
            ctx=((int)Clyde_X/15)*15;
            cty=((int)Clyde_Y/15)*15;
            ctf=1;
            CEDecision();
            point+=pow(2,ghost_count)*200;
            Sleep(200);
            ghost_eat_point=pow(2,ghost_count)*200;
            ghost_eat_point_X=Clyde_X;
            ghost_eat_point_Y=Clyde_Y;
            flug=1;
            fcount=0;
            ghost_count++;
            Clyde_Power_Mood=0;
            Clyde_Mood=0;
            if(sound)
                eatghost_sound();
        }
        else
        {
            if(Dead==0)
            {
                if(sound)
                    death_sound();
                life--;
                Dead=1;
            }
        }
    }
    if(Clyde_Direction==1&&Dead!=1)
    {
        cy=ceil(Clyde_X/15)-1;
        if(Clyde_Y==11*15&&Clyde_X<=7.5)
        {
            Clyde_X=18*15;
            Clyde_Direction==1;
        }
        else if(maze[(int)Clyde_Y/15][cy]==1)
            Clyde_X-=ghost_speed;
        ClydeDecision();
    }
    else if(Clyde_Direction==2&&Dead!=1)
    {
        cy=floor(Clyde_Y/15)+1;
        if(maze[cy][(int)Clyde_X/15]==1)
            Clyde_Y+=ghost_speed;
        ClydeDecision();
    }
    else if(Clyde_Direction==3&&Dead!=1)
    {
        cy=floor(Clyde_X/15)+1;
        if(Clyde_Y==11*15&&Clyde_X>=18*15-7.5)
        {
            Clyde_X=0;
            Clyde_Direction==3;
        }
        else if(maze[(int)Clyde_Y/15][cy]==1)
            Clyde_X+=ghost_speed;
        ClydeDecision();
    }
    else if(Clyde_Direction==4&&Dead!=1)
    {
        cy=ceil(Clyde_Y/15)-1;
        if(maze[cy][(int)Clyde_X/15]==1)
            Clyde_Y-=ghost_speed;
        ClydeDecision();
    }
    cl_in++;
    if(cl_in==2)
        cl_in=0;
}

///Blinky eye decision at every moment
void BEDecision()
{
    if(btx==9*15&&bty==11*15)
    {
        btf=0;
        Binky_Mood=1;
        Binky_X=9*15;
        Binky_Y=11*15;
        Binky_Direction=2;
    }

    else if(maze[((int)bty/15)+1][((int)btx/15)]==1&&btd!=4&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15))&&11*15>bty)
        btd=2;
    else if(maze[((int)bty/15)-1][((int)btx/15)]==1&&btd!=2&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15))&&11*15<bty)
        btd=4;
    else if(maze[((int)bty/15)][((int)btx/15)-1]==1&&btd!=3&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15))&&9*15<btx)
        btd=1;
    else if(maze[((int)bty/15)][((int)btx/15)+1]==1&&btd!=1&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15))&&9*15>btx)
        btd=3;

    else if(maze[((int)bty/15)+1][((int)btx/15)]==1&&btd!=4&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15)))
        btd=2;
    else if(maze[((int)bty/15)-1][((int)btx/15)]==1&&btd!=2&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15)))
        btd=4;
    else if(maze[((int)bty/15)][((int)btx/15)-1]==1&&btd!=3&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15)))
        btd=1;
    else if(maze[((int)bty/15)][((int)btx/15)+1]==1&&btd!=1&&(((int)btx/15)==(btx/15))&&(((int)bty/15)==(bty/15)))
        btd=3;
}

void BEControll()
{
    if(btd==1&&Dead!=1)
    {
        btt=ceil(btx/15)-1;
        if(bty==11*15&&btx<=7.5)
        {
            btx=18*15;
            btd==1;
        }
        else if(maze[(int)bty/15][btt]==1)
        {
            btx-=7.5;
        }
        BEDecision();
    }
    else if(btd==2&&Dead!=1)
    {
        btt=floor(bty/15)+1;
        if(maze[btt][(int)btx/15]==1)
        {
            bty+=7.5;
        }
        BEDecision();
    }
    else if(btd==3&&Dead!=1)
    {
        btt=floor(btx/15)+1;
        if(bty==11*15&&btx>=18*15-7.5)
        {
            btx=0;
            btd==3;
        }
        else if(maze[(int)bty/15][btt]==1)
        {
            btx+=7.5;
        }
        BEDecision();
    }
    else if(btd==4&&Dead!=1)
    {
        btt=ceil(bty/15)-1;
        if(maze[btt][(int)btx/15]==1)
        {
            bty-=7.5;
        }
        BEDecision();
    }
}

void IEDecision()
{
    if(itx==9*15&&ity==11*15)
    {
        itf=0;
        Inky_Mood=1;
        Inky_X=9*15;
        Inky_Y=11*15;
        Inky_Direction=2;
    }

    else if(maze[((int)ity/15)+1][((int)itx/15)]==1&&itd!=4&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15))&&11*15>ity)
        itd=2;
    else if(maze[((int)ity/15)-1][((int)itx/15)]==1&&itd!=2&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15))&&11*15<ity)
        itd=4;
    else if(maze[((int)ity/15)][((int)itx/15)-1]==1&&itd!=3&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15))&&9*15<itx)
        itd=1;
    else if(maze[((int)ity/15)][((int)itx/15)+1]==1&&itd!=1&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15))&&9*15>itx)
        itd=3;

    else if(maze[((int)ity/15)+1][((int)itx/15)]==1&&itd!=4&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15)))
        itd=2;
    else if(maze[((int)ity/15)-1][((int)itx/15)]==1&&itd!=2&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15)))
        itd=4;
    else if(maze[((int)ity/15)][((int)itx/15)-1]==1&&itd!=3&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15)))
        itd=1;
    else if(maze[((int)ity/15)][((int)itx/15)+1]==1&&itd!=1&&(((int)itx/15)==(itx/15))&&(((int)ity/15)==(ity/15)))
        itd=3;
}

void IEControll()
{
    if(itd==1&&Dead!=1)
    {
        itt=ceil(itx/15)-1;
        if(ity==11*15&&itx<=7.5)
        {
            itx=18*15;
            itd==1;
        }
        else if(maze[(int)ity/15][itt]==1)
        {
            itx-=7.5;
        }
        IEDecision();
    }
    else if(itd==2&&Dead!=1)
    {
        itt=floor(ity/15)+1;
        if(maze[itt][(int)itx/15]==1)
        {
            ity+=7.5;
        }
        IEDecision();
    }
    else if(itd==3&&Dead!=1)
    {
        itt=floor(itx/15)+1;
        if(ity==11*15&&itx>=18*15-7.5)
        {
            itx=0;
            itd==3;
        }
        else if(maze[(int)ity/15][itt]==1)
        {
            itx+=7.5;
        }
        IEDecision();
    }
    else if(itd==4&&Dead!=1)
    {
        itt=ceil(ity/15)-1;
        if(maze[itt][(int)itx/15]==1)
        {
            ity-=7.5;
        }
        IEDecision();
    }
}

void PEDecision()
{
    if(ptx==9*15&&pty==11*15)
    {
        ptf=0;
        Pinky_Mood=1;
        Pinky_X=9*15;
        Pinky_Y=11*15;
        Pinky_Direction=2;
    }

    else if(maze[((int)pty/15)+1][((int)ptx/15)]==1&&ptd!=4&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15))&&11*15>pty)
        ptd=2;
    else if(maze[((int)pty/15)-1][((int)ptx/15)]==1&&ptd!=2&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15))&&11*15<pty)
        ptd=4;
    else if(maze[((int)pty/15)][((int)ptx/15)-1]==1&&ptd!=3&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15))&&9*15<ptx)
        ptd=1;
    else if(maze[((int)pty/15)][((int)ptx/15)+1]==1&&ptd!=1&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15))&&9*15>ptx)
        ptd=3;

    else if(maze[((int)pty/15)+1][((int)ptx/15)]==1&&ptd!=4&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15)))
        ptd=2;
    else if(maze[((int)pty/15)-1][((int)ptx/15)]==1&&ptd!=2&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15)))
        ptd=4;
    else if(maze[((int)pty/15)][((int)ptx/15)-1]==1&&ptd!=3&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15)))
        ptd=1;
    else if(maze[((int)pty/15)][((int)ptx/15)+1]==1&&ptd!=1&&(((int)ptx/15)==(ptx/15))&&(((int)pty/15)==(pty/15)))
        ptd=3;
}

void PEControll()
{
    if(ptd==1&&Dead!=1)
    {
        ptt=ceil(ptx/15)-1;
        if(pty==11*15&&ptx<=7.5)
        {
            ptx=18*15;
            ptd==1;
        }
        else if(maze[(int)pty/15][ptt]==1)
        {
            ptx-=7.5;
        }
        PEDecision();
    }
    else if(ptd==2&&Dead!=1)
    {
        ptt=floor(pty/15)+1;
        if(maze[ptt][(int)ptx/15]==1)
        {
            pty+=7.5;
        }
        PEDecision();
    }
    else if(ptd==3&&Dead!=1)
    {
        ptt=floor(ptx/15)+1;
        if(pty==11*15&&ptx>=18*15-7.5)
        {
            ptx=0;
            ptd==3;
        }
        else if(maze[(int)pty/15][ptt]==1)
        {
            ptx+=7.5;
        }
        PEDecision();
    }
    else if(ptd==4&&Dead!=1)
    {
        ptt=ceil(pty/15)-1;
        if(maze[ptt][(int)ptx/15]==1)
        {
            pty-=7.5;
        }
        PEDecision();
    }
}

void CEDecision()
{
    if(ctx==9*15&&cty==11*15)
    {
        ctf=0;
        Clyde_Mood=1;
        Clyde_X=9*15;
        Clyde_Y=11*15;
        Clyde_Direction=2;
    }

    else if(maze[((int)cty/15)+1][((int)ctx/15)]==1&&ctd!=4&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15))&&11*15>cty)
        ctd=2;
    else if(maze[((int)cty/15)-1][((int)ctx/15)]==1&&ctd!=2&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15))&&11*15<cty)
        ctd=4;
    else if(maze[((int)cty/15)][((int)ctx/15)-1]==1&&ctd!=3&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15))&&9*15<ctx)
        ctd=1;
    else if(maze[((int)cty/15)][((int)ctx/15)+1]==1&&ctd!=1&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15))&&9*15>ctx)
        ctd=3;

    else if(maze[((int)cty/15)+1][((int)ctx/15)]==1&&ctd!=4&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15)))
        ctd=2;
    else if(maze[((int)cty/15)-1][((int)ctx/15)]==1&&ctd!=2&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15)))
        ctd=4;
    else if(maze[((int)cty/15)][((int)ctx/15)-1]==1&&ctd!=3&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15)))
        ctd=1;
    else if(maze[((int)cty/15)][((int)ctx/15)+1]==1&&ctd!=1&&(((int)ctx/15)==(ctx/15))&&(((int)cty/15)==(cty/15)))
        ctd=3;
}

void CEControll()
{
    if(ctd==1&&Dead!=1)
    {
        ctt=ceil(ctx/15)-1;
        if(cty==11*15&&ctx<=7.5)
        {
            ctx=18*15;
            ctd==1;
        }
        else if(maze[(int)cty/15][ctt]==1)
        {
            ctx-=7.5;
        }
        CEDecision();
    }
    else if(ctd==2&&Dead!=1)
    {
        ctt=floor(cty/15)+1;
        if(maze[ctt][(int)ctx/15]==1)
        {
            cty+=7.5;
        }
        CEDecision();
    }
    else if(ctd==3&&Dead!=1)
    {
        ctt=floor(ctx/15)+1;
        if(cty==11*15&&ctx>=18*15-7.5)
        {
            ctx=0;
            ctd==3;
        }
        else if(maze[(int)cty/15][ctt]==1)
        {
            ctx+=7.5;
        }
        CEDecision();
    }
    else if(ctd==4&&Dead!=1)
    {
        ctt=ceil(cty/15)-1;
        if(maze[ctt][(int)ctx/15]==1)
        {
            cty-=7.5;
        }
        CEDecision();
    }
}

///fixed position of all ghost at the time of speed change
void Position()
{

    if(((int)Binky_Y/15)==(Binky_Y/15)&&((int)Binky_X/15)==(Binky_X/15))
    {
        Binky_Y=Binky_Y;
        Binky_X=Binky_X;
    }
    else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)]==1)
    {
        Binky_Y=(((int)Binky_Y/15))*15;
        Binky_X=((int)Binky_X/15)*15;
    }
    else if(maze[((int)Binky_Y/15)-1][((int)Binky_X/15)]==1)
    {
        Binky_Y=(((int)Binky_Y/15)-1)*15;
        Binky_X=((int)Binky_X/15)*15;
    }
    else if(maze[((int)Binky_Y/15)+1][((int)Binky_X/15)]==1)
    {
        Binky_Y=(((int)Binky_Y/15)+1)*15;
        Binky_X=((int)Binky_X/15)*15;
    }
    else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)-1]==1)
    {
        Binky_Y=(((int)Binky_Y/15))*15;
        Binky_X=(((int)Binky_X/15)-1)*15;
    }
    else if(maze[((int)Binky_Y/15)][((int)Binky_X/15)+1]==1)
    {
        Binky_Y=(((int)Binky_Y/15))*15;
        Binky_X=(((int)Binky_X/15)+1)*15;
    }

    if(((int)Inky_Y/15)==(Inky_Y/15)&&((int)Inky_X/15)==(Inky_X/15))
    {
        Inky_Y=Inky_Y;
        Inky_X=Inky_X;
    }
    else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)]==1)
    {
        Inky_Y=(((int)Inky_Y/15))*15;
        Inky_X=((int)Inky_X/15)*15;
    }
    else if(maze[((int)Inky_Y/15)-1][((int)Inky_X/15)]==1)
    {
        Inky_Y=(((int)Inky_Y/15)-1)*15;
        Inky_X=((int)Inky_X/15)*15;
    }
    else if(maze[((int)Inky_Y/15)+1][((int)Inky_X/15)]==1)
    {
        Inky_Y=(((int)Inky_Y/15)+1)*15;
        Inky_X=((int)Inky_X/15)*15;
    }
    else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)-1]==1)
    {
        Inky_Y=(((int)Inky_Y/15))*15;
        Inky_X=(((int)Inky_X/15)-1)*15;
    }
    else if(maze[((int)Inky_Y/15)][((int)Inky_X/15)+1]==1)
    {
        Inky_Y=(((int)Inky_Y/15))*15;
        Inky_X=(((int)Inky_X/15)+1)*15;
    }

    if(((int)Pinky_Y/15)==(Pinky_Y/15)&&((int)Pinky_X/15)==(Pinky_X/15))
    {
        Pinky_Y=Pinky_Y;
        Pinky_X=Pinky_X;
    }
    else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)]==1)
    {
        Pinky_Y=(((int)Pinky_Y/15))*15;
        Pinky_X=((int)Pinky_X/15)*15;
    }
    else if(maze[((int)Pinky_Y/15)-1][((int)Pinky_X/15)]==1)
    {
        Pinky_Y=(((int)Pinky_Y/15)-1)*15;
        Pinky_X=((int)Pinky_X/15)*15;
    }
    else if(maze[((int)Pinky_Y/15)+1][((int)Pinky_X/15)]==1)
    {
        Pinky_Y=(((int)Pinky_Y/15)+1)*15;
        Pinky_X=((int)Pinky_X/15)*15;
    }
    else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)-1]==1)
    {
        Pinky_Y=(((int)Pinky_Y/15))*15;
        Pinky_X=(((int)Pinky_X/15)-1)*15;
    }
    else if(maze[((int)Pinky_Y/15)][((int)Pinky_X/15)+1]==1)
    {
        Pinky_Y=(((int)Pinky_Y/15))*15;
        Pinky_X=(((int)Pinky_X/15)+1)*15;
    }

    if(((int)Clyde_Y/15)==(Clyde_Y/15)&&((int)Clyde_X/15)==(Clyde_X/15))
    {
        Clyde_Y=Clyde_Y;
        Clyde_X=Clyde_X;
    }
    else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)]==1)
    {
        Clyde_Y=(((int)Clyde_Y/15))*15;
        Clyde_X=((int)Clyde_X/15)*15;
    }
    else if(maze[((int)Clyde_Y/15)-1][((int)Clyde_X/15)]==1)
    {
        Clyde_Y=(((int)Clyde_Y/15)-1)*15;
        Clyde_X=((int)Clyde_X/15)*15;
    }
    else if(maze[((int)Clyde_Y/15)+1][((int)Clyde_X/15)]==1)
    {
        Clyde_Y=(((int)Clyde_Y/15)+1)*15;
        Clyde_X=((int)Clyde_X/15)*15;
    }
    else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)-1]==1)
    {
        Clyde_Y=(((int)Clyde_Y/15))*15;
        Clyde_X=(((int)Clyde_X/15)-1)*15;
    }
    else if(maze[((int)Clyde_Y/15)][((int)Clyde_X/15)+1]==1)
    {
        Clyde_Y=(((int)Clyde_Y/15))*15;
        Clyde_X=(((int)Clyde_X/15)+1)*15;
    }
}

void Controll()
{
    if(intro)
    {
        In++;
        if(In==2)
            In=0;
        if(intro_left)
        {
            intro_left_x-=15;
            if(intro_left_x<=60)
            {
                Sleep(200);
                intro_right=true;
                intro_left=false;
            }
        }
        if(intro_right)
        {
            intro_right_x+=15;
            if(intro_right_x>485)
            {
                intro_final=true;
                intro_right=false;
            }
        }
    }
    if(play)
    {
        if(T>=4)
            PacmanControll();
        if(Power_Mood==1)
        {
            ghost_speed=2.5;
            if(Time>=15)
            {
                Position();
                Binky_Power_Mood=0,Inky_Power_Mood=0,Pinky_Power_Mood=0,Clyde_Power_Mood=0;
                Power_Mood=0;
                Controll();
            }
        }
        else if(point<750)
        {
            ghost_speed=3;
            Pacman_Speed=5;
        }
        else if(point>=750&&point<2000)
        {
            p300++;
            if(p300==1)
                Position();
            Pacman_Speed=5;
            ghost_speed=3.75;
        }
        else if(point>=2000&&point<5000)
        {
            p750++;
            if(p750==1)
            {
                Position();
                Ball_X=((int)Ball_X/15)*15;
                Ball_Y=((int)Ball_Y/15)*15;
                Pacman_Speed=7.5;
            }
            ghost_speed=5.00;
        }
        else if(point>=5000&&point<20000)
        {
            p1500++;
            if(p1500==1)
            {
                Position();
            }
            Pacman_Speed=7.5;
            ghost_speed=7.50;
        }
        else
        {
            p2000++;
            if(p2000==1)
            {
                Position();
            }
            ghost_speed=15;
            Pacman_Speed=7.5;
        }
        if(Binky_Mood==1&&T>=4)
            BinkyControll();
        if(Inky_Mood==1&&T>=4)
            InkyControll();
        if(Pinky_Mood==1&&T>=5)
            PinkyControll();
        if(Clyde_Mood==1&&T>=7)
            ClydeControll();
        if(btf==1&&T>=4)
            BEControll();
        if(itf==1&&T>=4)
            IEControll();
        if(ptf==1&&T>=4)
            PEControll();
        if(ctf==1&&T>=4)
            CEControll();
        if(c==151)
        {
            file=fopen("point.txt","r");
            for(i=0; i<21; i++)
            {
                for(j=0; j<19; j++)
                {
                    fscanf(file,"%d",&Point[i][j]);
                }
            }
            fclose(file);
            Sleep(500);
            starting();
            c=0;
        }
        if(Dead==1)
            Dc++;
        if(Dc==9)
        {
            Dead=0;
            starting();
            Controll();
        }
        if(((c==50)||(c==100))&&fruit==0)
            fruit=1;
        if(ffcount==3)
            fflug=0;
        if(fcount==3)
            flug=0;
        if(life==0)
        {
            Sleep(1000);
            play=false;
            gameover=true;
        }
    }
}

///for time count
void Count()
{
    if(play)
    {
        T++;
        if(Power_Mood==1)
            Time++;
        if(fflug==1)
            ffcount++;
        if(flug==1)
            fcount++;
    }
}

int main()
{
    PlaySound("music\\pacman_intermission.wav", NULL, SND_LOOP | SND_ASYNC);
    file=fopen("load_game.txt","r");
    fscanf(file,"%d",&save_game);
    fclose(file);
    iSetTimer(120,Controll);
    iSetTimer(1000,Count);
    iInitialize(485, 615, "Pacman");
    return 0;
}

