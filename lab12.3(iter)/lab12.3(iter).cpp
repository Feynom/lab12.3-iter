#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void Enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
bool Process(Elem* L);
int Count(Elem* L);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    bool result;

    Info value, N;

    do
    {
        cout << "Введіть кількість елементів списку: "; cin >> N;
    } while (N < 0);

    for (int i = 0; i < N; i++)
    {
        cout << "Введіть дані: "; cin >> value;
        Enqueue(first, last, value);
    }

    cout << "Елементи черги: "; Print(first); cout << endl;

    cout << "\nРезультат: ";
    Process(first) ? cout << "Так!" : cout << "Ні";
    return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}
void Print(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->next;
    }
}
bool Process(Elem* L)
{
    int count = 0, 
        number_of_elements = Count(L),
        cur_poss = 0;
   
    if (number_of_elements == 1)
        return false;

    Info curent,
         next;

    while (cur_poss < number_of_elements - 1)
    {
        curent = L->info;
        L = L->next;
        next = L->info;
        if (next >= curent)
            count++;
        cur_poss++;
    }
    if (count == number_of_elements - 1)
        return true;
    else
        return false;
}
int Count(Elem* L)
{
    int count = 0;
    while (L != NULL)
    {
        count++;
        L = L->next;
    }
    return count;
}