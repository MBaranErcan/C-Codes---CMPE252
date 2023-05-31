#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER 500

typedef struct {
    char name[MAX_NUMBER];
    char surname[MAX_NUMBER];
    double duration;
} Attendee;

int compareAttendees(const void* a, const void* b); // Function to compare the names and surnames of attendees.

int main() {
    char filename[50];
    char scanSort[3];
    Attendee attendee_array[MAX_NUMBER];


    printf("Enter the input file name: ");      // Get the filename.
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");          // Open the file.
    if (file == NULL) {
        printf("Failed to open the file.");
        return 1;
    }
    char header[100];
    fgets(header, sizeof(header), file);    // Read the header line of the file.

    char entry[300];
    int attenderNumber = 0;
    while (fgets(entry, sizeof(entry), file)) {
        char joinTime[20];
        char leaveTime[20];
        double duration;
        char name[100];
        char surname[50];
        char email[100];

        strcpy(joinTime, strtok(entry, ","));
        strcpy(leaveTime, strtok(NULL, ","));
        duration = atof(strtok(NULL, ","));     // Convert str into double using atof.
        strcpy(name, strtok(NULL, ","));

        char *email_str =       strtok(NULL, ",");            // Check whether the email entry is empty or not.
        if (email_str != NULL)  strcpy(email, email_str);   // If not Null, copy its value.
        else                    strcpy(email, "");          // If it is Null, copy empty value.

        int surname_location = -1;              // Integer to store the location of the starting index of the Surname.
        for (int i = 0; name[i] != '\0'; ++i) { // To find the surname, that always is the last word of the name:
            if (name[i] == ' ')                 // Iterate over the name, find the last space char.
                surname_location = i+1;         // Therefore, starting index of the surname is the index on the right of the last space in name.
        }

        strncpy(surname, &name[surname_location], sizeof(surname)-1);   // Set the surname.
        name[surname_location-1] = '\0';                                                  // Reset the name by adding a null character

        // Check if the attendee already has a record or not!
        int new_Attendee = 1;
        for (int i = 0; i < attenderNumber; ++i) {                                        // Iterate over all previous attendees.
            if (strcasecmp(attendee_array[i].name,name) == 0                    // If they both have the same name and surname.
                && strcasecmp(attendee_array[i].surname, surname) == 0) {       // If they are same person,
                attendee_array[i].duration += duration;                                   // add only the duration to the record and do not create new record.
                new_Attendee = 0;
                break;
            }
        }
        if (new_Attendee) {                                     // If it is a new record
            Attendee attendee = {                               // Create  a new Attendee object
                    "", "",duration              // with empty name and surname fields but with correct the duration value.
            };
            strcpy(attendee.name, name);            // Strcpy the name
            strcpy(attendee.surname, surname);      // and the surname to the attendee.

            attendee_array[attenderNumber++] = attendee;        // Add the new attendee to the list.
            }
        }

    int isSorted = 0;
    printf("\nSort the results? (yes/no): ");     // Get the user input indicating whether the answer will be sorted or not.
    scanf("%s", scanSort);
    if (!strcasecmp(scanSort, "yes"))        // If answer is yes, set isSorted to 1.
        isSorted = 1;
    else if (strcasecmp(scanSort, "no")) {   // If the answer is not "yes" or "no", print wrong input and return with error.
        printf("Wrong answer. You have to write \"yes\" or \"no\".");
        return 1;
    }

    printf("\n");   // New line command.
    for (int i = 0; i < attenderNumber; ++i) {
        if (isSorted) {
            qsort(attendee_array, attenderNumber, sizeof(Attendee), compareAttendees);
        }
        printf("%s %s %.2lf\n",attendee_array[i].surname, attendee_array[i].name, attendee_array[i].duration);
    }

    fclose(file);
    return 0;
}

int compareAttendees(const void* a, const void* b) { // Function to compare the names and surnames of attendees.
    const Attendee* attendeeA = (const Attendee*)a;
    const Attendee* attendeeB = (const Attendee*)b;

    int surnameComparison = strcasecmp(attendeeA->surname, attendeeB->surname);// Compare the surnames
    if (surnameComparison != 0)
        return surnameComparison;                       // Return the surname comparison result, if they are not equal.
    return strcmp(attendeeA->name, attendeeB->name);    // If surnames are equal, then compare names.
}