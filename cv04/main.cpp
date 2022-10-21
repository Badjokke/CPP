#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <ranges>
#include <stdexcept>
#include <random>

class Func{
public:
    int operator() (int par) const{
        return 2 * par + 1;
    }
};

/*
class MyException: public std::exception{
private:
    int error_code;
public:
    MyException(int errorCode): error_code{errorCode}{};
    virtual const char* what() const override{
        return "NO FUJ";
    }
    int get_error_code(){
        return this->error_code;
    }
};
*/

std::random_device rdev;
//ukol - home 04.zip
//v zipu
//sunday deadline
int main() {
/*
    int a = 5;
    int b = 10;
    auto lfnc = [](int par, int mul){
        return mul * par + 1;
    };
    auto f = [a,b]()mutable ->int{
        b = a + 1;
        return a*2;
    };
    Func fnc;

    std::cout << f() << std::endl;
    std::cout << lfnc(8,2) << std::endl;

    auto lfnc_2 = std::bind(lfnc, std::placeholders::_1, 2);
    std::cout << lfnc_2(8) << std::endl;
*/
    /*
    std::vector<int> numbers(30);

    std::iota(numbers.begin(),numbers.end(),0);

    std::transform(numbers.begin(),numbers.end(),numbers.begin(),[](int a){
        return 2 * a;
    });
    */

    /*
    std::generate(numbers.begin(),numbers.end(),[num = 1]() mutable{
        num += 2;
        return num;
    });
    */

    /*
    auto numbers = std::ranges::iota_view{1,30}
    | std::views::transform([](int a){return a * 2;});
    for(auto i : numbers)
        std::cout << i << std::endl;
    */
/*
    try{
        MyException ex(10);
        throw ex;
    }
    catch (MyException &ex){
        std::cerr << "nejaka chyba: " << ex.what() << std::endl;
    }
    catch(std::runtime_error ex){
        std::cerr << "nejaka chyba: " << ex.what() << std::endl;
    }
*/


    std::default_random_engine reng(rdev());
    std::uniform_int_distribution<int> kostka(1,6);
    kostka(reng)


    return 0;
}
