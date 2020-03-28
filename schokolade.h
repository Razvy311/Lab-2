#include <string>

class Schokolade{
    private:
        std::string name, typ;
        double preis;

    public:

        // Constructor.
        Schokolade(std::string name, std::string typ, double preis);
        // Destructor.
        ~Schokolade();

        // Getters.
        std::string getName();
        std::string getTyp();
        double getPreis();

        // Setters.
        void setName(std::string newName);
        void setTyp(std::string newTyp);
        void setPreis(double neuPreis);
};