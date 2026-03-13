#include <stdio.h>

int main() {
    printf("NAME:RAHUL M MATTI\n" "USN:1BM25CS498\n");
    printf("\nPRIORITY SCHEDULING (PREEMPTIVE)\n");
    int n;
    printf("\nEnter number of processes: ");
    scanf("%d",&n);
    int at[n], bt[n], pr[n], rt[n];
    int ct[n], tat[n], wt[n];
    for(int i=0;i<n;i++){
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);
        rt[i] = bt[i];
    }
    int time = 0, completed = 0;
    while(completed < n){
        int min = 9999;
        int index = -1;
        for(int i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0){
                if(pr[i] < min){
                    min = pr[i];
                    index = i;
                }
            }
        }
        if(index == -1){
            time++;
        }
        else{
            rt[index]--;
            time++;
            if(rt[index] == 0){
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
                completed++;
            }
        }
    }
    printf("\nPID\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\n",i+1,wt[i],tat[i]);
    }
    return 0;
}
