#include <iostream>
using namespace std;
class Matrice
{
private :

    float A[100][100];
    int n,m;
public:
    /*  void afisare()
      {
          cout<<n<<m;


      }*/
///calculeaza determinantul unei matrice,doar daca este patratica wink onii chan
/// uitat formula recupereaza maine pe caiet vezi cum faci

    float deterstart();
    int adaugand();

/// inversa unei matrici nu am idee cum inca :\
/// or int or void nustiu
    Matrice inversastart();
    int impartireainminori();
/// transpusa DONE
    void transpusa(const Matrice &ob);

///inca mai am de lucru la inversa, am presupus ca +,- sunt simple fata de adunare si det unde trebuie sa gasesti si anumite tampenii
    friend istream& operator>>(istream &input,Matrice &obj);
    friend ostream& operator<<(ostream &output,const Matrice &obj);
    void afisare();

    friend operator*(const Matrice &obj,const Matrice &obie);
    friend operator-(const Matrice &obj,const Matrice &obie);
    friend operator+(const Matrice &obj,const Matrice &obie);



};
