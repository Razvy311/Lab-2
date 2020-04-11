#include <string>

class Film{
    private:
        std::string titel, genre, linkTrailer;
        int erscheinungsjahr, anzahlLikes;

    public:

        // Constructor for the class.
        Film(std::string titel, std::string genre, int erscheinungsjahr, int anzahlLikes, std::string trailer);

        // Getters.
        std::string getTitel();
        std::string getGenre();
        int getErscheinungsjahr();
        int getAnzahlLikes();
        std::string getLinkTrailer();

        // Setters.
        void setTitel(std::string newTitel);
        void setGenre(std::string newGenre);
        void setErscheinungsjahr(int newErscheinungsjahr);
        void setAnzahlLikes(int newLikes);
        void setLinkTrailer(std::string newLink);

        // String.
        std::string showFilm();
};