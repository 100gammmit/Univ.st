import processing.video.*;
import ddf.minim.*;

Minim min;
AudioPlayer player, main, game, score, count10, count5, count3; 
PImage gb, mb, sb;
Movie how;

void setup()
{
  size(500, 500);
  min=new Minim(this);
  how=new Movie(this, "Howtoplay.mp4");
  gb = loadImage("grass.png");
  mb = loadImage("main_mole.png");
  sb = loadImage("score_mole.png");
  player =min.loadFile("015_ddiring.mp3");
  main = min.loadFile("Beat_Your_Competition.mp3");
  game = min.loadFile("Bike_Rides.mp3");
  score = min.loadFile("Get_Outside.mp3");
  count10 = min.loadFile("[Track 04] Countdown Sound Effect.wav");
  count5 = min.loadFile("[Track 07] Countdown Sound Effect.wav");
  count3 = min.loadFile("[Track 02] Countdown Sound Effect.wav");
}

int ran = int(random(9));
int goldenmole = int(random(10));
int x, y;
int sc=0;
int bsc=0;
int gamemode=0;
float second=0.0166;
float timer=30;
float moleRS=1;

void draw(){
if(gamemode==0){
  count3.pause();
  count3.rewind();
  image(mb, 0, 0);
  main.play();
  
  if(bsc<sc) {bsc=sc;}
  
  timer=30;
  sc=0;
  moleRS=1;
  
  fill(150);
  rectMode(CENTER);  
  rect(400, 300, 200, 50);  
  rect(400, 400, 200, 50);
  fill(0);
  textSize(50);
  text("Catch Mole!!", 100, 50);
  fill(255);
  textSize(30);
  text("Start Game", 330, 310);
  text("How to Play", 320, 410);
  
  if((300<mouseX)&&(mouseX<500)&&(mouseY>250)&&(mouseY<350))
{
    if(mousePressed==true){
      main.pause();
      main.rewind();
      gamemode=1;
    }
  }
  if((300<mouseX)&&(mouseX<500)&&(mouseY>350)&&(mouseY<450))
{
    if(mousePressed==true){
      gamemode=3;
    }
  }
}

if(gamemode==1){
  frameRate(60);
  image(gb, 0, 0);
  hole();
  mole();
  hammer();
  game.play();

timer-=second;
if(timer<=10){
  count10.play();
}
if(timer<=5){
  count10.pause();
  count10.rewind();
  count5.play();
}
if(timer<=3){
  count5.pause();
  count5.rewind();
  count3.play();
  loadPixels();
  for(int i=0; i<pixels.length;i++){
    pixels[i]=color(red(pixels[i]), 0, 0);
  }
  updatePixels();
}
if(timer<=0){
  game.pause();
  game.rewind();
  gamemode=2;
}

moleRS-=second;
if(moleRS<=0){
  newmole();
}

textSize(50);
text("score: "+sc, 130, 50);
text(timer, 160, 485);
if((x<mouseX)&&(mouseX<x+100)&&(mouseY>y-50)&&(mouseY<y+50))
{
  if(mousePressed==true)
  {
    player.play();
    player.rewind();
    if(goldenmole==5){sc+=1000;}
    else sc+=100;
    newmole();
  }
}
}

if(gamemode==2){
score.play();
image(sb, 0, 0);
fill(0);
textSize(60);
text("Game Over", 90, 150);
textSize(50);
text("score: "+sc, 120, 250);


if(bsc<sc){
  fill(#FFE603);
  text("New record!!", 100, 300);
}
if(bsc>=sc){
  fill(0);
  text("Best Score: "+bsc, 50, 300);
}

fill(0);
text("Press any key\n   to ReStart", 80, 400);
if(keyPressed==true){
  score.pause();
  score.rewind();
  gamemode = 0;
}
}

if(gamemode==3){
  how.loop();
  image(how, 0, 0, width, height);
  fill(150);
  rectMode(CENTER);  
  rect(100, 50, 200, 50);
  fill(255);
  textSize(30);
  text("Back to Main", 10, 60);
  if((0<mouseX)&&(mouseX<200)&&(mouseY>25)&&(mouseY<75))
{
    if(mousePressed==true){
      how.pause();
      gamemode=0;
    }
  }
}

}

void hole(){
int hx, hy;
for(hy=150;hy<=400;hy+=125){
  for(hx=100;hx<=400;hx+=150){
    fill(0);
    ellipse(hx, hy, 100, 100);
    fill(#624B32);
    arc(hx, hy, 80, 50, -PI, 0);
  }
}

}

void mole(){
if(goldenmole==5){fill(#EDD811);}
else fill(#624B32);
if (ran==0){x=100;y=150;}
else if(ran==1){x=250;y=150;}
else if(ran==2){x=400;y=150;}
else if(ran==3){x=100;y=275;}
else if(ran==4){x=250;y=275;}
else if(ran==5){x=400;y=275;}
else if(ran==6){x=100;y=400;}
else if(ran==7){x=250;y=400;}
else if(ran==8){x=400;y=400;}
arc(x, y, 80, 150, -PI, 0);
arc(x-5, y-25, 10, 10, 0, PI);
arc(x+5, y-25, 10, 10, 0, PI);
fill(0);
ellipse(x-15, y-45, 10, 10);
ellipse(x+15, y-45, 10, 10);
ellipse(x, y-30, 10, 7);
}

void newmole()
{
ran = int(random(9));
goldenmole = int(random(10));
moleRS=1;
}

void hammer(){
rectMode(CENTER);
if(mousePressed==false)
{
fill(#FF0000);
rect(mouseX, mouseY-50, 100, 50);
fill(255, 255, 255);
rect(mouseX, mouseY, 20, 150);
}
else if(mousePressed==true)
{
fill(#FF0000);
rect(mouseX-50, mouseY, 50, 100);
fill(255, 255, 255);
rect(mouseX, mouseY, 150, 20);
}
}

void movieEvent(Movie m){m.read();}
