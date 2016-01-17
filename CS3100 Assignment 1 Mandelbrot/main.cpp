//
//  main.cpp
//  CS3100 Assignment 1 Mandelbrot
//
//  Created by Camron Blake Martinez on 1/16/16.
//  Copyright © 2016 Camron Blake Martinez. All rights reserved.
//

//
//  main.cpp
//  Mandelbrots
//
//  Created by Camron Blake Martinez on 10/14/14.
//  Copyright (c) 2014 Camron Blake Martinez. All rights reserved.
//
#include <fstream>
#include <iostream>
#include "MandelBrot.h"
#include "timeFunction.h"
#include "timeStatistics.h"

using namespace std;

int main(){
    ofstream fout;
    fout.open("mybrot.ppm");
   
    //top matter
    fout<<"P3 ";
    fout<<COLS<< " ";
    fout<<ROWS<< " ";
    fout<<"255 ";
    fout<<endl;
    
    makeMandelBrot(fout);
    
    auto time = timeFunction(makeMandelBrot, fout);
    
    auto timeStats = timeStatistics(makeMandelBrot, fout, 5);
    
    cout << "Time: " << time << endl;
    cout << "Average: " << timeStats.first << endl;
    cout << "Std Deviation: " << timeStats.second << endl;
    
    fout.close();
    
    return 0;
}
