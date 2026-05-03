//
// Created by Huawei on 4/25/2026.
//

#ifndef WAVEFORM_H
#define WAVEFORM_H

typedef struct
{
    double timestamp;
    double phase_A;
    double phase_B;
    double phase_C;
    double current;
    double power_factor;
    double percentage;
    double frequency;

}WaveformSample ;

double getRmsValue(WaveformSample * wf , int samples_number , char p);
double getVoltagePeakToPeakValue(WaveformSample * wf , int samples_number , char p);
double getDcOffsetValue(WaveformSample * wf , int samples_number , char p);
int    getClippingsValue(WaveformSample * wf , int samples_number , char p);
#endif //WAVEFORM_H

