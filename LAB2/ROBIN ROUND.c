#include <stdio.h>
int main() {
    printf("NAME:RAHUL M MATTI\n" "USN:1BM25CS498\n");
    printf("\nROUND ROBIN SCHEDULING\n");
    int n, tq;
    printf("\nEnter number of processes: ");
    scanf("%d",&n);
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);
    int at[n], bt[n], rt[n], wt[n], tat[n], ct[n];
    for(int i=0;i<n;i++){
        printf("\nProcess P%d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }
    int time = 0, done;
    do{
        done = 1;
        for(int i=0;i<n;i++){
            if(rt[i] > 0){
                done = 0;
                if(rt[i] > tq){
                    time += tq;
                    rt[i] -= tq;
                }
                else{
                    time += rt[i];
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                }
            }
        }
    }while(done == 0);
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],wt[i],tat[i]);
    }
    return 0;
}
