#include <iostream> 
#include <graphics.h> 
#include <cmath> 
using namespace std; 
 
class DDA { 
private: 
    float x1, x2, y1, y2, dx, dy, xi, yi, xn, yn; 
    int length; 
 
public: 
    void initialValues(float a, float b, float c, float d) { 
        x1 = a; 
        y1 = b; 
        x2 = c; 
        y2 = d; 
 
        dx = x2 - x1; 
        dy = y2 - y1; 
 
        length = max(abs(dx), abs(dy)); 
        xi = (length == 0) ? 0 : dx / length; 
        yi = (length == 0) ? 0 : dy / length; 
 
        xn = x1; 
        yn = y1; 
    } 
 
    void drawLine() { 
        for (int i = 0; i <= length; i++) { 
            putpixel(round(xn), round(yn), CYAN); 
            xn += xi; 
            yn += yi; 
            delay(50); 
        } 
    } 
}; 
 
class Bresenham { 
private: 
    int xc, yc, r, xi, yi, p; 
 
public: 
    void initialValues(int a, int b, int radius) { 
        xc = a; 
        yc = b; 
        r = radius; 
 
        xi = 0; 
        yi = r; 
        p = 3 - (2 * r); 
    } 
 
    void drawCircle() { 
        while (xi <= yi) { 
            putpixel(xc + xi, yc + yi, WHITE); 
            putpixel(xc - xi, yc + yi, CYAN); 
            putpixel(xc + xi, yc - yi, WHITE); 
            putpixel(xc - xi, yc - yi, CYAN); 
            putpixel(xc + yi, yc + xi, WHITE); 
            putpixel(xc - yi, yc + xi, CYAN); 
            putpixel(xc + yi, yc - xi, WHITE); 
            putpixel(xc - yi, yc - xi, CYAN); 
 
            xi++; 
            if (p < 0) { 
                p += (4 * xi) + 6; 
            } else { 
                yi--; 
                p += (4 * (xi - yi)) + 10; 
            } 
            delay(50); 
        } 
    } 
}; 
 
int main() { 
    int gd = DETECT, gm; 
    int xc, yc, r; 
 
    cout << "Enter the x coordinate of circle's center: "; 
    cin >> xc; 
    cout << "Enter the y coordinate of circle's center: "; 
    cin >> yc; 
    cout << "Enter the radius of the circle: "; 
    cin >> r; 
 
    Bresenham b1, b2; 
    DDA line1, line2, line3; 
 
    initgraph(&gd, &gm, NULL); 
 
    b1.initialValues(xc, yc, r); 
    b1.drawCircle(); 
 
    b2.initialValues(xc, yc, r / 2); 
    b2.drawCircle(); 
f
 loat sqrt3 = 1.732; // Approximation for square root of 3 
line1.initialValues(xc, yc - r, xc + (r / sqrt3), yc + (r / 2)); 
line2.initialValues(xc, yc - r, xc - (r / sqrt3), yc + (r / 2)); 
line3.initialValues(xc + (r / sqrt3), yc + (r / 2), xc - (r / sqrt3), yc + (r / 2)); 
line1.drawLine(); 
line2.drawLine(); 
line3.drawLine(); 
getch(); 
closegraph(); 
return 0; 
}