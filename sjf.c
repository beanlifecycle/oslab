#include<stdio.h>
#include<stdlib.h>

struct Process {
    int process_id;
    int BT;
};

int comp(const void *a, const void *b){
    return ((struct Process *)a)->BT - ((struct Process *)b)->BT;
}

void sjf(struct Process p[], int n){
    int wt[n], tat[n];
    wt[0] = 0;
    
    for(int i=1; i<n; i++){
        wt[i] = p[i-1].BT + wt[i-1];
    }
    
    for(int i=0; i<n; i++){
        tat[i] = p[i].BT + wt[i];
    }
    
    int tot_WT = 0, tot_TAT = 0;
    
    printf("\nProcesses Burst time Waiting time Turnaround time\n");
    
    for(int i=0; i<n; i++){
        tot_WT+=wt[i];
        tot_TAT+=tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].BT,wt[i],tat[i]);
    }
    
    float avg_WT = (float) tot_WT/n;
    float avg_TAT = (float) tot_TAT/n;
    
    printf("Avg Waiting time = %.2f\n", avg_WT);
    printf("Avg Turnaround time = %.2f\n", avg_TAT);
}

int main(){
	
	struct Process p[] = {
	    {1, 21},
        {2, 3},
        {3, 6},
        {4, 2},
    };
    
    int n = sizeof(p)/sizeof(p[0]);
    
    qsort(p,n,sizeof(p[0]),comp);
    
    
    printf("Order in which processes get executed:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", p[i].process_id);
    }

    sjf(p,n);
	return 0;
}
