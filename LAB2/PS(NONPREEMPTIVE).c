#include <stdio.h>
#include <stdbool.h>
int main() {
    printf("NAME:RAHUL M MATTI\n" "USN:1BM25CS498\n");
    printf("\nPRIORITY SCHEDULING (NON-PREEMPTIVE)\n");
    int n;
    printf("\nEnter number of processes: ");
    scanf("%d",&n);
    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n];
    bool completed[n];
    for(int i=0;i<n;i++){
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);
        completed[i] = false;
    }
    int time = 0, done = 0;
    while(done < n){
        int min = 9999;
        int index = -1;
        for(int i=0;i<n;i++){
            if(at[i] <= time && completed[i]==false){
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
            ct[index] = time + bt[index];
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            time = ct[index];
            completed[index] = true;
            done++;
        }
    }
    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],wt[i],tat[i]);
    }
    return 0;
}
