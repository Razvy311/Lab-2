#pragma once

#include "Medikament.h"
#include <vector>
#include <exception>

class Undo_Redo{
    private:
    	std::vector<std::vector<Medikament *>> steps;
        int index;
        
    public:
        bool flag = false;

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
            this->steps.push_back(step);
        }
        void clearSteps(int from){
            this->steps.erase(this->steps.begin() + from, this->steps.end());
        }

        std::vector<Medikament *> undo(){
            if(this->index < 0){
                throw std::exception();
            }
            flag = true;
            if(this->index == 0){
                this->index--;
                return this->steps[0];
            }
            this->index--;
            return this->steps[this->index];
        }

        std::vector<Medikament *> redo(){
            if(!flag){
                this->clearSteps(this->index + 1);
            }
            if(this->index >= this->steps.size() || !flag){
                throw std::exception();
            }
            this->index++;
            return this->steps[this->index];
        }
};