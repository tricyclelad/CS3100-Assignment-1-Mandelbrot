//
//  timeFunction.h
//  CS3100 Assignment 1 Mandelbrot
//
//  Created by Camron Blake Martinez on 1/16/16.
//  Copyright © 2016 Camron Blake Martinez. All rights reserved.
//

#ifndef timeFunction_h
#define timeFunction_h
#include <chrono>
#include <stdio.h>

template <typename F>
auto timeFunction(F f, ofstream& fout)
{
    auto start = std::chrono::steady_clock::now();
    f(fout);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end-start;
    
    return diff.count();
}




#endif /* timeFunction_h */
