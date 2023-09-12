#include <stdio.h>
#include <string.h>

// Define a struct to represent a person
struct Person {
    char name[50];
    int age;
};

// Define a union to represent a person's contact information
union ContactInfo {
    char email[50];
    char phone[15];
};

int main() {
    // Create an instance of the struct
    struct Person person;
    
    // Initialize the struct
    strcpy(person.name, "John");
    person.age = 30;

    // Access and print struct members
    printf("Person's name: %s\n", person.name);
    printf("Person's age: %d\n", person.age);

    // Create an instance of the union
    union ContactInfo contact;
    
    // Initialize the union's email member
    strcpy(contact.email, "john@example.com");

    // Access and print the union's email member
    printf("Contact Email: %s\n", contact.email);

    // Now, change the union's phone member
    strcpy(contact.phone, "123-456-7890");

    // Access and print the union's phone member
    printf("Contact Phone: %s\n", contact.phone);

    // The size of the struct and union
    printf("Size of struct Person: %lu bytes\n", sizeof(struct Person));
    printf("Size of union ContactInfo: %lu bytes\n", sizeof(union ContactInfo));

    return 0;
}

/* Result:

Person's name: John
Person's age: 30
Contact Email: john@example.com
Contact Phone: 123-456-7890
Size of struct Person: 56 bytes
Size of union ContactInfo: 50 bytes

*/

/* a struct allocates memory for all of its members simultaneously, whereas a union shares memory among its members, allowing only one member to be valid at a time. */
