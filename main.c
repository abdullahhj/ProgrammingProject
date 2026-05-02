#include <stdio.h>

#include "io.h"
#include "stdlib.h"
#include "waveform.h"
int main(void)
{
    int counter;
    WaveformSample * wf= readFromCsvFile ( "power_quality_log.csv" , &counter);

    double rms_phaseA= getRmsValue(wf , counter ,'A');
    double rms_phaseB= getRmsValue(wf , counter ,'B');
    double rms_phaseC= getRmsValue(wf , counter ,'C');

    printf("Rms value for phase A is %lf \n" , rms_phaseA);
    printf("Rms value for phase B is %lf \n" , rms_phaseB);
    printf("Rms value for phase C is %lf \n" , rms_phaseC);

    double peakTopeakA=getVoltagePeakToPeakValue(wf , counter ,'A');
    double peakTopeakB=getVoltagePeakToPeakValue(wf , counter ,'B');
    double peakTopeakC=getVoltagePeakToPeakValue(wf , counter ,'C');

    printf("VppA is %lf\n VppB is %lf \n VppC is %lf \n" , peakTopeakA,peakTopeakB,peakTopeakC);

    return 0;
}
