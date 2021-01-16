#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

//Mostrar politica de planificación (string) y prioridad (max/min)
int main()
{
    //pid = 0 -> proceso de llamada 
    int num_policity = sched_getscheduler(0);
    if(num_policity != -1){
        printf("Politica de planificación: ");
        switch (num_policity)
        {
            case SCHED_RR:
                printf("Round-robin\n");
                break;
            case SCHED_FIFO:
                printf("FiFo\n");
                break;
            case SCHED_OTHER:
                printf("Planificación por defecto\n");
                break;
            default:
                printf("indefinida\n");
                break;
        }
    }else{
        perror("Scheduler\n");
        return -1;
    }

    struct sched_param p;
    if(sched_getparam(0,&p) == 0){
        printf("Prioridad: %i\n", p.sched_priority);
    }else{
        perror("Priority\n");
        return -1;
    }

    int max = sched_get_priority_max(num_policity);
    int min = sched_get_priority_min(num_policity);
    if(max != -1 && min != -1){
        printf("Maxima prioridad: %i, Minima prioridad: %i\n",max, min);
    }else{
        perror("Max o Min\n");
        return -1;
    }
        
    return 0;
}
