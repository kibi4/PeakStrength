// Mridul Loomba
// Header File for UserPrompt
#ifndef USERPROMPT_H
#define USERPROMPT_H
#include <string>

#include "userPrompt_global.h"

class USERPROMPT_EXPORT UserPrompt
{
    // All the required instance variables and methods
public:
    UserPrompt(std::string n, int a, int w, int l, int g);
    std::string static name;
    int static age, weight, actLevel, goals;
    void setName(std::string n);
    int setAge(int a);
    int setWeight(int w);
    void setLev(int l);
    void setGoals(int g);
    std::string getName();
    int getAge();
    int getWeight();
    int getLev();
    int getGoals();
};

#endif // USERPROMPT_H
