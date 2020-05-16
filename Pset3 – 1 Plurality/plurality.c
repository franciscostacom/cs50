#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates

const int MAX = 9;

// -----------------------------------
// Candidates have name and vote count

typedef struct
{
    string name;
    int votes;
}
candidate;

// -------------------
// Array of candidates

candidate candidates[MAX];

// --------------------
// Number of candidates

int candidate_count;

// -------------------
// Function prototypes

bool vote(string name);

void print_winner(void);

// ----
// Main

int main(int argc, string argv[])
{
    // Check for invalid usage

    if (argc < 2) // If smaller than 2 (there's gotta be at least one)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Assign canditate count

    candidate_count = argc - 1; // number of entries minus 0, which is .plurality

    // If its too big, reject!

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Populate array of candidates

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; // +1 because 0 is ./plurality itself
        candidates[i].votes = 0; // Setting vote count to zero
    }

    // Number of people voting

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        vote(name);

        if (vote(name) == false)
        {
            printf("Invalid vote.\n");
        }

    }

    // Display winner of election

    print_winner();
}

// Update vote totals given a new vote

bool vote(string name)
{

    int a;

    for (a = 0; a < candidate_count; a++)
    {
        if (strcmp(name, candidates[a].name) == 0)
        {
            candidates[a].votes++;
            return true;
        }
    }

    return false;

}

// Print the winner (or winners) of the election

void print_winner(void)
{

    int highest_vote = 0;

    for (int b = 0; b < candidate_count; b++)
    {
        if (candidates[b].votes > highest_vote)
        {
            highest_vote = candidates[b].votes;
        }
    }

    for (int c = 0; c < candidate_count; c++)
    {
        if (highest_vote == candidates[c].votes)
            printf("%s\n", candidates[c].name);
    }


    return;

}

