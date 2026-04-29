#include <stdio.h>

#include "io.h"

int main(void)
{
    int counter;
    WaveformSample * wf= readFromCsvFile ( "power_quality_log.csv" , &counter);

    printf("test reading \n");
    printf("first line is : time %lf , VoltA : %lf , VoltB %lf , VoltC %lf \n",
        wf[0].timestamp , wf[0].phase_A , wf[0].phase_B , wf[0].phase_C );
    printf("total number of reading is %d" , counter);
    return 0;
}
