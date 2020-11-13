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
            std::cout<<"Is  valid date"<<std::endl;
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
    bool operator!=(SchoolMan const& other) const {
        return ((name != other.name) && (lastName != other.lastName) && (sex != other.sex) &&
            (group != other.group) && (dateOfBorn != other.dateOfBorn) && (adress != other.adress));
    }
    friend bool operator > (SchoolMan const& first, SchoolMan const& second){
            return first.dateOfBorn>second.dateOfBorn;
        };
    friend bool operator < (SchoolMan const& first, SchoolMan const& second){
            return first.dateOfBorn<second.dateOfBorn;
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
        pair <string, Date> top = q.top();
        cout << top.first << " - " << top.second << endl;
        q.pop();
    }
    std::cout << '\n';
}
//Шаблон АВЛ Дерева 2.3
template<class T>
class NodeT
{
protected:
    //закрытые переменные NodeT N; N.data = 10 вызовет ошибку
    //T data;
    //T key можно еще и это хранить

    //не можем хранить NodeT, но имеем право хранить указатель
    NodeT* left;
    NodeT* right;
    NodeT* parent;

    //переменная, необходимая для поддержания баланса дерева
    //int height;
public:
    T data;
    int height;
    //доступные извне переменные и функции
    virtual void setData(T d) { data = d; }
    virtual T getData() { return data; }
    int getHeight() { return height; }

    virtual NodeT* getLeft() { return left; }
    virtual NodeT* getRight() { return right; }
    virtual NodeT* getParent() { return parent; }

    virtual void setLeft(NodeT* N) { left = N; }
    virtual void setRight(NodeT* N) { right = N; }
    virtual void setParent(NodeT* N) { parent = N; }

    //Конструктор. Устанавливаем стартовые значения для указателей
    NodeT<T>(T n)
    {//Менять, если храниться более сложная инфа
        data = n;
        left = right = parent = NULL;
        height = 1;
    }

    NodeT<T>()
    {
        left = NULL;
        right = NULL;
        parent = NULL;
        //data = NULL;
        height = 1;
    }


    virtual void print()
    {
        cout << "\n" << data;
    }

    virtual void setHeight(int h)
    {
        height = h;
    }

    template<class R> friend ostream& operator<< (ostream& stream, NodeT<T>& N);
};

template<class T>
ostream& operator<< (ostream& stream, NodeT<T>& N)
{
    stream << "\nNodeT data: " << N.data << ", height: " << N.height;
    return stream;
}
template<class T>
void print(NodeT<T>* N) { cout << "\n" << N->getData(); }

template<class T>
class Tree
{
protected:
    //корень - его достаточно для хранения всего дерева
    NodeT<T>* root;
public:
    //доступ к корневому элементу
    virtual NodeT<T>* getRoot() { return root; }

    //конструктор дерева: в момент создания дерева ни одного узла нет, корень смотрит в никуда
    Tree<T>() { root = NULL; }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual NodeT<T>* Add_R(NodeT<T>* N)
    {
        return Add_R(N, root);
    }

    virtual NodeT<T>* Add_R(NodeT<T>* N, NodeT<T>* Current)
    {
        if (N == NULL) return NULL;
        if (root == NULL)
        {
            root = N;
            return N;
        }

        if (Current->getData() > N->getData())
        {
            //идем влево
            if (Current->getLeft() != NULL)
                Current->setLeft(Add_R(N, Current->getLeft()));
            else
                Current->setLeft(N);
            Current->getLeft()->setParent(Current);
        }
        if (Current->getData() < N->getData())
        {
            //идем вправо
            if (Current->getRight() != NULL)
                Current->setRight(Add_R(N, Current->getRight()));
            else
                Current->setRight(N);
            Current->getRight()->setParent(Current);
        }
        if (Current->getData() == N->getData())
            //нашли совпадение
            ;
        //для несбалансированного дерева поиска
        return Current;
    }

    //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
    virtual void Add(T n)
    {
        NodeT<T>* N = new NodeT<T>;
        N->setData(n);
        Add_R(N);
    }

    //удаление узла
    virtual void Remove(NodeT<T>* N)
    { }

    virtual NodeT<T>* Min(NodeT<T>* Current = NULL)
    {
        //минимум - это самый "левый" узел. Идём по дереву всегда влево
        //Пустое дерево
        if (root == NULL)
            return NULL;
        //T.Min();
        if (Current == NULL)
            Current = root;

        //Всегда влево
        while (Current->getLeft() != NULL)
            Current = Current->getLeft();

        return Current;
    }

    virtual NodeT<T>* Max(NodeT<T>* Current = NULL)
    {
        //максимум - это самый "правый" узел. Идём по дереву всегда вправо
        //Пустое дерево
        if (root == NULL)
            return NULL;
        //T.Min();
        if (Current == NULL)
            Current = root;

        //Всегда влево
        while (Current->getRight() != NULL)
            Current = Current->getRight();

        return Current;
    }

    virtual NodeT<T>* Find(T data)
    {
        return Find(data, root);
    }

    //поиск узла в дереве. Второй параметр - в каком поддереве искать, первый - что искать
    virtual NodeT<T>* Find(T data, NodeT<T>* Current)
    {
        if (Current == NULL) return NULL;

        //База рекурсии
        if (Current->getData() == data) return Current;

        if (Current->getData() > data) return Find(data, Current->getLeft());
        if (Current->getData() < data) return Find(data, Current->getRight());
        return NULL;
    }

    //три обхода дерева
    virtual void PreOrder(NodeT<T>* N, void (*f)(NodeT<T>*))
    {
        if (N != NULL)
            f(N);
        if (N != NULL && N->getLeft() != NULL)
            PreOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PreOrder(N->getRight(), f);
    }

    //InOrder-обход даст отсортированную последовательность
    virtual void InOrder(NodeT<T>* N, void (*f)(NodeT<T>*))
    {
        if (N != NULL && N->getLeft() != NULL)
            InOrder(N->getLeft(), f);
        if (N != NULL)
            f(N);
        if (N != NULL && N->getRight() != NULL)
            InOrder(N->getRight(), f);
    }

    virtual void PostOrder(NodeT<T>* N, void (*f)(NodeT<T>*))
    {
        if (N != NULL && N->getLeft() != NULL)
            PostOrder(N->getLeft(), f);
        if (N != NULL && N->getRight() != NULL)
            PostOrder(N->getRight(), f);
        if (N != NULL)
            f(N);
    }
};

//класс итератор по дереву
template<typename ValueType>
class TreeIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
private:

public:
    TreeIterator() { ptr = NULL; T = NULL; }
    TreeIterator(Tree<ValueType>* t, NodeT<ValueType>* p) { ptr = p; T = t; }
    TreeIterator(const TreeIterator& it) { ptr = it.ptr; T = it.T; }

    TreeIterator& operator=(const TreeIterator& it) { ptr = it.ptr; T = it.T; return *this; } //p1=p2=p3;
    TreeIterator& operator=(NodeT<ValueType>* p) { ptr = p; return *this; }

    bool operator!=(TreeIterator const& other) const { return ptr != other.ptr; }
    bool operator==(TreeIterator const& other) const { return ptr == other.ptr; }
    NodeT<ValueType>& operator*() { return *ptr; }
    TreeIterator& operator++()
    {
        //successor
        if (ptr->getRight() != NULL) {
            ptr = T->Min(ptr->getRight());
        }
        else if (ptr->getParent() != NULL && ptr->getData() < (ptr->getParent())->getData()) { //Если родитель больше, то поднимаемся.
            ptr = ptr->getParent();
        }
        else if (ptr->getParent() != NULL && ptr->getData() > (ptr->getParent())->getData()) {
            NodeT<ValueType>* temp = ptr;
            while ((ptr->getParent())->getData() < temp->getData())
                ptr = ptr->getParent();
            ptr = ptr->getParent();

        }
        return *this;
    }
    TreeIterator& operator++(int v)
    {
        //successor
        if (ptr->getRight() != NULL) {
            ptr = T->Min(ptr->getRight());
        }
        else if (ptr->getParent() != NULL && ptr->getData() < (ptr->getParent())->getData()) { //Если родитель больше, то поднимаемся.
            ptr = ptr->getParent();
        }
        else if (ptr->getParent() != NULL && ptr->getData() > (ptr->getParent())->getData()) {
            NodeT<ValueType>* temp = ptr;
            while ((ptr->getParent())->getData() < temp->getData())
                ptr = ptr->getParent();
            ptr = ptr->getParent();

        }
        return *this;
    }
    TreeIterator& operator--()
    {
        //predecessor
        if (ptr->getLeft() != NULL) {
            ptr = T->Max(ptr->getLeft());
        }
        else if (ptr->getParent() != NULL && ptr->getData() > (ptr->getParent())->getData()) { //Если родитель больше, то поднимаемся.
            ptr = ptr->getParent();
        }
        else if (ptr->getParent() != NULL && ptr->getData() < (ptr->getParent())->getData()) {
            NodeT<ValueType>* temp = ptr;
            while ((ptr->getParent())->getData() > temp->getData())
                ptr = ptr->getParent();
            ptr = ptr->getParent();

        }
        return *this;
    }
    TreeIterator& operator--(int v)
    {
        //predecessor
        if (ptr->getLeft() != NULL) {
            ptr = T->Max(ptr->getLeft());
        }
        else if (ptr->getParent() != NULL && ptr->getData() > (ptr->getParent())->getData()) { //Если родитель больше, то поднимаемся.
            ptr = ptr->getParent();
        }
        else if (ptr->getParent() != NULL && ptr->getData() < (ptr->getParent())->getData()) {
            NodeT<ValueType>* temp = ptr;
            while ((ptr->getParent())->getData() > temp->getData())
                ptr = ptr->getParent();
            ptr = ptr->getParent();

        }
        return *this;
    }
private:
    NodeT<ValueType>* ptr;
    Tree<ValueType>* T;
};

//класс итерируемое дерево поиска
template<class T>
class IteratedTree : public Tree<T>
{
public:
    IteratedTree<T>() : Tree<T>() {}

    //TreeIterator<T> iterator;

    TreeIterator<T> begin() { TreeIterator<T> it = TreeIterator<T>(this, Tree<T>::Min()); return it; }
    TreeIterator<T> end() { TreeIterator<T> it = TreeIterator<T>(this, Tree<T>::Max()); return it; }
};

//AVL_Tree - потомок класса Tree, АВЛ-дерево (сбалансированное дерево поиска)
template<class T>
class AVL_Tree : public IteratedTree<T>
{
protected:
    //определение разности высот двух поддеревьев
    int bfactor(NodeT<T>* p)
    {
        int hl = 0;
        int hr = 0;
        if (p->getLeft() != NULL)
            hl = p->getLeft()->getHeight();
        if (p->getRight() != NULL)
            hr = p->getRight()->getHeight();
        return (hr - hl);
    }

    //при добавлении узлов в них нет информации о балансе, т.к. не ясно, куда в дереве они попадут
    //после добавления узла рассчитываем его высоту (расстояние до корня) и редактируем высоты в узлах, где это
    //значение могло поменяться
    void fixHeight(NodeT<T>* p)
    {
        int hl = 0;
        int hr = 0;
        if (p->getLeft() != NULL)
            hl = p->getLeft()->getHeight();
        if (p->getRight() != NULL)
            hr = p->getRight()->getHeight();
        p->setHeight((hl > hr ? hl : hr) + 1);
    }

    //краеугольные камни АВЛ-деревьев - процедуры поворотов
    NodeT<T>* RotateRight(NodeT<T>* p) // правый поворот вокруг p
    {
        NodeT<T>* q = p->getLeft();
        p->setLeft(q->getRight());
        q->setRight(p);

        q->setParent(p->getParent());
        p->setParent(q);
        if (p->getLeft() != NULL)
            p->getLeft()->setParent(p);

        if (Tree<T>::root == p)
            Tree<T>::root = q;

        fixHeight(p);
        fixHeight(q);
        return q;
    }

    NodeT<T>* RotateLeft(NodeT<T>* q) // левый поворот вокруг q
    {
        NodeT<T>* p = q->getRight();
        q->setRight(p->getLeft());
        p->setLeft(q);

        p->setParent(q->getParent());
        q->setParent(p);
        if (q->getRight() != NULL)
            q->getRight()->setParent(q);

        if (q == Tree<T>::root)
            Tree<T>::root = p;

        fixHeight(q);
        fixHeight(p);
        return p;
    }

    //балансировка поддерева узла p - вызов нужных поворотов в зависимости от показателя баланса
    NodeT<T>* Balance(NodeT<T>* p) // балансировка узла p
    {
        fixHeight(p);
        if (bfactor(p) == 2)
        {
            if (bfactor(p->getRight()) < 0)
            {
                p->setRight(RotateRight(p->getRight()));
                p->getRight()->setParent(p);
            }
            return RotateLeft(p);
        }
        if (bfactor(p) == -2)
        {
            if (bfactor(p->getLeft()) > 0)
            {
                p->setLeft(RotateLeft(p->getLeft()));
                p->getLeft()->setParent(p);
            }
            return RotateRight(p);
        }

        return p; // балансировка не нужна
    }

public:
    //конструктор AVL_Tree вызывает конструктор базового класса Tree
    AVL_Tree<T>() : IteratedTree<T>() {}

    virtual NodeT<T>* Add_R(NodeT<T>* N)
    {
        return Add_R(N, Tree<T>::root);
    }

    //рекуррентная функция добавления узла. Устроена аналогично, но вызывает сама себя - добавление в левое или правое поддерево
    virtual NodeT<T>* Add_R(NodeT<T>* N, NodeT<T>* Current)
    {
        //вызываем функцию Add_R из базового класса
        NodeT<T>* AddedNodeT = Tree<T>::Add_R(N, Current);
        //применяем к добавленному узлу балансировку
        return Balance(AddedNodeT);
    }

    //функция для добавления числа. Делаем новый узел с этими данными и вызываем нужную функцию добавления в дерево
    virtual void Add(T n)
    {
        NodeT<T>* N = new NodeT<T>;
        N->setData(n);
        Add_R(N);
    }

    //удаление узла
    virtual void Remove(NodeT<T>* N)
    { }
};


int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "Russian");

    //ЗАДАНИЕ 2.1
    cout << "Лаба 2.1\n";

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
    string b = value_find(schoolman, Date(14, 9, 2011));
    cout << endl << "Поиск по значению: " << "14.9.2011" << endl;
    cout << b << endl;

    //Вывод в консоль отсортированного значению
    cout << endl << "Вывод в консоль отсортированного мэпа" << endl;
    map<string, Date> schoolman_filtered = filter(schoolman, Date(20, 11, 2001));
    to_console(schoolman_filtered);
    
    //ЗАДАНИЕ 2.2
    cout << "Лаба 2.2\n";

    auto cmp = [](const pair <string, Date>& a, const pair <string, Date>& b)
    {//Создаем лямбда-функцию, которая делает наш приоритет
        return a.second > b.second;
    };

    //Очередь на основы вектора строка-date, в которую мы кладем нашу мап из 2.1 и сортируем благодаря лямбда-функции cmp
    priority_queue < pair <string, Date>, vector < pair <string, Date>>, decltype(cmp)> queue(
                                                                                              schoolman.begin(), schoolman.end(), cmp);

    //Выводим очередь
    print_queue(queue);
    
    //!!!ЗАДАНИЕ 2.3!!!
    cout << "\n!!!ЗАДАНИЕ 2.3!!!\n";
    
    SchoolMan scm1("Виктория", "Шуманская", "Женский", 10, Date(7, 4, 1999), "Рязань");
    SchoolMan scm2("Максим", "Палёхин", "Мужской", 1, Date(4, 1, 2001), "Москва");
    SchoolMan scm3("Антон", "Дунаевский", "Мужской", 8, Date(7, 10, 2011), "Павловский пасад");
    SchoolMan scm4("Анатолий", "Красавин", "Мужской", 4, Date(23, 9, 1988), "Ростов");
    SchoolMan scm5("Александр", "Краснов", "Мужской", 3, Date(17, 2, 1981), "Ростов");
    SchoolMan scm6("Александр", "Сычев", "Мужской", 2, Date(27, 3, 1994), "Электросталь");
    SchoolMan scm8("Алексей", "Романов", "Мужской", 9, Date(23, 05, 2001), "Домодедово");

    AVL_Tree<SchoolMan> T;
    T.Add(scm1);
    T.Add(scm2);
    T.Add(scm3);
    T.Add(scm4);
    T.Add(scm5);
    T.Add(scm6);
    T.Add(scm8);

    NodeT<SchoolMan>* M = T.Min();
    cout << "\nMin = " << M->getData();
    void (*f_ptr)(NodeT<SchoolMan>*);
    f_ptr = print;
    cout << "\n-----\nPreorder:";
    T.PreOrder(T.getRoot(), f_ptr);
    cout << "\n-----\nInorder:";
    T.InOrder(T.getRoot(), f_ptr);
    cout << "\n-----\nPostorder:";
    T.PostOrder(T.getRoot(), f_ptr);
    cout << "\nIterators:\n";
    TreeIterator<SchoolMan> p = T.begin();
    while (p != T.end())
    {
        cout << *p << " ";
        p++;
    }
    cout << *p << " ";
    
    cout << "\nIterators Back:\n";
    p = T.end();
    while (p != T.begin())
    {
        cout << *p << " ";
        p--;
    }
    cout << *p << " ";

    
}
