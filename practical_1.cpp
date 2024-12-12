#include <iostream> 
using namespace std; 
 
class Complex { 
 private: 
  float real;  
  float imag;  
 public: 
  Complex() { 
   real = 0.0; 
   imag = 0.0; 
  } 
  Complex(float r, float i) { 
   real = r; 
   imag = i; 
  } 
 
  Complex operator+(Complex& obj) { 
   return Complex(real + obj.real, imag + obj.imag); 
  } 
 
  Complex operator*(Complex& obj) { 
          return Complex(real * obj.real - imag * obj.imag, real * obj.imag + imag *   
obj.real); 
  } 
 
  friend ostream& operator<<(ostream& os, Complex& obj) { 
   os << obj.real << " + " << obj.imag << "i"; 
   return os; 
  } 
 
friend istream& operator>>(istream& is, Complex& obj) { 
is >> obj.real;  
is >> obj.imag;  
return is; 
} 
}; 
int main() { 
Complex c1, c2, result; 
cout<<endl<<"Enter first complex number (first real part then imaginary):\t"; 
cin>>c1; 
cout<<"First complex number is:\t"<<c1<<endl; 
cout<<endl<<"Enter first complex number (first real part then imaginary):\t"; 
cin>>c2; 
cout<<"Second complex number is:\t"<<c2<<endl; 
result = c1 + c2;  
cout<<endl<<"----------"<<endl<<"Addition is:\t"<<result; 
result = c1 * c2;  
cout<<endl<<"Multiplication is:\t"<<result<<endl<<"----------"<<endl; 
return 0; 
} 