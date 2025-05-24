// Author: Mridul Loomba
// Description: Class to prompt the user for the required information and edit it.

#include "userprompt.h"
//Constructor to set the user prompts to the input values
UserPrompt::UserPrompt(std::string n, int a, int w, int l, int g) {
    UserPrompt::name = n;
    UserPrompt::age = a;
    UserPrompt::weight = w;
    UserPrompt::actLevel = l;
    UserPrompt::goals = g;
}
// method to set the name
void UserPrompt::setName(std::string n){
    UserPrompt::name = n;
}
// method to set the age
int UserPrompt::setAge(int a){
    if (a > 100){
        return -1;
    }
    UserPrompt::age = a;
    return 0;
}
// method to set the weight
int UserPrompt::setWeight(int w){
    if(w > 500){
        return -1;
    }
    UserPrompt::weight = w;
    return 0;
}
// method to set the activity level
void UserPrompt::setLev(int l){
    UserPrompt::actLevel = l;
}
// method to set the goals
void UserPrompt::setGoals(int g){
    UserPrompt::goals = g;
}
/**
 *  Methods to get the:
 *  Name
 *  Age
 *  Weight
 *  Activity Level
 *  Goals
 */
std::string getName(){
    return UserPrompt::name;
}

int getAge(){
    return UserPrompt::age;
}
int getWeight(){
    return UserPrompt::weight;
}

int getLev(){
    return UserPrompt::actLevel;
}

int getGoals(){
    return UserPrompt::goals;
}
