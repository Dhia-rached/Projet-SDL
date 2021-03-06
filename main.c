#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
int main ()
{
int cont=1,i=50,ng=0,op=1,ex=0,issettings=0,j=0;
Mix_Music *music;
Mix_Chunk *clic;
SDL_Surface *t[8];
SDL_Surface *texte=NULL;
SDL_Surface *up=NULL;
SDL_Surface *down=NULL;
SDL_Surface *screen=NULL;
SDL_Surface *image1=NULL;
SDL_Surface *jeu=NULL;
SDL_Surface *option=NULL;
SDL_Surface *play=NULL;
SDL_Surface *settings=NULL;
SDL_Surface *setting=NULL;
SDL_Surface *exit=NULL;
SDL_Surface *play1=NULL;
SDL_Surface *settings1=NULL;
SDL_Surface *exit1=NULL;
SDL_Event event;
SDL_Rect positionecranUp;
SDL_Rect positionecrandown;
SDL_Rect positionecran;
SDL_Rect positionecrant;
SDL_Rect positionecranb;
SDL_Rect positionecran3;
SDL_Rect positionecran1;
SDL_Rect positionecran2;
SDL_Rect positionClic;
TTF_Font *police=NULL;
SDL_Color couleur={0, 0, 0};
int continuer=1;
int isHome = 1;
t[0]=IMG_Load("bg.jpg");
t[1]=IMG_Load("bg1.jpg");
t[2]=IMG_Load("bg2.jpg");
t[3]=IMG_Load("bg3.jpg");
t[4]=IMG_Load("bg4.jpg");
t[5]=IMG_Load("bg5.jpg");
t[6]=IMG_Load("bg6.jpg");
if(SDL_Init(SDL_INIT_VIDEO) != 0)
{
printf("Erreur lors de l'initialisation de la SDL : %s",SDL_GetError());
return (1);
}
TTF_Init();
screen = SDL_SetVideoMode(1600,1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
if (screen == NULL)
{
printf("Erreur lors du placement du mode video : %s",SDL_GetError());
return (1); 
}
SDL_WM_SetCaption("Jeu" , NULL);

image1=IMG_Load("menu.jpg");
jeu=IMG_Load("bg.jpg");
if(jeu == NULL)
{
printf("Erreur lors du telechargement de l'image jeu : %s",SDL_GetError());
}

play=IMG_Load("play.png");
if(!play)
{
printf("Erreur lors de telechargement du bouton play: %s", SDL_GetError());
return (1);
}
settings=IMG_Load("setting.png");
if(!settings)
{
printf("Erreur lors de chargement du bouton settings : %s", SDL_GetError());
return (1);
}
exit=IMG_Load("quit.png");
if(!exit)
{
printf("Erreur lors du chargement du bouton exit : %s", SDL_GetError());
return (1);
}

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}

music=Mix_LoadMUS("mario.mp3");
Mix_PlayMusic(music, -1);

clic=Mix_LoadWAV("son1.wav");

positionecran.x=0;
positionecran.y=0;

positionecran3.x=650;
positionecran3.y=500;

positionecran1.x=650;
positionecran1.y=650;

positionecran2.x=650;
positionecran2.y=800;

up=IMG_Load("up.png");
down=IMG_Load("down.png");
positionecranUp.x=100;
positionecranUp.y=100;
positionecrandown.x=100;
positionecrandown.y=200;
police = TTF_OpenFont("Masked Hero.ttf", 55);
texte = TTF_RenderText_Blended(police, "Mars", couleur);
positionecrant.x=600;
positionecrant.y=170;



while(cont==1)
{
SDL_BlitSurface(t[j], NULL, screen, &positionecran);
j++;
SDL_BlitSurface(play, NULL, screen, &positionecran3);
SDL_BlitSurface(settings, NULL, screen, &positionecran1);
SDL_BlitSurface(exit, NULL, screen, &positionecran2);
SDL_BlitSurface(texte, NULL, screen, &positionecrant);

if(j>7)
j=1;

SDL_Flip(screen);

SDL_PollEvent(&event);

if(event.type==SDL_QUIT){
cont=0;
break;}

switch(event.type)
{
case SDL_MOUSEMOTION:
if(event.motion.x>=650 && event.motion.x<=795 && event.motion.y>=(550-74) && event.motion.y<=550 )
{
play= IMG_Load("play1.png");
SDL_BlitSurface(play1, NULL, screen, &positionecran3);
SDL_Flip(screen);
}
      				 else
{
play=IMG_Load("play.png");
SDL_BlitSurface(play, NULL, screen, &positionecran3);
SDL_Flip(screen);	
}



if(event.motion.x>=650 && event.motion.x<=(650+174) && event.motion.y>=650 && event.motion.y<=(650+74))
{

settings= IMG_Load("setting1.png");
SDL_BlitSurface(settings, NULL, screen, &positionecran1);
SDL_Flip(screen);
}
      				 else
{
settings= IMG_Load("setting.png");
SDL_BlitSurface(settings, NULL, screen, &positionecran1);
SDL_Flip(screen);	
}


if(event.motion.x>=650 && event.motion.x<=(650+174) && event.motion.y>=800 && event.motion.y<=(800+74))
{

exit= IMG_Load("exit1.png");
SDL_BlitSurface(exit, NULL, screen, &positionecran2);
SDL_Flip(screen);
}
else
{
exit= IMG_Load("quit.png");
SDL_BlitSurface(exit, NULL, screen, &positionecran2);
SDL_Flip(screen);	
}

break;




case SDL_MOUSEBUTTONUP:




    if(event.button.button==SDL_BUTTON_LEFT)
{
if(event.button.x>=650 && event.button.x<=(650+174) && event.button.y>=800 && event.button.y<=(800+74))
{
Mix_PlayChannel(-1,clic,0);
cont=0;
issettings=0;
}

if(event.button.x>=650 && event.button.x<=(650+174) && event.button.y>=650 && event.button.y<=(650+74))
{
issettings=1;
Mix_PlayChannel(-1,clic,0);
positionecranb.x=0;
positionecranb.y=0;
do
{
play=NULL;
setting=NULL;
exit=NULL;
SDL_BlitSurface(image1, NULL, screen, &positionecranb);
SDL_BlitSurface(up, NULL, screen, &positionecranUp);
SDL_BlitSurface(down, NULL, screen, &positionecrandown);
SDL_Flip(screen);
SDL_PollEvent(&event);
switch(event.key.keysym.sym)
{
case SDL_KEYUP:
case SDLK_DOWN:
                
                    if (ng==1)
                    {
ex=1;
                        ng=0;
                        op=0;

                      positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=800;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if(op==1)
                    {
ng=1;
                            op=0;
                            ex=0;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if (ex==1)
                    {
op=1;
                        ex=0;
                        ng=0;
                       issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=650;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
            break;
                   

                case SDLK_UP:
                    
                    if (ng==1)
                    {
ng=0;
                            op=1;
                            ex=0;
                       
                                                   issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=650;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                       
                    }
                    else if(op==1)
                    {
ng=0;
                        op=0;
                        ex=1;
                                            positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=800;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    else if (ex==1)
                    {
 op=0;
                        ex=0;
                        ng=1;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    
                    break;
case SDLK_a:
if(!Mix_PlayingMusic())
Mix_PlayMusic(music,-1);
else if(Mix_PausedMusic())
Mix_ResumeMusic();
else
Mix_PauseMusic();
break;
case SDLK_d :
i=i-10;
Mix_VolumeMusic(i);

break;
//Music up
case SDLK_u :
i=i+10;
Mix_VolumeMusic(i);

break;
break;
}////////////////////////////////////////////////////////


switch(event.type)
{
case SDL_MOUSEBUTTONUP:
if(event.button.button==SDL_BUTTON_LEFT)
if(event.button.x>=100 && event.button.x<=(100+161) && event.button.y>=100 && event.button.y<=(163)&&i<130)
{

i=i+10;
Mix_VolumeMusic(i);
}
if(event.button.x>=100 && event.button.x<=(100+161) && event.button.y>=200 && event.button.y<=(263)&&i>0)
{
i=i-10;
Mix_VolumeMusic(i);

if(i<0)
i=0;
}
break;
}

if(event.type==SDL_QUIT){
cont=0;
break;}
}while((event.key.keysym.sym!=SDLK_b));
break;	
}
if(event.button.x>=650 && event.button.x<=795 && event.button.y>=(550-74) && event.button.y<=550 )
{
issettings=0;
Mix_PlayChannel(-1,clic,0);
positionecranb.x=0;
positionecranb.y=0;
do
{
play=NULL;
setting=NULL;
exit=NULL;
SDL_BlitSurface(image1, NULL, screen, &positionecranb);

SDL_Flip(screen);
SDL_PollEvent(&event);
if(event.type==SDL_QUIT){
cont=0;
break;}
}while((event.key.keysym.sym!=SDLK_b));
break;	
}

}//if button
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_DOWN:
                
                    if (ng==1)
                    {
ex=1;
                        ng=0;
                        op=0;

                      positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=800;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if(op==1)
                    {
ng=1;
                            op=0;
                            ex=0;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }

                    else if (ex==1)
                    {
op=1;
                        ex=0;
                        ng=0;
                       issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=650;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
            break;
                   

                case SDLK_UP:
                    
                    if (ng==1)
                    {
ng=0;
                            op=1;
                            ex=0;
                       
                                                   issettings=1;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(settings, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=650;
SDL_BlitSurface(settings1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                       
                    }
                    else if(op==1)
                    {
ng=0;
                        op=0;
                        ex=1;
                                            positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(exit, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=800;
SDL_BlitSurface(exit1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    else if (ex==1)
                    {
 op=0;
                        ex=0;
                        ng=1;
                                          issettings=0;
isHome=0;
if(Mix_PlayChannel(-1,clic,0)==-1)
{
return (1);
}
positionecran.x=1700;
positionecran.y=1200;
SDL_BlitSurface(play, NULL, screen, &positionecran);
positionecran.x=650;
positionecran.y=500;
SDL_BlitSurface(play1, NULL, screen, &positionecran);
SDL_Flip(screen);
continue;

                    }
                    
                    break;
case SDLK_q:
cont=0;
break;
case SDLK_p:

play= IMG_Load("play1.png");
SDL_BlitSurface(play, NULL, screen, &positionecran3);
SDL_Flip(screen);

break;
case SDLK_s:
settings= IMG_Load("setting1.png");
SDL_BlitSurface(settings, NULL, screen, &positionecran1);
SDL_Flip(screen);
break;

}//switch boutton
break;
case SDL_KEYUP:
switch(event.key.keysym.sym)
{
case SDLK_p:
Mix_PlayChannel(-1,clic,0);
SDL_BlitSurface(image1, NULL, screen, &positionecranb);
play=NULL;
setting=NULL;
exit=NULL;
do
{
play=NULL;
setting=NULL;
exit=NULL;
SDL_Flip(screen);
SDL_PollEvent(&event);
}while(event.key.keysym.sym!=SDLK_b);
SDL_Flip(screen);
break;
case SDLK_s:
Mix_PlayChannel(-1,clic,0);
SDL_BlitSurface(image1, NULL, screen, &positionecranb);
play=NULL;
setting=NULL;
exit=NULL;
do
{
play=NULL;
setting=NULL;
exit=NULL;
SDL_BlitSurface(up, NULL, screen, &positionecranUp);
SDL_BlitSurface(down, NULL, screen, &positionecrandown);
SDL_Flip(screen);
SDL_PollEvent(&event);
switch(event.key.keysym.sym)
{
case SDL_KEYUP:
case SDLK_a:
if(!Mix_PlayingMusic())
Mix_PlayMusic(music,-1);
else if(Mix_PausedMusic())
Mix_ResumeMusic();
break;
case SDLK_d :
i=i-10;
Mix_VolumeMusic(i);
if(i<0)
i=0;
break;
//Music up
case SDLK_u :
i=i+10;
Mix_VolumeMusic(i);
break;
break;
}////////////////////////////////////////////////////////


switch(event.type)
{
case SDL_MOUSEBUTTONUP:
if(event.button.button==SDL_BUTTON_LEFT)
if(event.button.x>=100 && event.button.x<=(100+161) && event.button.y>=100 && event.button.y<=(163))
i=i+10;
Mix_VolumeMusic(i);
if(event.button.x>=100 && event.button.x<=(100+161) && event.button.y>=200 && event.button.y<=(263))
i=i-10;
Mix_VolumeMusic(i);
break;
}
if(event.type==SDL_QUIT){
cont=0;
break;}
SDL_Flip(screen);
}while(event.key.keysym.sym!=SDLK_b);

break;
case SDLK_q:
Mix_PlayChannel(-1,clic,0);
cont=0;
break;
case SDLK_b:
Mix_PlayChannel(-1,clic,0);
SDL_BlitSurface(t[j], NULL, screen, &positionecran);
play= IMG_Load("play.png");
SDL_BlitSurface(play, NULL, screen, &positionecran3);
settings= IMG_Load("setting.png");
SDL_BlitSurface(settings, NULL, screen, &positionecran1);
exit= IMG_Load("quit.png");
SDL_BlitSurface(exit, NULL, screen, &positionecran2);
SDL_Flip(screen);
break;

case SDLK_f:
SDL_WM_ToggleFullScreen(screen); 
break;



}//switch boutton
}//switch
}//while
SDL_FreeSurface(play);
SDL_FreeSurface(setting);
SDL_FreeSurface(exit);
Mix_FreeMusic(music);
Mix_FreeChunk(clic);
SDL_FreeSurface(play);
SDL_FreeSurface(settings);
SDL_FreeSurface(exit);
}//main
