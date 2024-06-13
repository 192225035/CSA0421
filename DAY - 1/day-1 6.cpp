#include <stdio.h>

#define MAX_PROCESS 10

typedef struct {
    int pid;
    int burst_time;
    int priority;
} Process;

void priority_scheduling(Process p[], int n) {
    int i, j, total_waiting_time = 0, total_turnaround_time = 0;

    // Sort the processes based on their priorities
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority < p[j].priority) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    int waiting_time = 0;
    for (i = 0; i < n; i++) {
        int turnaround_time = waiting_time + p[i].burst_time;

        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, waiting_time, turnaround_time);

        waiting_time += p[i].burst_time;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    Process p[MAX_PROCESS];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].pid = i + 1;
    }

    priority_scheduling(p, n);

    return 0;
}
