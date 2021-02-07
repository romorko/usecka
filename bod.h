
class Bod2D{
private:
    float x;
    float y;
public:
    Bod2D():x(0),y(0){};
    explicit Bod2D(float val):x(val),y(val){};
    Bod2D(float valX, float valY):x(valX),y(valY){};
    float getX()const{return x;} ;
    float getY()const{return y;} ;
    float getDistance(const Bod2D & other = Bod2D(0,0)) const;
    Bod2D getCenterPoint(const Bod2D & other) const;
    void setX(float valX){x=valX;};
    void setY(float valY){y=valY;};
    Bod2D operator+(const Bod2D & other) const;
    Bod2D operator-(const Bod2D & other) const;
    Bod2D operator*(float n) const;
    Bod2D operator/(float n) const;

    friend Bod2D operator*(float n, const Bod2D & other);
    friend std::ostream & operator<<(std::ostream & os, const Bod2D & bod);
    friend std::istream & operator>>(std::istream & is, Bod2D & bod);
    static void getMinDistance(std::istream & is);
    static void getSortedDistance(std::istream & is, std::ofstream &os);
};

using Vektor = Bod2D;

class Usecka
{
    private:
    Bod2D X{0, 0};
    Bod2D Y{0, 0};
public:
    class VR
    {
    private:
        float koeficienty[3];
    public:
        VR(float ka, float kb, float kc):koeficienty{ka,kb,kc}{};
        friend std::ostream &operator<<(std::ostream & os,const VR & other);
        float & operator[](int index){return koeficienty[index];};
        const float & operator[](int index) const{return koeficienty[index];}
    };
    class PR
    {
    private:
        float koeficienty[4];
    public:
        PR(float ka1,float kv1,float ka2,float kv2):koeficienty{ka1,kv1,ka2,kv2}{};
        float & operator[](int index){return koeficienty[index];};
        const float & operator[](int index) const{return koeficienty[index];}
    };

    Usecka(){};
    Usecka(Bod2D A, Bod2D B) : X(A), Y(B){};
    explicit Usecka(Bod2D A) : X(A), Y(A){};
    friend std::ostream &operator<<(std::ostream &os, const Usecka &usecka);
    friend std::istream &operator>>(std::istream &is, Usecka &usecka);
    bool operator<(const Usecka &other) const;
    bool operator>(const Usecka &other) const;
    operator VR() const;  //konverzia na vseobecnu rovnicu
    operator float() const; //konverzia na float t.j. na velkost usecky
    float getDlzka() const;
    Vektor getNormalovy() const;
    Vektor getSmerovy() const;
    Bod2D getCenter() const;
    VR getVseobecna() const;

};
