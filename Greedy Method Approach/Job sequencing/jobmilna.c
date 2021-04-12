#include <stdio.h>
#include <stdlib.h>
# define MAX 100

typedef struct Job {
  char id[5];
  int deadline;
  int profit;
} Job;

void jobSequencingWithDeadline(Job jobs[], int n)
{
  int i, j, k, maxprofit;
  int timeslot[MAX];
  int filledTimeSlot = 0;
  int dmax = 0;
  for(i = 0; i < n; i++) {
    if(jobs[i].deadline > dmax) {
      dmax = jobs[i].deadline;
    }
  }
  for(i = 1; i <= dmax; i++) {
    timeslot[i] = -1;
  }
  printf("dmax: %d\n", dmax);
  for(i = 1; i <= n; i++) {
    k = minValue(dmax, jobs[i - 1].deadline);
    while(k >= 1) {
      if(timeslot[k] == -1) {
        timeslot[k] = i-1;
        filledTimeSlot++;
        break;
      }
      k--;
    }
    if(filledTimeSlot == dmax) {
      break;
    }
  }
  printf("\nRequired Jobs: ");
  for(i = 1; i <= dmax; i++) {
    printf("%s", jobs[timeslot[i]].id);

    if(i < dmax) {
      printf(" --> ");
    }
  }
  maxprofit = 0;
  for(i = 1; i <= dmax; i++) {
    maxprofit += jobs[timeslot[i]].profit;
  }
  printf("\nMax Profit: %d\n", maxprofit);
}
int minValue(int x, int y) {
  if(x < y) return x;
  return y;
}
int main(void) {
  int i, j;
  Job jobs[7];
  Job temp;
    for (i=0;i<7;i++)
    {
            printf("---------------------\n");
            printf("Enter Jobs\n");
            scanf("%s",&jobs[i].id);
            printf("---------------------\n");
            printf("Enter deadline\n");
            scanf("%d",&jobs[i].deadline);
            printf("---------------------\n");
            printf("Enter profit\n");
            scanf("%d",&jobs[i].profit);

    }
  for(i = 1; i < 7; i++) {
    for(j = 0; j < 7 - i; j++) {
      if(jobs[j+1].profit > jobs[j].profit) {
        temp = jobs[j+1];
        jobs[j+1] = jobs[j];
        jobs[j] = temp;
      }
    }
  }

  printf("%s %s %s\n", "Job", "Deadline", "Profit");
  for(i = 0; i < 7; i++) {
    printf("%s %d %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
  }

  jobSequencingWithDeadline(jobs, 7);

  return 0;
}



