#include <stdio.h>
#include <stdlib.h>

struct process{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

void swap(struct process *a, struct process *b){
    struct process *cur = malloc(sizeof(struct process));
    cur->process_id = a->process_id; cur->arrival_time = a->arrival_time; cur->completion_time = a->completion_time;
    cur->turn_around_time = a->turn_around_time; cur->waiting_time = a->waiting_time; cur->burst_time = a->burst_time;
    a->process_id = b->process_id; a->arrival_time = b->arrival_time; a->completion_time = b->completion_time;
    a->turn_around_time = b->turn_around_time; a->waiting_time = b->waiting_time; a->burst_time = b->burst_time;
    b->process_id = cur->process_id; b->arrival_time = cur->arrival_time; b->completion_time = cur->completion_time;
    b->turn_around_time = cur->turn_around_time; b->waiting_time = cur->waiting_time; b->burst_time = cur->burst_time;
}

void sort(int *n, struct process *p){
    for (int i = 0; i < *n-1; i++){
        for (int j = i+1; j < *n; j++){
            if (p[i].arrival_time > p[j].arrival_time){
                swap(&p[i], &p[j]);
            }
        }
    }
}

void calculate_waiting_time(struct process *cur, struct process *p){
    cur->waiting_time = p[0].arrival_time - p[cur->process_id].arrival_time;
    for (int i = 0; i < cur->process_id; i++){
        cur->waiting_time = cur->waiting_time + p[i].burst_time;
    }
}

void calculate_turnaround_time(struct process *cur){
    cur->turn_around_time = cur->waiting_time + cur->burst_time;
}

void calculate_completion_time(struct process *cur){
    cur->completion_time = cur->waiting_time + cur->arrival_time + cur->burst_time;
}

void average_turnaround_time(*n, struct process *p){
    double t_average = 0;
    for (int i = 0; i < *n; i++){
        t_average += p[i].turn_around_time;
    }
    t_average = t_average / *n;
    printf("Average Turnaround time = %f\n", t_average);
}

void average_waiting_time(*n, struct process *p){
double w_average = 0;
for (int i = 0; i < *n; i++){
w_average += p[i].waiting_time;
}
w_average = w_average / *n;
printf("Average Waiting time = %f\n", w_average);
}

int main() {
    int n;
    struct process p[1000] = {0};
    printf("Input the number of processes (not more than 1000): \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        p[i].process_id = i;
        printf("Process %d\n", p[i].process_id);
        printf("Input the arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Input the burst time: ");
        scanf("%d", &p[i].burst_time);
    }
    sort(&n, &p);
    printf("Waiting time: \n");
    for (int i = 0; i < n; i++){
        calculate_waiting_time(&p[i], &p);
        printf("P%d = %d\n", p[i].process_id, p[i].waiting_time);
    }
    printf("Completion time: \n");
    for (int i = 0; i < n; i++){
        calculate_completion_time(&p[i]);
        printf("P%d = %d\n", p[i].process_id, p[i].completion_time);
    }
    printf("Turnaround time: \n");
    for (int i = 0; i < n; i++){
        calculate_turnaround_time(&p[i]);
        printf("P%d = %d\n", p[i].process_id, p[i].turn_around_time);
    }
    average_turnaround_time(&n, &p);
    average_waiting_time(&n, &p);
    return 0;
}
