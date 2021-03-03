#include "inout.h"
#include "bod.h"

int main()
{
/*   std::ifstream fin;
     std::ofstream fout;
     try
     {
         fin.open("suradnice.txt");
         if (!fin.is_open())
         {
             throw ("Nepodarilo sa otvorit vstupny subor!");
         }
         fout.open("zapis.txt");
         if(!fout.is_open())
         {
             throw ("Nepodarilo sa otvorit subor na zapis!");
         }
         //Bod2D::getMinDistance(fin);
         //fin.close();
         //fin.open("suradnice.txt");
         Bod2D::getSortedDistance(fin,fout);
         fin.close();
         fout.close();
     }
     catch (const char *ex)
     {
         std::cout << ex;
     }

    Bod2D A(1,3);
    Bod2D B(3,7);
    Usecka AB(A,B);
    Usecka CD({5,8},{2,12});
    cout<<AB.getPoloha(CD);
    AB.getOsUhla(CD);*/
    using namespace inout;
    Trojuholnik ABC{{1,10},{8,10},{5,15}};
    //Trojuholnik KLM;
    ABC.ukazStrany();
    ABC.ukazUhly();
    cout<<"Tazisko:"<<ABC.getTazisko()<<endl;
    cout<<"Ortocentrum:"<<ABC.getOrtocentrum()<<endl;
    return 0;
}
