#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    string email;

public:
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Person::name = name;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Person::email = email;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Person::age = age;
    }
};


class Event {
private:
    string name;
    string date;

public:
    Event(const string &name, const string &date) {
        this->name = name;
        this->date = date;
    }

    string getName() const {
        return name;
    }

    string getDate() const {
        return date;
    }

    void setName(const string &name) {
        this->name = name;
    }

    void setDate(const string &date) {
        this->date = date;
    }
};

class Meeting : public Event {
private:
    int numberPeople;
    string location;
    Person people[100];

public:

    Meeting(const string &name, const string &date, const string &location)
            : Event(name, date) {
        this->location = location;
        numberPeople = 0;
    }

    void addPerson(const Person &p) {
        people[numberPeople] = p;
        numberPeople++;
    }

    int getNumberOfPeople() const {
        return numberPeople;
    }

    string getLocation() {
        return location;
    }

    Person *getPeople() {
        return people;
    }

    void setLocation(const string &location) {
        this->location = location;
    }
};


int main() {
    Meeting m1("Izpit", "18.06.2023", "VTU");

    Person p1;
    Person p2;

    p1.setName("Ivan Ivanov");
    p2.setName("Stoqn Stoqnov");
    p1.setAge(22);
    p2.setAge(30);
    p1.setEmail("st@abv.bg");
    p2.setEmail("ivan@abv.bg");

    m1.addPerson(p1);
    m1.addPerson(p2);

    cout << "Meeting: \n" << m1.getName() << " in ";
    cout << m1.getLocation() << " on " << m1.getDate() << endl;
    cout << "Participants (" << m1.getNumberOfPeople() << "):" << endl;

    Person *people = m1.getPeople();
    int nPeople = m1.getNumberOfPeople();

    for (int i = 0; i < nPeople; ++i) {
        cout << people[i].getName() << " " << people[i].getEmail() << " age: " << people[i].getAge() << endl;
    }
    return 0;
}

