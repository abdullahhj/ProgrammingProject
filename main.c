#include <stdio.h>

#include "io.h"
#include "stdlib.h"
#include "waveform.h"
int main(int argc , char *argv[])
{
    int counter;
    char * csv_data_file = argv[1];
    WaveformSample * wf= readFromCsvFile (csv_data_file , &counter);

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

    double dcOffsetA=getDcOffsetValue(wf , counter ,'A');
    double dcOffsetB=getDcOffsetValue(wf , counter ,'B');
    double dcOffsetC=getDcOffsetValue(wf , counter ,'C');
    printf("DC offset A is %lf \n" , dcOffsetA);
    printf("DC offset B is %lf \n" , dcOffsetB);
    printf("DC offset C is %lf \n" , dcOffsetC);

    int clippingNumberA=getClippingsValue(wf , counter ,'A');
    int clippingNumberB=getClippingsValue(wf , counter ,'B');
    int clippingNumberC=getClippingsValue(wf , counter ,'C');

    printf("clippingNumberA is %d\n clippingNumberB is %d \n clippingNumberC is %d \n" ,
        clippingNumberA ,clippingNumberB,clippingNumberC);

    return 0;
}
