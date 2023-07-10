#include<stdio.h>

int main() {
    int p[20], bt[20], su[20], wt[20], tat[20], at[20], i, k, n, temp;
    float wtavg = 0, tatavg = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("AT of %d: ", i);
        scanf("%d", &at[i]);
        printf("BT of %d: ", i);
        scanf("%d", &bt[i]);
        printf("System/User Process (1/0): ");
        scanf("%d", &su[i]);
    }
    
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (at[i] > at[k]) {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                
                temp = su[i];
                su[i] = su[k];
                su[k] = temp;
                
                temp = at[i];
                at[i] = at[k];
                at[k] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (k = i + 1; k < n; k++) {
            if (at[i] == at[k] && su[i]>su[k]) {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                
                temp = su[i];
                su[i] = su[k];
                su[k] = temp;
                
                temp = at[i];
                at[i] = at[k];
                at[k] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];
    
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1] - at[i];
        tat[i] = tat[i - 1] + bt[i] - at[i];
        
        wtavg += wt[i];
        tatavg += tat[i];
    }
    
    printf("\nPROCESS\t\tSYSTEM/USER PROCESS\tARRIVAL TIME\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    
    for (i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t\t%d\t\t%d\t\t%d\t\t%d", p[i], su[i], at[i], bt[i], wt[i], tat[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);
    
    return 0;
}
