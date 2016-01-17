//
//  timeStatistics.h
//  CS3100 Assignment 1 Mandelbrot
//
//  Created by Camron Blake Martinez on 1/16/16.
//  Copyright © 2016 Camron Blake Martinez. All rights reserved.
//

#ifndef timeStatistics_h
#define timeStatistics_h
#include <vector>
#include <numeric>

template <typename F>
auto timeStatistics(F f, ofstream& fout, int samples)
{
    
    std::vector<decltype(timeFunction(f, fout))> times(samples);
    
    std::generate(times.begin(), times.end(), [&](){return timeFunction(f, fout);});
    
    //std::generate(times.begin(), times.end(), timeFunction(f, fout));
    
    auto total = std::accumulate(times.begin(), times.end(), 0.0);
    
    auto avg =  total/samples;
    
   // auto var = 10;
    auto var = std::accumulate(times.begin(), times.end(), 0.0, [avg](auto a, auto time){return a + (time - avg) * (time - avg);});
    
    auto stddev = sqrt(var / samples);

    return std::make_pair(avg, stddev);
}

#endif /* timeStatistics_h */
