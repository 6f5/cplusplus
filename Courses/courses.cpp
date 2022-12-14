#include <iostream>
#include <string.h>

//==========================================================
//
// Title: Courses
// Course: CSC 2110
// Homework: Homework 1
// Author: Abdulla Saeed
// Date: 9/15/2021
// Description:
// A console application to create courses objects using classes
//
//==========================================================


using namespace std;

class Course {
private:
  static int MAX_SEATS;
  static int MAX_CREDIT_HOURS;
  static int DEFAULT_MAX_LEN;
  static int MAX_ID_NUMBER;
  int inCampus = 0;
  int id = 0;
  int creditHours = 3;
  int seatsAvailable = 0;
  int waitCount = 0;
  string title = "(Not Set)";
  string subject = "(Not Set)";
  string professorName = "(Not Set)";
  string professorEmail = "(Not Set)";
public:
  Course() {
    cout << "zero-parameter constructor called" << endl;
  }


  Course(int id, string title, int inCampus, int creditHours, string subject) {
    this->id = id;
    this->title = title;
    this->inCampus = inCampus;
    this->creditHours = creditHours;
    this->subject = subject;
    cout << "5 parameter constructor called" << endl;
  }

  Course(int id, string title, int inCampus, int creditHours, string subject, int seatsAvailable, int waitCount) {
    this->id = id;
    this->title = title;
    this->inCampus = inCampus;
    this->creditHours = creditHours;
    this->subject = subject;
    this->seatsAvailable = seatsAvailable;
    this->waitCount = waitCount;
    cout << "7 parameter constructor called" << endl;
  }

  Course(int id, string title, int inCampus, int creditHours, string subject, int seatsAvailable, int waitCount,
         string professorName, string professorEmail) {
    this->id = id;
    this->title = title;
    this->inCampus = inCampus;
    this->creditHours = creditHours;
    this->subject = subject;
    this->seatsAvailable = seatsAvailable;
    this->waitCount = waitCount;
    this->professorName = professorName;
    this->professorEmail = professorEmail;
    cout << "9 parameter constructor called" << endl;
  }

  // Setters

  void setId(int id) {
    if (id >= 0 && id <= this->MAX_ID_NUMBER) {
      this->id = id;
    } else {
      cout << "ERROR: course number out of range." << endl;
    }
  }

  void setIdPrompt() {
    int id;
    cout << "Enter course id (int): ";
    cin >> id;
    
    this->setId(id);
  }

  void setInCampus(int inCampus) {
    if (inCampus >= 0 && inCampus <= 1) {
      this->inCampus = inCampus;
    } else {
      cout << "ERROR: Input out of range." << endl;
    }
  }

  void setInCampusPrompt() {
    int inCampus;
    cout << "Course in campus? (0 = online, 1 = in campus): ";
    cin >> inCampus;
    
    this->setInCampus(inCampus);
  }

  void setCreditHours(int creditHours) {
    if (creditHours > 0 && creditHours <= this->MAX_CREDIT_HOURS) {
      this->creditHours = creditHours;
    } else {
      cout << "ERROR: Credit hours out of range." << endl;
    }
  }

  void setCreditHoursPrompt() {
    int creditHours;
    cout << "Enter Credit Hours (1-" << this->MAX_CREDIT_HOURS << "): ";
    cin >> creditHours;
    
    this->setCreditHours(creditHours);
  }

  void setSeatsAvailable(int seatsAvailable) {

    if (seatsAvailable <= this->MAX_SEATS && seatsAvailable >= 0) {
      this->seatsAvailable = seatsAvailable;
      if (seatsAvailable > 0) {
        this->waitCount = 0;
      }
    } else {
      cout << "ERROR: Seats available out of range." << endl;
    }
  }

  void setSeatsAvailablePrompt() {
    int seatsAvailable;
    cout << "Enter # of seats available (int): ";
    cin >> seatsAvailable;
    
    this->setSeatsAvailable(seatsAvailable);
  }

  void setWaitCount(int waitCount) {
    if (waitCount >= 0 && waitCount <= this->MAX_SEATS && this->seatsAvailable == 0) {
      this->waitCount = waitCount;
    } else {
      cout << "ERROR: Wait count out of range." << endl;
    }
  }

  void setWaitCountPrompt() {
    int waitCount;
    cout << "Enter Wait Count (int): ";
    cin >> waitCount;
    
    this->setWaitCount(waitCount);
  }


  void setTitle(string title) {
    size_t inputLength = title.size();
    if (inputLength > 0 && inputLength <= this->DEFAULT_MAX_LEN) {
      this->title = title;
    } else {
      cout << "ERROR: Title can not exceed " << this->DEFAULT_MAX_LEN << " characters." << endl;
    }
  }

  void setTitlePrompt() {
    string title;
    cout << "Enter course title: ";
    getline(cin, title, '\n');
    
    this->setTitle(title);
  }

  void setSubject(string subject) {
    size_t inputLength = title.size();
    if (inputLength > 0 && inputLength <= this->DEFAULT_MAX_LEN) {
      this->subject = subject;
    } else {
      cout << "ERROR: Subject can not exceed " << this->DEFAULT_MAX_LEN << " characters." << endl;
    }
  }

  void setSubjectPrompt() {
    string subject;
    cout << "Enter subject: ";
    getline(cin, subject, '\n');
    
    this->setSubject(subject);
  }

  void setProfessorName(string professorName) {
    size_t inputLength = professorName.size();

    if (inputLength > 0 && inputLength <= DEFAULT_MAX_LEN) {
      this->professorName = professorName;
    } else {
      cout << "ERROR: Professor name can not exceed " << DEFAULT_MAX_LEN << " characters." << endl;
    }
  }

  void setProfessorNamePrompt() {
    string professorName;
    cout << "Enter Professor Name: ";
    getline(cin, professorName, '\n');
    
    this->setProfessorName(professorName);
  }

  void setProfessorEmail(string professorEmail) {
    size_t inputLength = professorEmail.size();

    if (inputLength > 0 && inputLength <= DEFAULT_MAX_LEN) {
      this->professorEmail = professorEmail;
    } else {
      cout << "ERROR: Professor email can not exceed " << DEFAULT_MAX_LEN << " characters." << endl;
    }
  }

  void setProfessorEmailPrompt() {
    string professorEmail;
    cout << "Enter Professor Email: ";
    getline(cin, professorEmail, '\n');
    
    this->setProfessorEmail(professorEmail);
  }

  // Getters
  int getId() {
    return this->id;
  }

  int getCreditHours() {
    return this->creditHours;
  }

  int getInCampus() {
    return this->inCampus;
  }

  int getSeatsAvailable() {
    return this->seatsAvailable;
  }

  int getWaitCount() {
    return this->waitCount;
  }

  string getTitle() {
    return this->title;
  }

  string getSubject() {
    return this->subject;
  }

  string getProfessorName() {
    return this->professorName;
  }

  string getProfessorEmail() {
    return this->professorEmail;
  }

  void print() {
    cout << "\n";
    cout << "id: " << this->id << endl;
    cout << "Title: " << this->title << endl;
    cout << "Subject: " << this->subject << endl;
    cout << "Credits: " << this->creditHours << endl;
    cout << "Professor: " << this->professorName << endl;
    cout << "Professor Email: " << this->professorEmail << endl;
    cout << "Seats Available: " << this->seatsAvailable << endl;
    cout << "Wait Count: " << this->waitCount << endl;
  }

};

int main() {

  // Using zero-params constructor
  cout << "\n\nFirst Course with its values:\n" << endl;
  Course basicWriting;
  basicWriting.print();
  basicWriting.setSubject("english");
  basicWriting.setId(15476);
  basicWriting.setTitle("Basic Writing");
  basicWriting.setCreditHours(4);
  basicWriting.setProfessorEmail("diarelo@wayne.edu");
  basicWriting.setProfessorName("Diaz Robert");
  basicWriting.setInCampus(1);
  basicWriting.setSeatsAvailable(23);
  basicWriting.setWaitCount(10);

  int id, inCampus, creditHours, seatsAvailable, waitCount;
  string title, subject, professorName, professorEmail;
  id = basicWriting.getId();
  inCampus = basicWriting.getInCampus();
  creditHours = basicWriting.getCreditHours();
  seatsAvailable = basicWriting.getSeatsAvailable();
  waitCount = basicWriting.getWaitCount();

  title = basicWriting.getTitle();
  subject = basicWriting.getSubject();
  professorName = basicWriting.getProfessorName();
  professorEmail = basicWriting.getProfessorEmail();

  cout << "\n\n::Second Course with its values: \n" << endl;
  Course biology;
  biology.print();

  // Using 5 Params Constructor
  cout << "\n\n::Third Course with its values: \n" << endl;
  Course webTechnology(7533, "Web Technology", 1, 3, "Computer Science");
  webTechnology.print();

  cout << "\n\n::Fourth Course with its values: \n" << endl;
  Course webDesign(4958, "Web Design", 1, 3, "Computer Science");
  webDesign.print();


  // Using 7 Params Constructor
  cout << "\n\n::Fifth Course with its values: \n" << endl;
  Course java(3746, "Java", 0, 4, "Computer Science", 11, 0);
  java.print();


  cout << "\n\n::Sixth Course with its values: \n" << endl;
  Course rust(4352, "Rust", 1, 4, "Computer Science", 0, 7);
  rust.print();


  // Using 9 Params Constructor
  cout << "\n\n::Seventh Course with its values: \n" << endl;
  Course science(1001, "Science", 1, 5, "Science", 3, 0, "Lily Walker", "walkerlil221@wayne.edu");
  science.print();

  cout << "\n\n::Eighth Course with its values: \n" << endl;
  Course physics(2912, "Physics", 0, 3, "Physics", 9, 0, "John Doe", "johndoetogo@wayne.edu");
  physics.print();

  cout << "\n\nUpdating Java Course:\n";
  java.setTitlePrompt();
  java.setSubjectPrompt();
  java.setCreditHoursPrompt();
  java.setSeatsAvailablePrompt();
  cout << "\n:->After Course Update:" << endl;
  java.print();

  return 0;
}

int Course::DEFAULT_MAX_LEN = 100;
int Course::MAX_CREDIT_HOURS = 6;
int Course::MAX_SEATS = 50;
int Course::MAX_ID_NUMBER = 100000;
