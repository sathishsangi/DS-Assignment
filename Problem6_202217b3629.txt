#include <stdio.h>
 
void main()
{
    int n, a[10], b[10], t[10], w[10], ct[10], i;  
    float att = 0, awt = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    printf("\nEnter the arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    
    ct[0] = a[0] + b[0];  
    for(i = 1; i < n; i++) {
        if (a[i] > ct[i-1]) {
            ct[i] = a[i] + b[i];  
        } else {
            ct[i] = ct[i-1] + b[i];  
        }
    }
    
    for(i = 0; i < n; i++) {
        t[i] = ct[i] - a[i];  
        w[i] = t[i] - b[i];  
        awt += w[i];
        att += t[i];
    }
    
    awt /= n;  
    att /= n;  
    
    printf("\n\tProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, a[i], b[i], w[i], t[i]);  
    }
    
    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);
}