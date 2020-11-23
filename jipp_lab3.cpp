#include <iostream>
using namespace std;

template <typename T>
class double_Matrix
{
private:
    int n; //rows
    int m; //cols
    T** M;// macierz
public:
    //konstruktory

//    double_Matrix(int a)
//    {
//        n=m=a;
//        for (int i = 0; i < n; i++){
//            M[i] = (T*)new T[m];
//        }
//        for(int i=0; i<n; i++){
//            for(int j=0; j<m; j++){
//                M[i][j]=0;
//            }
//        }
//    }

    double_Matrix(int _n, int _m)
    {
        n = _n;
        m = _m;
        M = (T**) new T*[n];
        for (int i = 0; i < n; i++){
            M[i] = (T*)new T[m];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                M[i][j]=0;
            }
        }
    }

    void set(int valueN, int valueM, double val)
    {
        n = valueN;
        m = valueM;
        M[n][m] = val;
    }

    double get(int valueN, int ValueM)
    {
        n = valueN;
        m = ValueM;
        return M[n][m];
    }

    //metody
    double add(double_Matrix m2)
    {
        double_Matrix wynik[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                wynik[i][j] = M[i][j] + m2[i][j];
            }
        }
        return wynik;
    }

    double substract(double_Matrix m2)
    {
        double_Matrix wynik[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                wynik[i][j] = M[i][j] - m2[i][j];
            }
        }
        return wynik;
    }

    double multiply(double_Matrix m2)
    {
        double_Matrix wynik[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                wynik[i][j] = 0;
                for(int k=0; k<m; k++){
                    wynik[i][j] += M[i][j] * m2[j][i];
                }
            }
        }
        return wynik;
    }

    int cols()
    {
        return m;
    }

    int rows()
    {
        return n;
    }

    void print()
    {
        int rows = n;
        int cols = m;
        for(int i=0; i<rows;i++){
            for(int j=0; j<cols; j++){
                cout<< M[i][j] <<"\t";
            }
            cout<<endl;
        }
    }
};

int main()
{
    double_Matrix<double> Macierz1(2,3);
    for(int i=0;i<2;i++){
        for(int j=0; j<3;j++){
            Macierz1.set(i,j,i+j);
        }
    }
   double_Matrix<double> Macierz2(2,3);
   for(int i=0;i<2;i++){
       for(int j=0; j<3;j++){
           Macierz2.set(i,j,i*j);
       }
   }
   Macierz1.add(Macierz2);
    Macierz1.print();

}

