#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int id; // actor id
    char name[20]; // actor name
	char surname[20]; // actor surname
    char major[20]; // major of actor
    int repIndex; // reputation index of the actor
} actor;

void showRecords(FILE *filePtr);

int modifyRepIndex(FILE *filePtr, unsigned int id, int decreaseRep);
int insertActor(FILE *filePtr, unsigned int id, char name[], char surname[], char major[], int repIndex);
int removeActor(FILE *filePtr, unsigned int id);
int viewMajorReps(FILE *filePtr, char major[], int minRep);

int main()
{
    unsigned int id;
    int decreaseRep;
    int status;

    char name[20];
    char surname[20];
	char major[20];
    int repIndex;

    int count;
	int minReputation;

    FILE *filePtr;
    filePtr = fopen("actor.bin","rb+");
    if (filePtr == NULL)
    {
        printf("Could not open actor.bin");
        return 1; // It was "return;" I changed it to "return 1;"
    }

    showRecords(filePtr);

    int choice;

    printf("\nWhich operation do you choose?\n");
    printf("1 : Update Reputation Index\n");
    printf("2 : Add Actor\n");
    printf("3 : Delete Actor\n");
    printf("4 : View Major Info with Reputation\n");
    printf("> ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("\nActor id: ");
        scanf("%d",&id);
        printf("Decrease value for reputation index: ");
        scanf("%d",&decreaseRep);
        status = modifyRepIndex(filePtr, id, decreaseRep);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No actor with id %d\n", id);
        break;
    case 2:
        printf("\nActor id: ");
        scanf("%d",&id);
        printf("Name: ");
        scanf("%s",name);
		printf("Surname: ");
        scanf("%s",surname);
        printf("Major: ");
        scanf("%s",major);
        printf("Reputation Index: ");
        scanf("%d",&repIndex);
        status = insertActor(filePtr, id, name, surname, major, repIndex);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("There is already an actor with id %d\n", id);
        break;
    case 3:
        printf("\nActor id: ");
        scanf("%d",&id);
        status = removeActor(filePtr, id);
        if (status == 1)
            showRecords(filePtr);
        else
            printf("No actor with id %d\n", id);
        break;
    case 4:
        printf("\nMajor: ");
        scanf("%s",major);
		printf("\nMin reputation Index: ");
        scanf("%d", &minReputation);    // I added "&" before the minReputation or else I was getting the wrong answer.
        count = viewMajorReps(filePtr, major, minReputation);
        if (count == 0)
            printf("No actor in major %s with reputation index <= %d\n", major, minReputation);
        else
            printf("There are %d actors in major %s with reputation index <= %d\n", count, major, minReputation);
        break;
    }

    fclose(filePtr);
    return 0;
}

void showRecords(FILE *filePtr)
{
    fseek(filePtr, 0, SEEK_SET);

    printf("\n%-3s %-20s %-20s %-20s %s\n",
                   "ID",
                   "Name",
				   "Surname",
                   "Major",
                   "Reputation Index");

    while (!feof(filePtr))
    {
        actor a;
        int result = fread(&a, sizeof(actor), 1, filePtr);
        if (result != 0 && a.id != 0)
        {
            printf("%-3d %-20s %-20s %-20s %d\n",
                   a.id,
                   a.name,
				   a.surname,
                   a.major,
                   a.repIndex);
        }
    }
}

int modifyRepIndex(FILE *filePtr, unsigned int id, int increaseCit) // Instead of decreaseRep we have given increaseCit, but it does not affect the method.
{
    fseek(filePtr, (id-1)* sizeof(actor), SEEK_SET); // Carry the file pointer to the position of the starting index of the actor.

    actor a;    // Actor object to make operations.
    int result; // Int result to check if the fread was successful.
    result = fread(&a, sizeof(actor), 1, filePtr);  // Read the actor object from bin file to Actor a.

    if (result != 0 && a.id != 0) { // If the result or actor.id is not zero:
        a.repIndex -= increaseCit;  // Decrease the rep value of the actor a.
        fseek(filePtr, (-1)* sizeof(actor), SEEK_CUR);  // Carry the pointer position back to the beginning of the actor record.
        fwrite(&a, sizeof(actor), 1, filePtr);  // Then write the Actor a's new rep value to the file.
        return 1;   // If successful, return 1,
    } else return 0;// Else return 0.
}

int insertActor(FILE *filePtr, unsigned int id, char name[], char surname[], char major[], int repIndex)
{
    fseek(filePtr, (id-1)*sizeof(actor), SEEK_SET); // Carry the file pointer to the position of the starting index of the actor.

    actor a;    // Actor object to make operations.
    int result; // Int result to check if the fread was successful.
    result = fread(&a, sizeof(actor), 1, filePtr);  // Read the actor object from bin file to Actor a.

    if (result != 0 && a.id == 0) { // If the result is not zero and the record is new (id == 0).
        a.id = id;                               // Actor's id.
        strcpy(a.name, name);       // Actor's name.
        strcpy(a.surname, surname); // Actor's surname.
        strcpy(a.major, major);     // Actor's major.
        a.repIndex = repIndex;                  // Actor's rep value.
        fseek(filePtr, (-1)* sizeof(actor), SEEK_CUR); // Carry the pointer position back to the beginning of the actor record.
        fwrite(&a, sizeof(actor), 1, filePtr);      // Write the Actor a's new values to the file.
        return 1;   // If successful, return 1,
    } else return 0;// Else return 0.
}

int removeActor(FILE *filePtr, unsigned int id)
{
    fseek(filePtr, (id-1)*sizeof(actor), SEEK_SET); // Carry the file pointer to the position of the starting index of the actor.

    actor a;    // Actor object to make operations.
    int result; // Int result to check if the fread was successful.
    result = fread(&a, sizeof(actor), 1, filePtr);  // Read the actor object from bin file to Actor a.

    if (result != 0 && a.id != 0) { // If the result or actor.id is not zero:
        a.id = 0;                            // Set the actor's id to zero.
        strcpy(a.name, "");     // Set the actor's name to empty value.
        strcpy(a.surname, "");  // Set the actor's name to empty value.
        strcpy(a.major, "");    // Set the actor's name to empty value.
        a.repIndex = 0;                     // Set the actor's id to zero.
        fseek(filePtr, (-1)* sizeof(actor), SEEK_CUR); // Carry the pointer position back to the beginning of the actor record.
        fwrite(&a, sizeof(actor), 1, filePtr);      // Write the Actor a's new values to the file.
        return 1;   // If successful, return 1
    } else return 0;// Else return 0.
}

int viewMajorReps(FILE *filePtr, char major[], int maxCit) // maxCity = minRep
{
    fseek(filePtr, 0, SEEK_SET); // Carry the file pointer to the position of the starting index of the actor.

    int count = 0; // Integer to return the count of available actors.
    printf("\n%-3s %-20s %-20s %-20s %s\n", // Print the header.
           "ID",
           "Name",
           "Surname",
           "Major",
           "Reputation Index");

    while (!feof(filePtr)) {
        actor a;    // Actor object to make operations.
        int result; // Int result to check if the fread was successful.
        result = fread(&a, sizeof(actor), 1, filePtr);  // Read the actor object from bin file to Actor a.

        if (result != 0 && a.id != 0 && strcmp(a.major, major) == 0 && a.repIndex >= maxCit) { // If the result or actor.id is not zero, and major and the min. Rep values are valid:
            count++;    // Increment the count by one if found.
            printf("%-3d %-20s %-20s %-20s %d\n",   // Print the actor's information.
                   a.id,
                   a.name,
                   a.surname,
                   a.major,
                   a.repIndex);
        }
    }
    return count;    // Return the count of the actors.
}
