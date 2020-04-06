#include <iostream>
#include "Medikament.h"
#include "MedikamentController.h"
using namespace std;

void tasks(){
    // Displays the tasks.
    cout<<"0. Exit."<<'\n';
    cout<<"1. Add medication."<<'\n';
    cout<<"2. Delete medication."<<'\n';
    cout<<"3. Update name."<<'\n';
    cout<<"4. Update concentration."<<'\n';
    cout<<"5. Update price."<<'\n';
    cout<<"6. Update Menge."<<'\n';
    cout<<"7. Show by name."<<'\n';
    cout<<"8. Show by price."<<'\n';
    cout<<"9. Show by Menge."<<'\n';
    cout<<"10. Undo."<<'\n';
    cout<<"11. Redo."<<'\n';
}

void menu(){
    tasks();
	MedikamentController * controller = new MedikamentController();
    int command;
    std::string name;
    double konzentration, preis;
    int menge;

    while (true)
    {      
        // Until we turn it off, we keep executing commands.
        cout<<'\n';  
        cout<<"Introduce a command: ";
        cin>>command;
        if(command == 0){
            return;
        }
        if(command == 1){
            // Add medicine.
            cout<<'\n'<<"Name of medication: ";
            cin>>name;
            cout<<'\n'<<"Concentration: ";
            cin>>konzentration;
            cout<<'\n'<<"Price: ";
            cin>>preis;
            cout<<'\n'<<"Menge: ";
            cin>>menge;
            controller->addMedikament(Medikament(name, konzentration, preis, menge));
        }
        cout<<'\n';
        if(command == 2){
            // Delete medicine.
            cout<<"Which medication do you want to remove?"<<'\n'<<"Introduce name: ";
            cin>>name;
            cout<<'\n'<<"Introduce concentration: ";
            cin>>konzentration;
            controller->removeMedikament(name, konzentration);
        }
        if(command == 3){
            // Replace name.
            cout<<"For what medicine do you want to replace the name?"<<'\n'<<"Introduce name: ";
            cin>>name;
            cout<<'\n'<<"Introduce concentration: ";
            cin>>konzentration;
            cout<<'\n'<<"Introduce new name: ";
            std::string newName;
            cin>>newName;
            controller->modifyMedikament(name, konzentration, newName);
        }
        if(command == 4){
            // Replace concentration.
            cout<<"For what medicine do you want to replace the concentration?"<<'\n'<<"Introduce name: ";
            cin>>name;
            cout<<'\n'<<"Introduce concentration: ";
            cin>>konzentration;
            cout<<'\n'<<"Introduce new concentration: ";
            double newK;
            cin>>newK;
            controller->modifyMedikamentK(name, konzentration, newK);
        }

        if(command == 5){
            // Replace price.
            cout<<"For what medicine do you want to replace the price?"<<'\n'<<"Introduce name: ";
            cin>>name;
            cout<<'\n'<<"Introduce concentration: ";
            cin>>konzentration;
            cout<<'\n'<<"Introduce new price: ";
            double newP;
            cin>>newP;
            controller->modifyMedikamentK(name, konzentration, newP);
        }
        if(command == 6){
            // Replace quantity.
            cout<<"For what medicine do you want to replace the quantity?"<<'\n'<<"Introduce name: ";
            cin>>name;
            cout<<'\n'<<"Introduce concentration: ";
            cin>>konzentration;
            cout<<'\n'<<"Introduce new Menge: ";
            int newM;
            cin>>newM;
            controller->modifyMedikamentK(name, konzentration, newM);
        }
        if(command == 7){
            // Filter by name.
            cout<<"Introduce a name to filter by: ";
            cin>>name;
            vector<string> filterNames = controller->filterByName(name);
            for(string s : filterNames)
		        cout <<'\n'<< s;
        }
        if(command == 8){
            // Group by price.
            vector<string> groups = controller->groupByPreis();
            cout << "Groups: " << endl;
            for(string s : groups)
                cout <<'\n'<< s;
        }
        if(command == 9){
            // Filter by quantity.
            cout<<"Introduce a quantity to filter by: ";
            cin>>menge;
            vector<string> filterMenge = controller->filterByMenge(menge);
            for(string s : filterMenge)
		        cout <<'\n'<< s;
        }
        if(command == 10){
            // Undo, if possible.
            try{
                controller->callUndo();
            }
            catch(...){
                cout<<"Can't undo."<<'\n';
            }
        }
        if(command == 11){
            // Redo, if possible.
            try{
                controller->callRedo();
            }
            catch(...){
                cout<<"Can't redo."<<'\n';
            }
        }
    }
    delete controller;
}

int main(){
    menu();
    return 0;
}