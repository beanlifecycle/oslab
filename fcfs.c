#include<stdio.h>

struct Process {
    int process_id;
    int AT;
    int BT;
    int WT;
    int TAT;
};

void fcfs(struct Process p[], int n){
    int current_time = 0;
    
    for(int i=0; i<n; i++){
        if(p[i].AT > current_time){
            current_time = p[i].AT;
        }
        
        p[i].WT = current_time - p[i].AT;
        p[i].TAT = p[i].WT + p[i].BT;
        current_time+=p[i].BT;
    }
}

void display(struct Process p[], int n){
    int tot_WT=0, tot_TAT=0;
    
    printf("Process\tArrival time\tBurst time\tWaiting time\tTA time\n");
    
    for(int i=0; i<n; i++){
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i].process_id, p[i].AT, p[i].BT, p[i].WT, p[i].TAT);
        tot_WT+=p[i].WT;
        tot_TAT+=p[i].TAT;
    }
    
    double avg_WT = (double)tot_WT/n;
    double avg_TAT = (double)tot_TAT/n;
    
    printf("Avg Waiting time : %.2lf\n", avg_WT);
    printf("Avg Turn around time: %.2lf\n", avg_TAT);
}

int main(){
	
	struct Process p[] = {
	    {1, 0, 2, 0, 0},
        {2, 1, 2, 0, 0},
        {3, 5, 3, 0, 0},
        {4, 6, 4, 0, 0},
    };
    
    int n = sizeof(p)/sizeof(p[0]);
    
    fcfs(p,n);
	display(p,n);
	return 0;
}
