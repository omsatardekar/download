#include <graphics.h> 
#include <math.h> 
#include <iostream> 
using namespace std; 
void display(int x1,int y1,int x2,int y2,int x3,int y3) 
{ 
} 
int xmid = getmaxx()/2; 
int ymid = getmaxx()/2; 
line(xmid,0,xmid,getmaxy()); 
line(0,ymid,getmaxx(),ymid); 
line(x1+xmid,y1+ymid,x2+xmid,y2+ymid); 
line(x2+xmid,y2+ymid,x3+xmid,y3+ymid); 
line(x1+xmid,y1+ymid,x3+xmid,y3+ymid); 
void translate(int x1,int y1,int x2,int y2,int x3,int y3,int tx,int ty) 
{ 
outtextxy(100,100,"Before Translation:"); 
display(x1,y1,x2,y2,x3,y3); 
delay(3000); 
cleardevice(); 
outtextxy(100,100,"After Translation:"); 
display(x1+tx,y1+ty,x2+tx,y2+ty,x3+tx,y3+ty); 
} 
void scale(int x1,int y1,int x2,int y2,int x3,int y3,float tx,float ty) 
{ 
} 
outtextxy(100,100,"Before Scaling:"); 
display(x1,y1,x2,y2,x3,y3); 
delay(3000); 
cleardevice(); 
outtextxy(100,100,"After Scaling:"); 
display(x1*tx,y1*ty,x2*tx,y2*ty,x3*tx,y3*ty); 
void arotate(int x1,int y1,int x2,int y2,int x3,int y3,float a) 
{ 
} 
a = a*(3.1415/180); 
f
 loat c = cos(a); 
f
 loat s = sin(a); 
outtextxy(100,100,"Before Rotation:"); 
display(x1,y1,x2,y2,x3,y3); 
delay(3000); 
cleardevice(); 
outtextxy(100,100,"After Rotation:"); 
display((x1*c-y1*s),(x1*s+y1*c),(x2*c-y2*s),(x2*s+y2*c),(x3*c-y3*s),(x3*s+y3*c)); 
void crotate(int x1,int y1,int x2,int y2,int x3,int y3,float a) 
{ 
a = a*(3.1415/180); 
    float c = cos(a); 
    float s = sin(a); 
    outtextxy(100,100,"Before Rotation:"); 
    display(x1,y1,x2,y2,x3,y3); 
    delay(3000); 
    cleardevice(); 
    outtextxy(100,100,"After Rotation:"); 
    display((x1*c+y1*s),(-x1*s+y1*c),(x2*c+y2*s),(-x2*s+y2*c),(x3*c+y3*s),(-x3*s+y3*c)); 
 
} 
int main() 
{ 
    int x1,y1,x2,y2,x3,y3; 
    int gd = DETECT , gm; 
    cout<<"Enter the coordinates of the Triangle : x1,y1,x2,y2,x3,y3:"<<endl; 
    cin>>x1>>y1>>x2>>y2>>x3>>y3; 
    while(1) 
    { 
        int ch; 
        cout<<"Enter|1-Translation|2-Scaling|3-AnticlockwiseR|4-ClockwiseR|0-EXIT:"<<endl; 
        cin>>ch; 
        if(ch==1) 
        { 
            int tx,ty; 
            cout<<"Enter Tx and Ty:"<<endl; 
            cin>>tx>>ty; 
            initgraph(&gd,&gm,NULL); 
            translate(x1,y1,x2,y2,x3,y3,tx,ty); 
            getch(); 
            closegraph(); 
        } 
        else if(ch==2) 
        { 
            float sx,sy; 
            cout<<"Enter Sx and Sy:"<<endl; 
            cin>>sx>>sy; 
            initgraph(&gd,&gm,NULL); 
            scale(x1,y1,x2,y2,x3,y3,sx,sy); 
            getch(); 
            closegraph(); 
        } 
        else if(ch==3) 
        { 
            float a; 
            cout<<"Enter Angle:"<<endl; 
            cin>>a; 
            initgraph(&gd,&gm,NULL); 
            arotate(x1,y1,x2,y2,x3,y3,a); 
            getch(); 
            closegraph(); 
        } 
        else if(ch==4) 
        { 
            float a; 
            cout<<"Enter Angle:"<<endl; 
            cin>>a; 
            initgraph(&gd,&gm,NULL); 
            crotate(x1,y1,x2,y2,x3,y3,a); 
            getch(); 
            closegraph(); 
        } 
        else if(ch==0) 
        { 
            cout<<"EXITED"<<endl; 
            break; 
        } 
    } 
    return 0; 
}