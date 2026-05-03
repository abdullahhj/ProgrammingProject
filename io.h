//
// Created by Huawei on 4/25/2026.
//

#ifndef IO_H
#define IO_H
#include "waveform.h"
WaveformSample * readFromCsvFile (char * fileName , int * dataSize);
void generateResultFile(char * fileName,
    double rms_phaseA,
    double rms_phaseB,
    double rms_phaseC,
    double vpp_phaseA,
    double vpp_phaseB,
    double vpp_phaseC,
    double dc_offsetA,
    double dc_offsetB,
    double dc_offsetC,
    int clipping_phaseA,
    int clipping_phaseB,
    int clipping_phaseC);;

int checkRmsTolerance(double value);
#endif //IO_H
