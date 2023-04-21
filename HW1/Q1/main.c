#include <stdio.h>

int main() {
    char filename[100];
    printf("Enter txt file name:\n");   // Get the filename
    scanf("%s", filename);
    FILE *fp;
    fp = fopen (filename, "r");    // open the text file using the filename variable
    if (!fp) {
        printf ("Error opening file\n");    // check for errors
        return 1;
    }

    int count = 1; // variable to count the number of teams
    while(!feof(fp)) { // loop until the end of the file is reached
        char c;
        for (c = getc(fp); c != EOF; c = getc(fp))
            if (c == '\n') // Increment count if the character is newline
                count = count + 1;
    }
    printf("There are %d teams in total.\n", count); // print the number of teams

    fp = fopen(filename, "r");  // Reopen the file, so we can iterate all over again.

    while(!feof(fp)) { // loop until the end of the file is reached
        int team_id, total_points = 0;
        char match_results[100];

        fscanf(fp, "%d %s", &team_id, match_results); // read team id and match results from each line

        for (int j = 0; match_results[j] != '\n' && match_results[j] != '\0'; j++) { // loop until the end of the line or the end of the string is reached
            if (match_results[j] == 'W') {
                total_points += 3;
            } else if (match_results[j] == 'D') {
                total_points += 1;
            }
        }

        printf("Team %d: %d\n", team_id, total_points);
        count++; // increment the number of teams
    }

    fclose(fp);
    return 0;
}