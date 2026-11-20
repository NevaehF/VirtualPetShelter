// Assignment OO Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Nevaeh Fernandez 
// Week 14
// Main Code File

/*  
	            	==      Concept Explination               == 
		    My concept for this app was to simulate a pet adoption shelter with
            an interactive UX. The user will have the ability to adopt, view and 
            even interact with differtn pets within the program. 
         My code will include 2 classes, 8 Attributes, 7 Methods, a main file and an .h file
        
                            Features Include: 
        User has freedom to choose a pet they'd like to adopt 
        Pet is removed from the list after adoption
        USer has interaction with pet (feedling, playing, etc)

		
*/


#include <iostream>
#include <vector>
#include "PetAdoptionShelter.h"  // Include header file for Pet and Adopter classes

using namespace std;

// Function to display the main menu
void displayMenu() {
    cout << "\n== Virtual Pet Adoption Shelter == \n";
    cout << "1. View our available pets\n";
    cout << "2. Adopt a pet\n";
    cout << "3. View adopted pets\n";
    cout << "4. Interact with adopted pets (Feed/Play)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() // Our Main Function 
    {
    // Create an Adopter object
    Adopter adopter("La'Landra Hurn", 42);  // Our default adopter

    // Create 10 Pet objects and store them in a vector
    vector<Pet> pets = {
        Pet("Xena", "Dog", 16, "Mutt"),
        Pet("Toru", "Bearded Dragon", 4, "Leatherback"),
        Pet("TenTen", "Hampster", 1, "Syrian"),
        Pet("Max", "Dog", 10, "Shitzu"),
        Pet("Frankie", "Fish", 1, "Beta"),
        Pet("Nina", "Cat", 3, "Orange Tabby"),
        Pet("Honey", "Dog", 1/2, "German Sheperd"),
        Pet("Simba", "Cat", 3, "Bengal"),
        Pet("Watermelon", "Fish", 1, "Suckerfish"),
        Pet("Milo", "Cat", 5, "British Shorthair")
    };

    int choice;  // Variable to store the user's choice

    // Main loop to run the program until the user chooses to exit
    while (true) {
        displayMenu();  // Show the menu options
        cin >> choice;  // Get user input

        switch (choice) {
        case 1:
            // Choice 1: View available pets
            for (const auto& pet : pets) {
                if (!pet.isAdopted) {
                    pet.getInfo();  // Display pet info only if it's not adopted
                }
            }
            break;

        case 2: {
            // Choice 2: Adopt a pet
            cout << "Enter the name of the pet you'd like to adopt: ";
            string petName;
            cin >> petName;

            bool found = false;  // This will flag to check if the pet was found

            // You can search for the pet by name
            for (auto& pet : pets) {
                if (pet.getName() == petName && !pet.isAdopted) {
                    adopter.adoptPet(pet);  // Adopter adopts the pet
                    pet.adopt();  // Mark the pet as adopted
                    found = true;
                    break;
                }
            }

            if (!found) {
                // Pet not found or already adopted
                cout << "Pet not found or already adopted.\n";
            }
            break;
        }

        case 3:
            // Choice 3: View adopted pets
            adopter.viewAdoptedPets();
            break;

        case 4:
            // Choice 4: Interact with adopted pets
            adopter.interactWithPet();
            break;

        case 5:
            // Choice 5 : Exit the program
            cout << "Thank you for using the Virtual Pet Adoption Center!\n";
            return 0;  // Exit the program

        default:
            // This handles the invalid menu options
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;  // End of program
}
