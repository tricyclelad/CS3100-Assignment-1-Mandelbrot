//
//  MandelBrot.h
//  CS3100 Assignment 1 Mandelbrot
//
//  Created by Camron Blake Martinez on 1/16/16.
//  Copyright © 2016 Camron Blake Martinez. All rights reserved.
//

#ifndef MandelBrot_h
#define MandelBrot_h

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int ROWS=512;
const int COLS=512;
const int MAXITERS=389;
const float c1r=-2;
const float c1i=1;
const float c2r=0.5;
const float c2i=-1;

struct Complex {
    float real;
    float imag;
};

struct color{
    int r;
    int g;
    int b;
};

struct point{
    float x;
    float y;
};

void PrintComplex(Complex c){
    cout<<c.real<<"+"<<c.imag<<"i";
    
    return;
}

Complex AddComplex(Complex c1, Complex c2){
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}

Complex MultiplyComplex(Complex c1, Complex c2){
    Complex sum;
    sum.real = c1.real*c2.real - c1.imag*c2.imag;
    sum.imag = c1.real*c2.imag + c1.imag*c2.real;
    return sum;
}

float getReal(int j, Complex c1, Complex c2){
    float incrementVal;
    float real;
    incrementVal=(c2.real-c1.real)/COLS;
    real=c1.real+(incrementVal*j);
    return real;
}

float getImag(int i, Complex c1, Complex c2){
    float incrementVal;
    float imag;
    incrementVal=(c2.imag-c1.imag)/ROWS;
    imag=c1.imag+(incrementVal*i);
    return imag;
}

Complex getComplex(int i, int j, Complex c1, Complex c2){
    Complex c;
    c.real=getReal(j,c1,c2);
    c.imag=getImag(i,c1,c2);
    return c;
}

float getx(int j, point p1, point p2){
    float incrementVal;
    float x;
    incrementVal=(p2.x-p1.x)/COLS;
    x=p1.x+(incrementVal*j);
    return x;
}

float gety(int i, point p1, point p2){
    float incrementVal;
    float y;
    incrementVal=(p2.y-p1.y)/ROWS;
    y=p1.y+(incrementVal*i);
    return y;
}

point getPoint(int i, int j, point p1, point p2){
    point p;
    p.x=getx(j,p1,p2);
    p.y=gety(i,p1,p2);
    return p;
}

bool isInsideUnitCircle(point p){
    if((p.x*p.x+p.y*p.y)<=1)return true;
    return false;
}

int getdistSQ(point p){
    float dist;
    dist=p.x*p.x+p.y*p.y;
    return dist;
}


color getColor(unsigned int i){
    color c;
    i%=MAXITERS/10;
    c.r=i*10;
    c.g=i*10;
    c.b=i*2;
    return c;
}

void printColor(color c, ofstream &fout){
    fout << c.r << " ";
    fout << c.g << " ";
    fout << c.b << " ";
    fout << endl;
}


int getMbrotIndex(Complex c){
    int i=0;
    Complex z;
    z=c;
    while(z.real*z.real+z.imag*z.imag<4 && i<MAXITERS){
        z=MultiplyComplex(z,z);
        z=AddComplex(z,c);
        i++;
    }
    
    return i;
}

void makeMandelBrot(ofstream &f)
{
    Complex c1,c2;
    c1.real=c1r;
    c1.imag=c1i;
    c2.real=c2r;
    c2.imag=c2i;
    color pc;
    Complex c;
    int index;
    
    
    //find each pixel color
    for(int i=0;i<ROWS;++i){
        for(int j=0;j<COLS;++j){
            // find the point in space for this pixel
            c = getComplex(i,j,c1,c2);
            
            // get an index for this point
            index = getMbrotIndex(c);
            
            //get a color for this index
            pc = getColor(index);
            
            //output the color
            printColor(pc, f);
            
            //if(index==MAXITERS)cout<< " ";
            //else cout<< "*";
        }
        //cout << endl;
    }

}

#endif /* MandelBrot_h */
