#include <iostream>
/*
class Cislo{
private:
    int mCislo = 0;
public:
    Cislo() = default;
    explicit Cislo(int cislo): mCislo{cislo}{};
     Cislo(int a,int b): mCislo{a * b}{};

    int get_cislo() const{
        return mCislo;
    }

    Cislo operator+(const Cislo& other) const{
        return Cislo({this->mCislo+other.mCislo});
    }

    operator int() const{
        return mCislo;
    }
    operator std::string() const{return std::to_string(mCislo);}

    auto operator<=>(const Cislo&b) const{
        return this->mCislo <=> b.get_cislo();
    }
};

void vypis_cislo(Cislo c){
    std::cout << "Cislo je " << c.get_cislo() << std::endl;
}

Cislo secti_cisla(const Cislo& c1, const Cislo& c2){
    return c1 + c2;
}
*/

class Vector2D{
private:
    double x = 0;
    double y = 0;
public:
     Vector2D(double x, double y):x{x},y{y}{};

    Vector2D operator+ (const Vector2D& other) const{
        return Vector2D({this->x + other.x, this->y + other.y});
    }

    Vector2D operator+= (const Vector2D& other){
        this->x += other.x;
        this->y += other.y;
    }
    friend std::ostream& operator <<(std::ostream& stream, const Vector2D& vec){
            return std::cout << "Vektor2D " << vec.x <<" " << vec.y << std::endl;
    };


    double operator*(const Vector2D& other)const{
        double skalar = this->x * other.x + this->y * other.y;
        return skalar;
    }


};
int main (int argc, char **argv){
    Vector2D vec(5.0,10.0);
    Vector2D vec2 (5,10);
    Vector2D vec3 = vec +  vec2;
    vec += vec3;
    std::cout << "Novy vektor souctem" << std::endl;
    std::cout << vec3 << std::endl;
    std::cout << "Skalar vektoru: \n"<<vec << vec2 << vec * vec2 << std::endl;
    std::cout << "+= vektor" << vec;




/*
    Cislo a(8);
    Cislo b(5);
    int c = a + b;


    vypis_cislo(a);
    vypis_cislo(b);
    vypis_cislo(Cislo(42));
    vypis_cislo({5,5});
*/


    return 0;
}