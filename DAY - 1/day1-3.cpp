#include<stdio.h>

int main()
{
    int n;
    printf("Enter Total Number of Processes:");
    scanf("%d", &n);

    int wait_time = 0, ta_time = 0, arr_time[n], burst_time[n], temp_burst_time[n];

    int x = n;

    for(int i = 0; i < n; i++)
    {
        printf("Enter Details of Process %d \n", i + 1);
        printf("Arrival Time:  ");
        scanf("%d", &arr_time[i]);
        printf("Burst Time:   ");
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    int time_slot;
    printf("Enter Time Slot:");
    scanf("%d", &time_slot);

    int total = 0,  counter = 0, i;
    printf("Process ID       Burst Time       Turnaround Time      Waiting Time\n");

    for(total=0, i = 0; x!=0; )  
    {  
        if(temp_burst_time[i] <= time_slot && temp_burst_time[i] > 0)    
        {  
            total = total + temp_burst_time[i];  
            temp_burst_time[i] = 0;
            counter++;
            x--;
            printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], total, total - burst_time[i]);
            wait_time += total - burst_time[i];
            ta_time += total;
        }  
        else  
        {  
            total += time_slot;  
            temp_burst_time[i] -= time_slot;  
        }  
        if(counter == x)  
        {  
            i = 0;  
            counter = 0;  
        }  
        else  
        {  
            i = (i + 1) % n;  
        }  
    }  

    printf("Average Waiting Time = %.2f\n", (float)wait_time / n);
    printf("Average Turnaround Time = %.2f\n", (float)ta_time / n);

    return 0;
}
