#include <iostream> 
#include <cstdlib> 
#include <graphics.h> 
using namespace std; 
int main() 
{ 
int gd = DETECT, gm; 
int i, x, y, flag=0; 
initgraph(&gd, &gm,NULL); 
x = getmaxx()/2; 
y = 30; 
while (1) 
{ 
if(y >= getmaxy()-30 || y <= 30) 
f
 lag = !flag; 
setcolor(RED); 
circle(x, y, 30); 
f
 loodfill(x, y, RED); 
delay(50); 
cleardevice(); 
if(flag) 
{ 
y = y + 5; 
} 
else 
{ 
y = y - 5; 
} 
} 
delay(5000); 
closegraph(); 
return 0; 
} 
#include <iostream> 
#include <graphics.h> 
using namespace std; 
int main() 
{ 
int gd = DETECT, gm; 
int i, x, y, flag = 0; 
 
    initgraph(&gd, &gm, NULL); 
 
    x = getmaxx() / 2; // Center the ball horizontally 
    y = 30; // Initial vertical position 
 
    while (1) 
    { 
        if (y >= getmaxy() - 30 || y <= 30) // If the ball reaches the top or bottom 
            flag = !flag; // Reverse direction 
 
        setcolor(RED);  
 
        setfillstyle(SOLID_FILL, RED); 
 
        circle(x, y, 30); // Draw a circle at (x, y) with radius 30 
        floodfill(x, y, RED); // Fill the circle with RED color; 
 
        delay(50); 
 
        cleardevice(); 
        if (flag) 
        { 
            y = y + 5; // Move the ball down 
        } 
        else 
        { 
            y = y - 5; // Move the ball up 
        } 
    } 
 
    delay(5000); 
closegraph(); 
return 0; 
}