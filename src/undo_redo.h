#pragma once

#include "Medikament.h"
#include <vector>
#include <exception>

class Undo_Redo{
    private:
        // We save every element of a step in a vector.
    	std::vector<std::vector<Medikament>> steps;
        int index;
        
    public:

        Undo_Redo(){
            index = 0;
        }

        // Getters.
        std::vector<std::vector<Medikament>> getSteps(){
            return this->steps;
        }
        int getIndex(){
            return this->index;
        }

        // Setters.
        void setIndex(int newIndex){
            this->index = newIndex;
        }

        void addStep(std::vector<Medikament> step){
            // Adds a vector(a step) to the vector.
            clearSteps(this->index);
            this->steps.push_back(step);
            this->index++;
        }
        void clearSteps(int from){
            // Clears the unwanted steps after an operation was made.
            this->steps.erase(this->steps.begin() + from, this->steps.end());
        }

        std::vector<Medikament> undo(){
            // Throws an exception if there are no more steps to undo.
            // Goes to the previous step.
            if(this->index == 0){
                throw std::exception();
            }
            if (firstCall()) {
            	--index;
            	return this->steps[--this->index];
            }
            return this->steps[--this->index];
        }

        std::vector<Medikament> redo(){
            // Throws an exception if there are no former steps.
            // Goes to the next step, only if an undo was previously made.
            if (index == steps.size()) {
            	throw std::exception();
            }
            return this->steps[++this->index];
        }

        bool firstCall() {
        	return index == steps.size();
        }
};