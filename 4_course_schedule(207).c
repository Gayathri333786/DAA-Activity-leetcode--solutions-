#include <stdio.h>
#include <stdbool.h>

bool dfs(int node, int graph[100][100], int visited[], int recStack[], int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < n; i++) {
        if(graph[node][i]) {
            if(!visited[i] && dfs(i, graph, visited, recStack, n))
                return true;
            else if(recStack[i])
                return true;
        }
    }

    recStack[node] = 0;
    return false;
}

bool canFinish(int numCourses, int graph[100][100]) {
    int visited[100] = {0};
    int recStack[100] = {0};

    for(int i = 0; i < numCourses; i++) {
        if(!visited[i]) {
            if(dfs(i, graph, visited, recStack, numCourses))
                return false;
        }
    }
    return true;
}
