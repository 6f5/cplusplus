//==========================================================
//
// Description:
//   This C++ console application demonstrates a checkout
// lane using a linked list. This application requires
// three files.
//   -This file
//   -Customer.h
//   -Customer.cpp
//
//==========================================================

#include <iostream> // For formatted output
#include <string> // For string data type
#include <cstdlib> // For general purpose functions
#include <iomanip> // to manipulate io stream

#include "Customer.h"

// So "std::cout" may be abbreviated to "cout"
using namespace std;

// Globals
const int COLFMT2 = 20;
Customer *head = NULL;
Customer *tail = NULL;
int listSize = 0;


// Function prototypes
int menuOption();
void addNode(Customer *ptr, int i);
bool deleteNode(int i);
void clearQueue();
void printQueue();
void runSimulation(int cycles);
void setSimulationCycles(int &cycles);
int random(int lower, int upper);
void unitTest();

// Static field initializations

int main() {

  // Declare local variables
  int option;
  int cycles = 10;

  // Seed the number generator with current time
  srand(time(0));

  // Show application header
  cout << "Welcome to the Checkered Checkouts" << endl;
  cout << "----------------------------------" << endl;


  // Loop to process menu options
  option = menuOption();
  while (option != 0) {
    // Test which option selected
    switch (option) {
      case 1: {
        // set simulation cycles
        setSimulationCycles(cycles);
        break;
      }
      case 2: {
        // run simulation
        runSimulation(cycles);
        break;
      }
      case 3: {
        // Print list
        printQueue();
        break;
      }
      case 4: {
        // clear list
        clearQueue();
        break;
      }
      default:
        cout << "Error: unknown option of " << option
             << "." << endl;
    }

    // get next option
    option = menuOption();
  }

  // Print exit message
  cout << "End of Checkered Checkouts" << endl;
  return 0;
}


// Functions implementations

/*
 * Displays menu and returns selected option.
 * @return selected option
 */
int menuOption() {
  // Declare local variables
  int option;

  // Display menu
  cout << "\nCheckered Checkouts Menu" << endl;
  cout << "1. Set simulation cycles" << endl;
  cout << "2. Run simulation" << endl;
  cout << "3. Print list" << endl;
  cout << "4. Clear list" << endl;
  cout << "0. Exit" << endl;
  cout << "Enter an option: ";
  cin >> option;

  // return option
  return option;
}

/*
 * Sets the number of simulation cycles
 * @param cycles, reference to the cycles variable
 */
void setSimulationCycles(int &cycles) {
  bool validInput = false;
  bool showError = false;
  while (!validInput) {
    if (showError) {
      cout << "\nThe number of simulations must be "
           << "between 1 and 2000" << endl;
    }

    cout << "\nEnter the number of simulation "
         << "cycles (1-2000): ";
    cin >> cycles;

    if (cycles > 1 && cycles <= 2000) {
      validInput = true;
    } else {
      showError = true;
    }
  }

  cout << "Simulation cycles is set to " << cycles
       << "." << endl;
}

/*
 * Runs a simulation with a given number of times,
 * simulating customer checkouts.
 * @param cycles, the number of times to simulate
 * customer checkouts
 */
void runSimulation(int cycles) {
  // Declare variables/constants
  static int id = 1;
  const int ITEMS_MIN = 1;
  const int ITEMS_MAX = 200;
  const int COST_MIN = 100;
  const int COST_MAX = 1000;
  const int ACTION_MIN = 1;
  const int ACTION_MAX = 3;
  int i = 0; // counter
  int items = 0;
  int cost = 0;
  Customer *ptr = NULL;
  int action = 0;

  // Loop for n (cycles) times
  while (i < cycles) {
    // Generate random values
    items = random(ITEMS_MIN, ITEMS_MAX);
    cost = random(COST_MIN, COST_MAX);
    action = random(ACTION_MIN, ACTION_MAX);

    // test action
    if (action <= 2) {
      // Create new customer
      ptr = new Customer(id, items, cost);

      // Add new customer to end of list
      addNode(ptr, i);

      // Increment counter and id
      i++;
      id++;

    } else {
      // Remove customer from front of list
      if (deleteNode(i)) {

        // Increment counter
        i++;
      }
    }
  }

}


/*
 * Adds a customer to the end of the list.
 * @param ptr, a pointer to the new customer
 * object.
 */
void addNode(Customer *ptr, int i) {

  // Possible states
  // tail = empty
  // tail = hasNext
  // Check if tail is empty (NULL)
  if (!tail) {
    // Set head and tail to point
    // to the same customer
    head = ptr;
    tail = ptr;
  } else {
    // Add customer to end of list
    tail->setNext(ptr);

    // set tail to point to new customer
    tail = ptr;
  }

  // Update list size
  listSize += 1;

  // Print message
  cout << "\nNode added to back of list: "
       << "[" << ptr->getItems() << ", "
       << ptr->getCost() << "]" << endl;
  cout << "[" << (i + 1) << "] Customer "
  << ptr->getId()
       << " entered checkout lane." << endl;
}

/*
 * Removes a customer from front of list.
 */
bool deleteNode(int i) {
  // Declare variables
  Customer *ptr = NULL;

  // Possible States
  // head = empty
  // head = hasNext

  // Check if head is empty
  if(!head){
    // Print message
    cout << "\nThe list is empty. There"
         << " is no customer to delete." << endl;
    return false;
  }

  // Check if head has next node
  if(head->getNext()){
    // Print message
    cout << "\nNode deleted from front of list: "
         << "[" << head->getItems() << ", "
         << head->getCost() << "]" << endl;
    cout << "[" << (i + 1) << "] Customer "
         << head->getId()
         << " left checkout lane." << endl;

    // Remove first node and move
    // second node to the front
    ptr = head->getNext();
    delete head;
    head = ptr;
    ptr = NULL;

    // Update list size
    listSize -= 1;

    return true;
  }

  // This will run only if
  // there's only one node left
  if(head){

    // Print message
    cout << "\nNode deleted from front of list: "
         << "[" << head->getItems() << ", "
         << head->getCost() << "]" << endl;
    cout << "[" << (i + 1) << "] Customer "
         << head->getId()
         << " left checkout lane." << endl;

    delete head;
    head = NULL;
    tail = NULL;

    // Update list size
    listSize -= 1;

    return true;
  }


  return false;
}


/*
 * Clears a list and initializes the list
 * pointers.
 */
void clearQueue() {
  // Declare variables
  Customer *ptr = NULL;

  // Loop to delete nodes
  ptr = head;
  while (ptr != NULL) {
    head = ptr->getNext();
    delete ptr;
    ptr = head;
  }

  // Initialize list pointers
  head = NULL;
  tail = NULL;


  // Print clear message and update list size
  listSize = 0;
  cout << "\nList cleared." << endl;
  cout << "List size: " << listSize << endl;
}

/*
 * Prints customers data in the linked list,
 * total items, total cost, and list size.
 */
void printQueue() {
  cout << endl;
  cout << "Current Checkout Lane" << endl;
  cout << setw(COLFMT2) << left << "ID"
       << setw(COLFMT2) << right << "Items"
       << setw(COLFMT2) << right << "Item Cost ($)"
       << endl;
  Customer *ptr = head;
  int totalItems = 0;
  double totalCost = 0.0;
  string tmp;
  while (ptr != NULL) {

    if (ptr == head) {
      tmp = to_string(ptr->getId());
      tmp += " (head)";
      cout << setw(COLFMT2) << left << tmp
           << setw(COLFMT2) << right << ptr->getItems()
           << setw(COLFMT2) << right << ptr->getCost()
           << endl;
    } else if (ptr == tail) {
      tmp = to_string(ptr->getId());
      tmp += " (tail)";
      cout << setw(COLFMT2) << left << tmp
           << setw(COLFMT2) << right << ptr->getItems()
           << setw(COLFMT2) << right << ptr->getCost()
           << endl;
    } else {
      cout << setw(COLFMT2) << left << ptr->getId()
           << setw(COLFMT2) << right << ptr->getItems()
           << setw(COLFMT2) << right << ptr->getCost()
           << endl;
    }

    totalItems += ptr->getItems();
    totalCost += ptr->getCost();

    // set next node into ptr
    ptr = ptr->getNext();
  }

  cout << "List size: " << listSize << endl;

  cout << fixed << setprecision(2);
  cout << setw(COLFMT2 + 2) << left << "\nTotal items: "
       << setw(COLFMT2) << right << totalItems << endl;
  cout << setw(COLFMT2) << left << "Total item cost ($): "
       << setw(COLFMT2) << right << totalCost << endl;

}

/*
 * Generates a number between the given lower
 * and upper bounds.
 * @param lower, the lower bound
 * @param upper, the upper bound
 */
int random(int lower, int upper) {
  return (rand() % (upper - lower + 1) + lower);
}
