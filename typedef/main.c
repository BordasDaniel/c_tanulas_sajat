#include <stdio.h>


// typedef   existingtype   name
typedef int Number; // Not recommended! Stick to int!!
typedef char String[50]; // Fixed to 50 bytes
typedef char* string; // Recommended with pointers
typedef char Initials[2]; // 2 characters + nullterminator

// Typedef is used to create an existing datatype a new nickname. It helps simplyfy complex types and improves readabilty.

int main()
{

    Number x = 10; // its the same as int x = 10;
    printf("%d\n", x);

    string name = "Hello World";
    printf("%s\n", name);

    Initials user = "PS";
    Initials user1 = "SS";
    Initials user2 = "BC";
    Initials user3 = "ST";

    printf("%s\n", user);

    return 0;

}