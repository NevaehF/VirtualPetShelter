#ifndef PETADOPTIONSHELTER_H
#define PETADOPTIONSHELTER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Pet class to represent each adoptable pet and the basic facts about them. 
class Pet {
private:
    string name;      // The Pet's name
    string species;   // The Pet's species (Reptile, Dog, Cat, etc)
    int age;          // The Pet's age
    string breed;     // Pet's breed

public:
    bool isAdopted;  // Public to track adoption status (true if adopted)

    // This constructor is needed to initialize Pets attributes
    Pet(string petName, string petSpecies, int petAge, string petBreed)
        : name(petName), species(petSpecies), age(petAge), breed(petBreed), isAdopted(false) {}

    // Getter for the pet's name
    string getName() const {
        return name;
    }

    // Method to display pet's info
    void getInfo() const {
        cout << "Name: " << name << ", Species: " << species << ", Age: " << age << ", Breed: " << breed << endl;
    }

    // This method is going to be used to mark the pet as adopted
    void adopt() {
        isAdopted = true;
        cout << name << " has been adopted!\n";
    }

    // This method will be used to simulate feeding the pet (Greater UX) 
    void feed() {
        cout << "You feed " << name << ". " << name << " is happy!\n";
    }

    // This method is used to simulate playing with the pet (Greater UX)
    void play() {
        cout << "You play with " << name << ". " << name << " is excited!\n";
    }
};

// Adopter class -  to represent the people adopting the pets
class Adopter {
private:
    string name;      // The Adopter's name
    int age;          // The Adopter's age
    vector<Pet> adoptedPets;  // A list of the adopted pets

public:
    // Constructor to initialize Adopter attributes
    Adopter(string adopterName, int adopterAge)
        : name(adopterName), age(adopterAge) {}

    // Method to adopt a pet
    void adoptPet(Pet& pet) {
        adoptedPets.push_back(pet);  // Add pet to adopted list
        cout << "You have adopted " << pet.getName() << "!\n";
    }

    // Method to view all adopted pets
    void viewAdoptedPets() const {
        if (adoptedPets.empty()) {
            cout << "You have not adopted any pets yet.\n";
        }
        else {
            cout << "Adopted Pets:\n";
            for (const auto& pet : adoptedPets) {
                pet.getInfo();  // This is going to display the info for each adopted pet
            }
        }
    }

    // This Method is used to interact with a specific adopted pet (Feed/Play)
    void interactWithPet() {
        if (adoptedPets.empty()) {
            cout << "You have no pets to interact with.\n";
            return;
        }

        cout << "Enter the name of the pet you want to interact with: ";
        string petName;
        cin >> petName;

        bool found = false;  // Flag to check if the pet was found

        // Search for the pet by name
        for (auto& pet : adoptedPets) {
            if (pet.getName() == petName) {
                found = true;
                cout << "Do you want to (1) Feed or (2) Play with " << pet.getName() << "? Enter choice: ";
                int action;
                cin >> action;
                if (action == 1) {
                    pet.feed();  // Feed the pet
                }
                else if (action == 2) {
                    pet.play();  // Play with the pet
                }
                else {
                    cout << "Invalid action.\n";
                }
                break;
            }
        }

        if (!found) {
            // Pet not found in the adopted list
            cout << "Pet not found in your adopted list.\n";
        }
    }
};

#endif // PETADOPTIONCENTER_H
