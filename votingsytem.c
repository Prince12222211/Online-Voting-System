#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char name[50];
    char id[10];
    int voted;
};

struct Election {
    char title[50];
    struct Candidate candidates[10];
    int numCandidates;
    struct Voter voters[100];
    int numVoters;
};

void createElection(struct Election *e) {
    printf("Enter the title of the election: ");
    scanf("%s", e->title);

    printf("Enter the number of candidates: ");
    scanf("%d", &e->numCandidates);

     for (int i = 0; i < e->numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", e->candidates[i].name);
        e->candidates[i].votes = 0;
    }

    e->numVoters = 0;
}

void addVoter(struct Election *e) {
    printf("Enter the name of the voter: ");
    scanf("%s", e->voters[e->numVoters].name);

    printf("Enter the ID of the voter: ");
    scanf("%s", e->voters[e->numVoters].id);

    e->voters[e->numVoters].voted = 0;

    e->numVoters++;
}

void castVote(struct Election *e) {
    char id[10];
    int index = -1;

    printf("Enter your ID: ");
    scanf("%s", id);

    for (int i = 0; i < e->numVoters; i++) {
        if (strcmp(id, e->voters[i].id) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Invalid ID.\n");
        return;
    }

    if (e->voters[index].voted == 1) {
        printf("You have already cast your vote.\n");
        return;
    }

    printf("Candidates:\n");

    for (int i = 0; i < e->numCandidates; i++) {
        printf("%d. %s\n", i+1, e->candidates[i].name);
    }

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > e->numCandidates) {
        printf("Invalid choice.\n");
        return;
    }

    e->candidates[choice-1].votes++;
    e->voters[index].voted = 1;

    printf("Vote cast successfully.\n");
}

void displayResults(struct Election *e) {
    printf("Election Title: %s\n", e->title);

    for (int i = 0; i < e->numCandidates; i++) {
        printf("%s: %d\n", e->candidates[i].name, e->candidates[i].votes);
    }
}

int main() {
    struct Election e;
    createElection(&e);

    int choice;

    do {
        printf("\n1. Add voter\n");
        printf("2. Cast vote\n");
        printf("3. Display results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        }
        