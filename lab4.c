#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 10
void dijkstra(int a[MAX_VERTICES][MAX_VERTICES], int s, int n, int d[], int p[], int
visited[]) {
int u, v, i, j, min;
for (v = 0; v < n; v++) {
d[v] = INT_MAX;
p[v] = -1;
visited[v] = 0;
}
d[s] = 0;
for (i = 0; i < n; i++) {
min = INT_MAX;
for (j = 0; j < n; j++) {
if (d[j] < min && visited[j] == 0) { 
min = d[j];
u = j;
}
}
visited[u] = 1;
for (v = 0; v < n; v++) 
{if ((d[u] + a[u][v] < d[v]) && (u != v) && visited[v] == 0) {
d[v] = d[u] + a[u][v];
p[v] = u;
}
}
}
}
void path(int v, int s, int p[]) {
if (p[v] != -1)
path(p[v], s, p);
if (v != s)
printf("->%d", v);
}
void display(int s, int n, int d[], int p[]) {
int i;
for (i = 0; i < n; i++) {
if (i != s) {
printf("%d ", s);
path(i, s, p);
if (i != s)
printf("=%d\n", d[i]);
printf("\n");
}
}
}
int main() {
int a[MAX_VERTICES][MAX_VERTICES];
int d[MAX_VERTICES], p[MAX_VERTICES], visited[MAX_VERTICES];
int i, j, n, s;
printf("Enter the number of vertices: ");
scanf("%d", &n);
printf("Enter the weighted matrix:\n");
for (i = 0; i < n; i++) {
for (j = 0; j < n; j++) {
scanf("%d", &a[i][j]);
}
}
printf("Enter the source vertex: ");
scanf("%d", &s);
dijkstra(a, s, n, d, p, visited);
printf("The shortest path from source %d to remaining vertices:\n", s);
display(s, n, d, p);
return 0;
}
