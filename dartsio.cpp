
#include <cmath>

using namespace std;




int dartsio(int a,int b) {
    const double pi =3.141592653589;
    const int playground =500;
    int r1 =  20;
    int r2 = 40;
    int r3 = 150;
    int r4 = 180;
    int r5 = 320;
    int r6 = 350;
    int xdist,ydist,sector,score;
    double distance,sin,angle;
    bool n,f = true;
    if (a>1000) {return 0;}
    if (b>1000){return 0;}

    if (a<500) {
        xdist= 500-a;
    }
    else
    { xdist =a-500;
     n =false;
    }
    if (b<500) {
        ydist= 500-b;

    }
    else
    { ydist =b-500;
      f =false;
    }
    distance = sqrt(pow(xdist,2)+pow(ydist,2));
    sin = ((asin(xdist/distance))*180/pi);
    if ((n== false)&&(f==false))
        { angle = (360 - sin); }else {
        if ((n == true) && (f == false)) { angle = (180 + sin); } else {
        if ((n == true) && (f == true)) { angle = (180-sin); } else {
        if ((n == false) && (f == true)) { angle = sin; }
    }}}


  if ((angle>=81)&&(angle<99)){sector= 20;}else{
    if ((angle>=63)&&(angle<81)){sector= 1;}else{
    if ((angle>=45)&&(angle<63)){sector= 18;}else{
    if ((angle>=27)&&(angle<45)){sector= 4;}else{
    if ((angle>=9)&&(angle<27)){sector= 13;}else{
    if (((angle>=351)&&(angle<=359))||((angle<9)&&(angle>=0))){sector= 6;}else{
    if ((angle>=333)&&(angle<351)){sector= 10;}else{
    if ((angle>=315)&&(angle<333)){sector= 15;}else{
    if ((angle>=297)&&(angle<315)){sector= 2;}else{
    if ((angle>=279)&&(angle<297)){sector= 17;}else{
    if ((angle>=261)&&(angle<279)){sector= 3;}else{
    if ((angle>=243)&&(angle<261)){sector= 19;}else{
    if ((angle>=225)&&(angle<243)){sector= 7;}else{
    if ((angle>=207)&&(angle<225)){sector= 16;}else{
    if ((angle>=189)&&(angle<207)){sector= 8;}else{
    if ((angle>=171)&&(angle<189)){sector= 11;}else{
    if ((angle>=153)&&(angle<171)){sector= 14;}else{
    if ((angle>=135)&&(angle<153)){sector= 9;}else{
    if ((angle>=117)&&(angle<135)){sector= 12;}else{
    if ((angle>=99)&&(angle<117)){sector= 5;}
}}}}}}}}}}}}}}}}}}}
if (sin =0)
    if ((n== false)&&(f==false))
    { angle = 0; }else {
        if ((n == true) && (f == false)) { angle = (270); } else {
            if ((n == true) && (f == true)) { angle = (180); } else {
                if ((n == false) && (f == true)) { angle = 90; }
            }}}

    if (distance<=r1){score =50;}
    else{if ((distance>r1)&&(distance<=r2)){score = 25;}
    else{if ((distance>r2)&&(distance<=r3)){score = sector;}
    else{if ((distance>r3)&&(distance<=r4)){score = sector*3;}
    else{if ((distance>r4)&&(distance<=r5)){score = sector;}
    else {if ((distance>r5)&&(distance<=r6)){score = sector*2;}
    else{score = 0;}}}}}}

    return score;
}