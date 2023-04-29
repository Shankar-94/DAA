#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100
#define MAX_PERSONS 100

int n, m; // n = number of persons, m = number of jobs
int cost[MAX_PERSONS][MAX_JOBS]; // cost matrix
int assignments[MAX_PERSONS]; // array to store job assignments
int min_cost = 99999999; // variable to store minimum cost

// Function to check if a job is assigned to a person
int isAssigned(int job, int person, int *assignments) {
    int i;

    for (i = 0; i < person; i++) {
        if (assignments[i] == job)
            return 1;
    }

    return 0;
}

// Recursive function to find all possible job assignments
void findJobAssignments(int person, int total_cost, int *assignments) {
    int job;

    if (person == n) { // all persons have been assigned jobs
        if (total_cost < min_cost) { // update minimum cost
            min_cost = total_cost;
            int i;
            for (i = 0; i < n; i++)
                assignments[i] = assignments[i];
        }
        return;
    }

    for (job = 0; job < m; job++) {
        if (!isAssigned(job, person, assignments)) {
            assignments[person] = job;
            findJobAssignments(person + 1, total_cost + cost[person][job], assignments);
        }
    }
}

int main() {
    printf("Enter the number of persons and jobs: ");
    scanf("%d%d", &n, &m);

    int i, j;
    printf("Enter the cost matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize assignments array
    for (i = 0; i < n; i++)
        assignments[i] = -1;

    // Find all possible job assignments
    findJobAssignments(0, 0, assignments);

    // Print minimum cost and job assignments
    printf("Optimal cost: %d\n", min_cost);
    printf("Optimal job assignments: \n");
    for (i = 0; i < n; i++)
        printf("person %d: job %d\n", i + 1, assignments[i] + 1);

    return 0;
}
