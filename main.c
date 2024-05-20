#include<stdio.h>
#define MAX 5
int alloc[MAX][MAX], max[MAX][MAX], need[MAX][MAX], avail[MAX], request[MAX];
int SafeSequence(int n, int m);
void resourceRequest(int n, int m);
int main() {
int n, m;
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter the number of resources: ");
scanf("%d", &m);
printf("Enter MAX matrix:\n");
for(int i = 0; i < n; i++)
{
for(int j = 0; j < m; j++)
{
scanf("%d", &max[i][j]);
}
}
printf("Enter ALLOCATED matrix:\n");
for(int i = 0; i < n; i++)
{
for(int j = 0; j < m; j++)
{
scanf("%d", &alloc[i][j]);
}
}
printf("Enter initial AVAILABLE values: \n");
for(int i = 0; i < m; i++)
scanf("%d", &avail[i]);
printf("NEED matrix: \n");
for(int i = 0; i < n; i++)
{
for(int j = 0; j < m; j++)
{
need[i][j] = max[i][j] - alloc[i][j];
printf("%d ",need[i][j]);
}
printf("\n");
}
SafeSequence(n, m);
resourceRequest(n, m);
return 0;
}
int SafeSequence(int n, int m)
{
int flag[MAX] = {0};
int work[MAX];
int safeSeq[MAX];
int j,count = 0;
for(int i = 0; i < m; i++)
{
work[i] = avail[i];
}
while(count < n)
{
int found = 0;
for(int i = 0; i < n; i++)
{
if(flag[i] == 0)
{
for(j = 0; j < m; j++)
{
if(need[i][j] > work[j])
break;
}
if(j == m)
{
flag[i] = 1;
for(int k = 0; k < m; k++)
{
work[k] += alloc[i][k];
}
safeSeq[count++] = i;
found = 1;
}
}
}
if(found == 0)
{
printf("\nNo safe sequence exists.\n");
return 0;
}
}
printf("\nSafe sequence: ");
for(int i = 0; i < n; i++)
{
printf("P%d ", safeSeq[i]);
}
printf("\n");
return 1;
}
void resourceRequest(int n, int m)
{
int x, safe;
printf("\nEnter the process which requests for resources: ");
scanf("%d", &x);
printf("Enter resource request: ");
for(int i = 0; i < m; i++)
scanf("%d", &request[i]);
for(int j = 0; j < m; j++)
{
if(request[j] > need[x][j] || request[j] > avail[j])
{
printf("Request cannot be granted safely.\n");
return;
}
}
for(int j = 0; j < m; j++)
{
avail[j] -= request[j];
alloc[x][j] += request[j];
need[x][j] -= request[j];
}
safe = SafeSequence(n, m);
if(safe)
printf("Request can be granted safely.\n");
else
printf("Request cannot be granted safely.\n");
}
