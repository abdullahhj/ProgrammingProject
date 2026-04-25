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
#endif //WAVEFORM_H

