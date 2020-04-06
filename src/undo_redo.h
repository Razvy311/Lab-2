#pragma once

#include "Medikament.h"
#include <vector>
#include <exception>

class Undo_Redo{
    private:
        // We save every element of a step in a vector.
    	std::vector<std::vector<Medikament *>> steps;
        int index;
        
    public:
        bool flag = false;  // the flag is recording wether an undo was made

        Undo_Redo(){
            index = -1;
        }

        // Getters.
        std::vector<std::vector<Medikament *>> getSteps(){
            return this->steps;
        }
        int getIndex(){
            return this->index;
        }

        // Setters.
        void setIndex(int newIndex){
            this->index = newIndex;
        }

        void addStep(std::vector<Medikament *> step){
            // Adds a vector(a step) to the vector.
            this->steps.push_back(step);
            this->index++;
        }
        void clearSteps(int from){
            // Clears the unwanted steps after an operation was made.
            this->steps.erase(this->steps.begin() + from, this->steps.end());
        }

        std::vector<Medikament *> undo(){
            // Throws an exception if there are no more steps to undo.
            // Goes to the previous step.
            if(this->index < 0){
                throw std::exception();
            }
            flag = true;
            this->index--;
            if(this->index == -1){
                return this->steps[0];
            }
            return this->steps[this->index];
        }

        std::vector<Medikament *> redo(){
            // Throws an exception if there are no former steps.
            // Goes to the next step, only if an undo was previously made.
            this->index++;
            if(this->index >= this->steps.size() || !flag){
                throw std::exception();
            }
            return this->steps[this->index];
        }
};