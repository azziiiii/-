#include <iostream>

using namespace std;
#define RESET "\033[0m"
//#define BLACK1 "\033[30m"  /* Black */
#define RED1 "\033[31m"    /* Red */
#define GREEN1 "\033[32m"  /* Green */
#define YELLOW1 "\033[33m" /* Yellow */
#define BLUE1 "\033[34m"   /* Blue */
//#define PURPLE "\033[35m" /* Purple */
//#define CYAN "\033[36m"   /* Cyan */
#define WHITE1 "\033[37m"  /* White */

class map
{
public:
    void DrawHighHp();
    void DrawHighMoney();
    void DrawInit();
};

void map::DrawHighMoney()
{
    cout << YELLOW1 << "          A " << RESET << "-----------------------  C  ---------------------- F" << endl;
    cout << YELLOW1 << "          |" << RESET << "                          |                         |" << endl;
    cout << YELLOW1 << "          |" << RESET << "                          |                         |" << endl;
    cout << YELLOW1 << "          |" << RESET << "                          |                         |" << endl;
    cout << YELLOW1 << "          |" << RESET << "                          |                         |" << endl;
    cout << YELLOW1 << "          B-------------" << RESET << "-------------|-------------------------|" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << YELLOW1 << "E-------------" << RESET << "|" << YELLOW1 << "-------------G-----------I" << RESET << endl;
    cout << "          |            |             |                         " << YELLOW1 << "|" << RESET << endl;
    cout << "          |            |             |                         " << YELLOW1 << "|" << RESET << endl;
    cout << "          D------------|-------------" << YELLOW1 << "|-------------L-----------|" << RESET << endl;
    cout << "          |            |             " << YELLOW1 << "|" << RESET << "             |           |" << endl;
    cout << "          |            |             " << YELLOW1 << "|" << RESET << "             |           |" << endl;
    cout << "          |            |             " << YELLOW1 << "|" << RESET << "             |           |" << endl;
    cout << "          |            " << YELLOW1 << "H-------------|" << RESET << "             |           |" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "                           |           |" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "                           |           |" << endl;
    cout << "          K------------" << YELLOW1 << "|" << RESET << "             N-------------------------M" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << YELLOW1 << "|" << RESET << "             |                         |" << endl;
    cout << YELLOW1 << "          O----------------------------------------------------P" << RESET << endl;
}

void map::DrawHighHp()
{
    cout << RED1 << "          A -----------------------  C  ---------------------- F" << RESET << endl;
    cout << "          |                          |                         " << RED1 << "|" << RESET << endl;
    cout << "          |                          |                         " << RED1 << "|" << RESET << endl;
    cout << "          |                          |                         " << RED1 << "|" << RESET << endl;
    cout << "          |                          |                         " << RED1 << "|" << RESET << endl;
    cout << "          B--------------------------" << RED1 << "|-------------------------|" << RESET<< endl;
    cout << "          |            |             " << RED1 << "|                         " << RESET << "|" << endl;
    cout << "          |            |             " << RED1 << "|                         " << RESET << "|" << endl;
    cout << "          |            |             " << RED1 << "|                         " << RESET << "|" << endl;
    cout << "          |            E-------------" << RED1 << "|" << RESET << "-------------G-----------I" << endl;
    cout << "          |            |             " << RED1 << "|" << RESET << "                         |" << endl;
    cout << "          |            |             " << RED1 << "|" << RESET << "                         |" << endl;
    cout << "          D------------|-------------" << RED1 << "|" << RESET << "-------------L-----------|" << endl;
    cout << "          |            |             " << RED1 << "|" << RESET << "             |           |" << endl;
    cout << "          |            |             " << RED1 << "|" << RESET << "             |           |" << endl;
    cout << "          |            |             " << RED1 << "|" << RESET << "             |           |" << endl;
    cout << "          |            " << RED1 << "H-------------|" << RESET << "             |           |" << endl;
    cout << "          |            " << RED1 << "|" << RESET << "                           |           |" << endl;
    cout << "          |            " << RED1 << "|" << RESET << "                           |           |" << endl;
    cout << "          K------------" << RED1 << "|" << RESET << "             N-------------------------M" << endl;
    cout << "          |            " << RED1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << RED1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << RED1 << "|" << RESET << "             |                         |" << endl;
    cout << "          |            " << RED1 << "|" << RESET << "             |                         |" << endl;
    cout << RED1 << "          O----------------------------------------------------P" << RESET << endl;
}

void map::DrawInit()
{
    cout << "          A -----------------------  C  ---------------------- F" << endl;
    cout << "          |                          |                         |" << endl;
    cout << "          |                          |                         |" << endl;
    cout << "          |                          |                         |" << endl;
    cout << "          |                          |                         |" << endl;
    cout << "          B--------------------------|-------------------------|" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          |            E-------------|-------------G-----------I" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          D------------|-------------|-------------L-----------|" << endl;
    cout << "          |            |             |             |           |" << endl;
    cout << "          |            |             |             |           |" << endl;
    cout << "          |            |             |             |           |" << endl;
    cout << "          |            H-------------|             |           |" << endl;
    cout << "          |            |                           |           |" << endl;
    cout << "          |            |                           |           |" << endl;
    cout << "          K------------|             N-------------------------M" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          |            |             |                         |" << endl;
    cout << "          O----------------------------------------------------P" << endl;
}
