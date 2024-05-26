#include <iostream>
#include <ctime>
#define _USE_MATH_DEFINES 
#include <sstream>
#include <math.h>
using namespace std;

const int M = 5;
const double A = M_PI_4;
int collisionCounter = 0;

struct Node
{
    string key = "";
    string value = "";
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct HashTable
{
    Node* table[M];

    HashTable()
    {
        for (int i = 0; i < M; ++i)
            table[i] = nullptr;
    }
};

double mod1(double k) 
{
    int intPart = static_cast<int>(k);
    return k - intPart;
}

int gethash(double k) 
{
    return static_cast<int>(M * mod1(k) * A);
}

int gethash(string line) 
{
    int n = 0;
    for (int i = 0; i < line.size(); i++) 
    {
        n += static_cast<int>(pow(line[i], 2) * M_2_SQRTPI + abs(line[i]) * M_SQRT1_2);
    }
    return gethash(abs(n));
}

bool add(HashTable& table, string key, string elem) 
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->value = elem;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    int hash = gethash(key);
    if (table.table[hash] == nullptr)
    {
        table.table[hash] = newNode;
        return true;
    }
    else 
    {
        Node* current = table.table[hash];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        collisionCounter++;
    }
    return true;
}

bool removeByKey(HashTable& table, string key)
{
    int hash = gethash(key);
    Node* current = table.table[hash];
    while (current != nullptr) 
    {
        if (current->key == key)
        {
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            else 
            {
                table.table[hash] = current->next;
            }
            if (current->next != nullptr) 
            {
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool removeByValue(HashTable& table, string elem) 
{
    for (int i = 0; i < M; i++)
    {
        Node* current = table.table[i];
        while (current != nullptr) 
        {
            if (current->value == elem) 
            {
                if (current->prev != nullptr) 
                {
                    current->prev->next = current->next;
                }
                else 
                {
                    table.table[i] = current->next;
                }
                if (current->next != nullptr) 
                {
                    current->next->prev = current->prev;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

Node* get(HashTable& table, string key)
{
    int hash = gethash(key);
    Node* current = table.table[hash];
    while (current != nullptr) 
    {
        if (current->key == key) 
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void print(HashTable& table) 
{
    for (int i = 0; i < M; i++) 
    {
        Node* current = table.table[i];
        while (current != nullptr)
        {
            cout << "[" << current->key << " : " << current->value << "]\n";
            current = current->next;
        }
    }
}

string surnames[] = 
{
    "Ivanov", "Kozlov", "Novikov", "Morozov", "Petrov",
    " Lebedev", "Soloviev", "Vasiliev", "Zaitsev", "Pavlov",
    "Volkov", "Golubev", "Ignatov", "Bogdanov", "Borobyev",
    "Fyodorov", "Mikhaylov", "Beleyev", "Tarasov", "Belov",
    "Zhukov", "Orlov", "Kiselev", "Makarov", "Andreyev"
};

string names[] = 
{
    "Alexander", "Sergey", "Andrey", "Dmitriy", "Aleksey",
    "Mikhail", "Nikolay", "Evgeniy", "Oleg", "Vladimir",
    "Nikita", "Yuriy", "Ivan", "Konstantin", "Stanislav",
    "Valentin", "Valeriy", "Oleg", "Konstantin", "Stanislav",
    "Roman", "Igor", "Gennadiy", "Vyacheslav", "David",
    "Nikita", "Artem", "Timur", "Ruslan", "Semyon"
};

string patronymics[] = 
{
    "Ivanovich", "Sergeevich", "Andreyevich", "Dmitriyevich", "Alekseyevich",
    "Ivanovich", "Nikolayevich", "Mikhaylovich", "Olegovich", "Petrovich",
    "Anatolyevich", "Vladimirovich", "Yegorovich", "Viktorovich", "Fyodorovich",
    "Konstantinovich", "Arkadyevich", "Ermolaevich", "Vasilievich", "Timofeevich",
    "Igorevich", "Valeryevich", "Stanislavovich", "Romanovich", "Gennadiyevich",
    "Pavlovich", "Vyacheslavovich", "Evgenyevich", "Davidovich", "Grigoryevich"
};

string generateFullName() 
{
    return surnames[rand() % 30] + " " + names[rand() % 30] + " " + patronymics[rand() % 30];
}

string correctStr(int n, int length) 
{
    string strn = to_string(n);
    while (strn.size() < length) 
    {
        strn = '0' + strn;
    }
    while (strn.size() > length) 
    {
        strn.erase(0, 1);
    }
    return strn;
}

string generateCount() 
{
    return correctStr(rand(), 5) + correctStr(rand(), 5) + correctStr(rand(), 5) + correctStr(rand(), 5);
}

string generateSum()
{
    return to_string(rand()) + to_string(rand());
}

int main() 
{
    srand(time(NULL));
    HashTable myTable;

    for (int i = 0; i < M; i++) 
    {
        string count = generateCount();
        string newHuman = generateFullName() + " | " + count + " | " + generateSum();
        add(myTable, count, newHuman);
    }

    cout << "\nHash table created:\n" << endl;
    print(myTable);
    cout << endl;

    int existingInd = rand() % M;
    while (myTable.table[existingInd] == nullptr) 
    {
        existingInd = rand() % M;
    }

    Node* randomHuman = myTable.table[existingInd];
    string keyToRemove = randomHuman->key;

    cout << "Delete by key " << keyToRemove << ": ";

    if (removeByKey(myTable, keyToRemove))
    {
        cout << "\nElement with key '" << keyToRemove << "' successfully deleted\n" << endl;
    }
    else 
    {
        cout << "\nElement with key '" << keyToRemove << "'" << " not found\n" << endl;
    }

    print(myTable);
    existingInd = rand() % M;
    while (myTable.table[existingInd] == nullptr) 
    {
        existingInd = rand() % M;
    }

    randomHuman = myTable.table[existingInd];
    string valueToRemove = randomHuman->value;
    cout << "\nDelete by value \"" << valueToRemove << "\":" << endl;
    if (removeByValue(myTable, valueToRemove)) 
    {
        cout << "Element with value \"" << valueToRemove << "\" successfully deleted\n" << endl;
    }
    else
    {
        cout << "Element with value \"" << valueToRemove << "\" not found\n" << endl;
    }
    print(myTable);

    existingInd = rand() % M;
    while (myTable.table[existingInd] == nullptr) 
    {
        existingInd = rand() % M;
    }

    randomHuman = myTable.table[existingInd];
    string keyToGet = randomHuman->key;
    cout << "\nGetting an element by key \"" << keyToGet << "\":" << endl;
    Node* node = get(myTable, keyToGet);
    if (node != nullptr) 
    {
        cout << "Item found: " << node->value << endl;
    }
    else 
    {
        cout << "Element with value " << keyToGet << "not found." << endl;
    }
    cout << "Number of collisions: " << collisionCounter << endl << endl;
    return 0;
}