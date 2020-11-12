//
//  main.cpp
//  lab 2
//
//  Created by Максим Палёхин on 12.11.2020.
//

#include <map>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class Date
{
public:
    Date(int d = 0, int m = 0, int y = 0)
    {
        setDate(d, m, y);
    }
 
    Date(const Date &date)
    {
        setDate(date.day, date.month, date.year);
    }
 
    ~Date()
    {
 
    }
 
    int getDay() const
    {
        return day;
    }
 
    int getMonth() const
    {
        return month;
    }
 
    int getYear() const
    {
        return year;
    }
 
    void setDay(int day)
    {
        this->day = day;
    }
 
    void setMonth(int month)
    {
        this->month = month;
    }
 
    void setYear(int year)
    {
        this->year = year;
    }
 
    void setDate(int day, int month, int year)
    {
        if (isValidDate(day, month, year))
        {
            setDay(day);
            setMonth(month);
            setYear(year);
        }
        else {
            throw std::string("Not valid date");
        }
    }
 
    void print() const
    {
        std::cout << day << '.'
            << month << '.'
            << year << std::endl;
    }
 
    static bool isValidDate(int day, int month, int year)
    {
        if ((day<1 || day>31) || (month<1 || month>12))
        {
            std::cout<<"Not valid date"<<std::endl;
        }
        return true;
    }
 
    static bool isLeapYear(int year)
    {
 
        return ((year % 4 == 0 && year% 100 != 0) || year % 400);
 
    }
 
    static int dayInMonth(int month)
    {
        int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear)days[1]=29;
        return days[month-1];
    }
    friend ostream& operator<<(ostream& os, const Date& date)
        {
            os << date.day << "." << date.month << "." << date.year << "\n";
            return os;
        }
    friend bool operator > (Date const& first, Date const& second){
        if (first.year > second.year){
            return true;
        } else if (first.month > second.month){
            return true;
        } else if ( first.day > second.day){
            return true;
        }else{
            return false;
        }
        };
    friend bool operator < (Date const& first, Date const& second){
        if (first.year < second.year){
            return true;
        } else if (first.month < second.month){
            return true;
        } else if ( first.day < second.day){
            return true;
        }else{
            return false;
        }
        };
    friend bool operator == (Date const& first, Date const& second){
        if (first.year == second.year){
            return true;
        } else if (first.month == second.month){
            return true;
        } else if ( first.day == second.day){
            return true;
        }else{
            return false;
        }
        };
    friend bool operator != (Date const& first, Date const& second){
        if (first.year != second.year){
            return true;
        } else if (first.month != second.month){
            return true;
        } else if ( first.day != second.day){
            return true;
        }else{
            return false;
        }
        };
 
private:
    int day;
    int month;
    int year;
};




class SchoolMan {

private:
    string name;
    string lastName;
    string sex;
    int group;
    Date dateOfBorn;
    string adress;
public:
    SchoolMan(){}

    SchoolMan(string name, string lastName, string sex, int group, Date dateOfBorn, string adress) {
        this->name = name;
        this->lastName = lastName;
        this->sex = sex;
        this->group = group;
        this->dateOfBorn = dateOfBorn;
        this->adress = adress;

    }

    string getName() {
        return name;
    }
    string getLastName() {
        return lastName;
    }
    string getSex() {
        return sex;
    }
    int getGroup() {
        return group;
    }
    Date getDateOfBorn() {
        return dateOfBorn;
    }
    string getAdress() {
        return adress;
    }

    friend ostream& operator<<(ostream& os, const SchoolMan& schoolMan)
    {
        os << "" << schoolMan.name << " | " << schoolMan.lastName << " | " << schoolMan.sex << " | "
            << schoolMan.group << " | " << schoolMan.dateOfBorn << " | " << schoolMan.adress << "\n";
        return os;
    }
    bool operator==(SchoolMan const& other) const {
        return ((name == other.name) && (lastName == other.lastName) && (sex == other.sex) &&
            (group == other.group) && (dateOfBorn == other.dateOfBorn) && (adress == other.adress));
    }
    friend bool operator > (SchoolMan const& first, SchoolMan const& second){
            return first.dateOfBorn>second.dateOfBorn;
        };
    friend bool operator < (SchoolMan const& first, SchoolMan const& second){
            return first.dateOfBorn<second.dateOfBorn;
        };
    friend bool operator == (SchoolMan const& first, SchoolMan const& second){
            return first.dateOfBorn==second.dateOfBorn;
        };
    friend bool operator != (SchoolMan const& first, SchoolMan const& second){
            return first.dateOfBorn!=second.dateOfBorn;
        };
};

map<string, Date>::iterator key_find(map<string, Date>& schoolman, string key)
{
    return schoolman.find(key);
}

string value_find(map<string, Date>& schoolman, Date value)
{
    map<string, Date>::iterator p = schoolman.begin();

    while (p != schoolman.end())
    {
        if (p->second == value)
            return p->first;
        p++;
    }
    return "";
}


void to_console(map<string, Date>& schoolman)
{
    map<string, Date>::iterator p = schoolman.begin();
    while (p != schoolman.end())
    {
        cout << "Ключ: " << p->first << ", Значение: " << p->second << "\n";
        p++;
    }
}

map<string, Date> filter(map<string, Date>& schoolman, Date pred)
{
    map<string, Date> res;
    map<string, Date>::iterator p = schoolman.begin();
    while (p != schoolman.end())
    {
        if (p->second > pred)
            res.insert(make_pair(p->first, p->second));
        p++;
    }
    return res;
}

template<typename T>
void print_queue(T& q)
{
    while (!q.empty())
    {
        pair <string, int> top = q.top();
        cout << top.first << " - " << top.second << endl;
        q.pop();
    }
    std::cout << '\n';
}

int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "Russian");

    //ЗАДАНИЕ 2.1
    cout << "!!!ЗАДАНИЕ 2.1!!!\n";

    map<string, Date> schoolman;
    schoolman["Максим Палёхин"] = Date(20, 12, 2001);
    schoolman["Краснов Александр"] = Date(8, 11, 2001);
    schoolman["Евгений Кравцов"] =  Date(4, 1, 1994);
    schoolman["Валерий Меладзе"] = Date(20, 5, 1981);
    schoolman["Дмитрий Шац"] =  Date(14, 9, 2011);

    //Вывод в консоль мапа
    cout << endl << "Вывод в консоль мэпа" << endl;
    to_console(schoolman);

    //Поиск по ключу
    map<string, Date>::iterator a = key_find(schoolman, "Валерий Меладзе");
    cout << endl << "Поиск по ключу: " << "Валерий Меладзе" << endl;
    if(a != schoolman.end())
        cout << a->second << endl;
    else
        cout << "Данный ключ не найден " << endl;

    //Поиск по значению
    string b = value_find(schoolman, Date(20, 11, 1999));
    cout << endl << "Поиск по значению: " << "20.11.1999" << endl;
    cout << b << endl;

    //Вывод в консоль отсортированного значения (трешхолд 10)
    cout << endl << "Вывод в консоль отсортированного мэпа, без Победы" << endl;
    map<string, Date> schoolman_filtered = filter(schoolman, Date(20, 11, 2001));
    to_console(schoolman_filtered);
}
