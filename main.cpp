#include "inout.h"
#include <cmath>
#include "bod.h"
int comp(const void *prva,const void *druha );
using namespace inout;
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
     }*/
    Bod2D A(1,2);
    Bod2D B(3,7);
    Usecka AB(A,B);
    cout<<AB;
    AB.getVseobecna();
    AB.getParametricka();
    (Usecka::VR)AB;
    (Usecka::PR)AB;

    return 0;
}

float Bod2D::getDistance(const Bod2D &other) const
{
    return (float)sqrt(pow(x-other.x, 2)+pow(y-other.y, 2));
}

Bod2D Bod2D::getCenterPoint(const Bod2D &other) const {
    return {(x + other.x) / 2,(y + other.y) / 2};
}

Bod2D Bod2D::operator+(const Bod2D &other) const {
    return {x+other.x, y+other.y};
}

Bod2D Bod2D::operator-(const Bod2D &other) const {
    return {x-other.x, y-other.y};
}

Bod2D Bod2D::operator*(float n) const {
    return {x*n, y*n};
}

Bod2D Bod2D::operator/(float n) const {
    return {x/n, y/n};
}

std::ostream &operator<<(std::ostream &os, const Bod2D &bod) {
    os << "[" << bod.x << "," << bod.y << "]";
    return os;
}

Bod2D operator*(float n, const Bod2D &other) {
    return {other.x*n, other.y*n};
}

void Bod2D::getMinDistance(std::istream &is)
{
    Bod2D A;
    Bod2D B;
    is>>A>>B;
    Bod2D Temp1;
    Bod2D Temp2;
    float min = A.getDistance(B);
    float tmp;
    for (int i = 0; i < 99; ++i)
    {
        if(is>>A>>B,(tmp=A.getDistance(B)) < min)
        {
            Temp1=A;
            Temp2=B;
            min=tmp;
        }
    }
    std::cout<<"Najmensia vzdialenost je "<<min<<" bodov "<<Temp1<<" "<<Temp2;
}

void Bod2D::getSortedDistance(std::istream &is, std::ofstream &os)
{
    Usecka Usecky[100];
    for(auto & i : Usecky)
    {
        is>>i;
    }
    qsort(Usecky,100,sizeof(Usecka),comp);
    std::cout<<"Utriedene podla velkosti"<<std::endl;
    for(int i=0;i<100;++i)
    {
        std::cout<<(float )Usecky[i]<<" "<<Usecky[i];
        os<<(float)Usecky[i]<<" "<<Usecky[i];
    }
}

std::istream &operator>>(std::istream &is, Bod2D &bod) {
    is >> bod.x>>bod.y;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Usecka &usecka)
{
    os<<"Usecka je dana bodmi:"<<usecka.X<<usecka.Y<<std::endl;
    return os;
}

bool Usecka::operator<(const Usecka &other) const
{
    return  (float)(*this)<(float)other;
}

float Usecka::getDlzka() const
{
    return X.getDistance(Y);
}

std::istream &operator>>(std::istream &is, Usecka &usecka)
{
    is>>usecka.X>>usecka.Y;
    return is;
}

bool Usecka::operator>(const Usecka &other) const
{
    //return (float)(*this)>(float)other;
    return this->getDlzka()>other.getDlzka();
}

Vektor Usecka::getNormalovy() const
{
    Vektor tmp =Y-X;
    return {-tmp.getY(),tmp.getX()};
}

Vektor Usecka::getSmerovy() const
{
    return Y-X;
}

Bod2D Usecka::getCenter() const
{
    return (X+Y)/2;
}

int comp(const void *prva,const void *druha )
{
    auto * A = (Usecka *)prva;
    auto * B = (Usecka *)druha;
    return ((*A)<(*B))?1:((*A)>(*B))?-1:0;
}

std::ostream &operator<<(std::ostream &os, const Usecka::VR &other)
{
    os<<"Vseobecna rovnica:"<<setw(4)<<other[0]<<"x"<<std::showpos<<setw(4)<<other[1]<<"y"<<std::showpos<<setw(4)<<other[2]<<" = 0"<<endl;
    return os;
}

Usecka::VR Usecka::getVseobecna() const
{
    float a = this->getNormalovy().getX();
    float b = this->getNormalovy().getY();
    float c= -a*X.getX()-b*X.getY();
    cout<<Usecka::VR(a, b, c);
    return {a,b,c};
}

Usecka::operator VR() const
{
    return getVseobecna();
}

Usecka::operator float() const
{
    return X.getDistance(Y);
}

std::ostream &operator<<(std::ostream &os, const Usecka::PR &other)
{
    os<<"Parametricka rovnica:"<<std::endl<<"x = "<<setw(4)<<std::noshowpos<<other[0]<<std::showpos<<setw(4)<<other[1]<<"*t"<<std::endl<<"y = "<<setw(4)<<std::noshowpos<<other[2]<<std::showpos<<setw(4)<<other[3]<<"*t"<<"   t je z R"<<std::endl;
    return os;
}

Usecka::PR Usecka::getParametricka() const
{
    Vektor smerovy = this->getSmerovy();
    float s1=smerovy.getX();
    float s2 =smerovy.getY();
    float a1=X.getX();
    float a2=X.getY();
    std::cout<<Usecka::PR(a1, s1, a2, s2);
    return {a1, s1, a2, s2};
}

Usecka::operator PR() const
{
    return getParametricka();
}
