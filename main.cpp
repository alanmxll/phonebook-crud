#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int choice, onChoiced, wantedPosition, positionsFilled = 0;

struct Contact {
  char name[50];
  char phone[11];
  char company[30];
};

struct Contact Phonebook[10];

/************ START - METHODS OF A CRUD ************/
void getContact() {
  cout << "========== PHONEBOOK ==========" << endl << endl;
  for(int position = 0; position < 10; position++) {
    cout << "\nContact " << (position + 1) << endl;
    cout << "\nName: " << Phonebook[position].name << endl;
    cout << "Phone: " << Phonebook[position].phone << endl;
    cout << "Company: " << Phonebook[position].company << endl; 
  }
}

void postContact(int wantedPosition, char self_name[20], char self_phone[11], char self_company[30]) {
    strcpy(Phonebook[wantedPosition - 1].name, self_name);
    strcpy(Phonebook[wantedPosition - 1].phone, self_phone);
    strcpy(Phonebook[wantedPosition - 1].company, self_company);
}

void updateContact(int wantedPosition, char self_name[20], char self_phone[11], char self_company[30]) {
    strcpy(Phonebook[wantedPosition - 1].name, self_name);
    strcpy(Phonebook[wantedPosition - 1].phone, self_phone);
    strcpy(Phonebook[wantedPosition - 1].company, self_company);
}

void deleteContact(int self_position) {
  strcpy(Phonebook[wantedPosition - 1].name, "");
  strcpy(Phonebook[wantedPosition - 1].phone, "");
  strcpy(Phonebook[wantedPosition - 1].company, "");
}
/************ END - METHODS OF A CRUD ************/

/*********** START - MENU OPTIONS ************/
void menu() {
  cout << "Choose an option"<< endl;
  cout << "1 - Create" << endl << "2 - Read" << endl << "3 - Update" << endl << "4 - Delete" << endl << "0 - Exit" << endl;
  cout << "Choice: ";
  cin >> choice;
}

void onChoicedMenu() {
  cout << "\nPress a number to back" << endl << "0 to Exit" << endl << "Choice: ";
  cin >> onChoiced;
}

void exit() {
  cout << "\n========== PHONEBOOK CLOSED ==========" << endl;
  exit(0);
}
/*********** END - MENU OPTIONS ************/

int main() {
  cout << "========== PHONEBOOK ==========" << endl << endl;
  menu();

  char name[20], phone[11], company[30];
  switch(choice) {
    case 1: system("clear");
    int choice;
    cout << "========== Form Register ==========" << endl;
    cout << "\nChoose the position where you want input the contact: ";
    cin >> wantedPosition;
    if (wantedPosition > 0 & wantedPosition <= 10) {
      if (strlen(Phonebook[wantedPosition - 1].name) > 0) {
        cout << "Position already occupied, choose UPDATE if you want to change the contact\n";
        cout << "1 - Menu" << endl << "0 - EXIT" << endl;
        cout << "choice: ";
        cin >> choice;
        switch(choice) {
          case 0: exit();
          case 1: system("clear");
          main();
          break;
          default: cout << "Invalid Option" << endl;
          break;
        }
      } else {
        cout << "Name: ";
        cin >> name;
        cout << "Phone: ";
        cin >> phone;
        cout << "Company: ";
        cin >> company;
        postContact(wantedPosition, name, phone, company);
        system("clear");
        cout << "CONTACT CREATED!" << endl;
        main();
      }
    } else {
      system("clear");
      cout << "Phonebook haven't this position, choose between 1 and 10." << endl;
      main();
  }
    break;
    case 2: system("clear");
    getContact();
    onChoicedMenu();
    break;
    case 3: system("clear");
    cout << "========== Form Updater ==========" << endl;
    cout << "\nChoose the position where you want update the contact: ";
    cin >> wantedPosition;
    if (strlen(Phonebook[wantedPosition - 1].name) == 0) {
      system("clear");
      cout << "\nPosition already is empty!" << endl;
      main();
    } else {
      cout << "Name: ";
      cin >> name;
      cout << "Phone: ";
      cin >> phone;
      cout << "Company: ";
      cin >> company;
      updateContact(wantedPosition, name, phone, company);
      system("clear");
      cout << "CONTACT UPDATED!" << endl;
      main();
      break;
    }
    case 4: system("clear");
    getContact();
    cout << "\nType the position what you want delete: ";
    cin >> wantedPosition;
    if (strlen(Phonebook[wantedPosition - 1].name) == 0) {
      system("clear");
      cout << "\nPosition already is empty!" << endl;
      main();
    } else {
      deleteContact(wantedPosition);
      system("clear");
      cout << "CONTACT DELETED!" << endl;
      main();
      break;
    }
    case 0: exit();
    break;
    default: system("clear");
    cout << "INVALID OPTION" << endl;
    main();
    break;
  }

  switch(onChoiced) {
    case 0: exit();
    break;
    case 1: system("clear");
    main();
    break;
    case 2: system("clear");
    main();
    break;
    case 3: system("clear");
    main();
    break;
    case 4: system("clear");
    main();
    break;
    case 5: system("clear");
    main();
    break;
    case 6: system("clear");
    main();
    break;
    case 7: system("clear");
    main();
    break;
    case 8: system("clear");
    main();
    break;
    case 9: system("clear");
    main();
    break;
  }
}
