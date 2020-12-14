#include <iostream>

class Matrix
{
private:
    double **M;
    int n, m; //n-rows m-cols
public:
    // dodatkowy konstruktor jako argument przyjmujący ścieżkę do pliku o podanym wcześniej formacie i na jego podstawie tworzący nową macierz na podstawie przekazanego pliku
    Matrix(std::string path);
    // przyjmujący dwa argumenty typu int tworzący macierz o podanych wymiarach zainicjalizowaną zerami
    Matrix(int n, int m){
        M= new double* [n];
        for(int z=0; z<n; z++){
            M[z]= new double [m];
        }
    }

    // przyjmujący jeden argument typu int tworzący macierz kwadratową o podanym rozmiarze zainicjalizowaną zerami
    Matrix(int n){
        M= new double* [n];
        for(int z=0; z<n; z++){
            M[z]= new double [n];
        }
    }

    ~Matrix(){
        for(int z=0;z<n; z++){
            delete[] M[z];
        }
        delete[] M;
    }

    // set(n, m, val) - metoda ustawiająca wartość elementu (n, m) na val
    void set(int n, int m, double val){
        M[n][m] = val;
    }

    // get(n, m) - metoda pobierająca element (n, m)
    double get(int n, int m){
        return M[n][m];
    }

    // add(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą sumą bieżącej macierzy oraz macierzy przekazanej jako argument
    Matrix add(Matrix& m2){
        for(int w=0;w<n;w++){
            for(int s=0;s<n;s++){
                Matrix res_m[w][s] = m2 + M;
            }
        }
    }

    // subtract(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą różnicą bieżącej macierzy oraz macierzy przekazanej jako argument
    //Matrix subtract(Matrix& m2);

    // multiply(Matrix m2) - metoda przyjmująca jako argument inną macierz i zwracająca jako wynik nową macierz będącą iloczynem bieżącej macierzy oraz macierzy przekazanej jako argument
    //Matrix multiply(Matrix& m2);

    // cols() - metoda zwracająca liczbę kolumn macierzy
    int cols(){
        return m;
    }

    // rows() - metoda zwracająca liczbę wierszy macierzy
    int rows(){
        return n;
    }

    // print() - metoda wyświetlająca macierz na ekranie
    // https://invisible-island.net/ncurses/announce.html
    void print();

    // store(std::string filename, std::string path) - metoda zapisująca macierz w pliku; w pliku powinny być zapisane wymiary macierzy (liczba kolumn i liczba wierszy w pierwszym wierszu pliku) oraz jej zawartość (każdy wiersz macierzy w osobnym wierszu pliku)
    bool store(std::string filename, std::string path);

};

int main()
{
    // należy dodać metodę main (chodzi o funkcję int main(){}) pokazującą działanie wszystkich powyższych metod na przykładzie macierzy o rozmiarze co najmniej 4 (należy zademonstrować działanie wszystkich konstruktorów).

}
