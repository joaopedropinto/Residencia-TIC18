#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){

    float minValue = numeric_limits<float>::min();
    float maxValue = numeric_limits<float>::max();

    cout << "Menor valor float: " << minValue << endl;
    cout << "Maior valor float: " << maxValue << endl;

    float pif = M_PI;

    double pid = M_PI;

    long double pilf = M_PI;

    std::cout << std::fixed << std::setprecision(22);
    cout << "Pi com o máximo de casas decimais em float(22): " << pif << endl;
    std::cout << std::fixed << std::setprecision(48);
    cout << "Pi com o máximo de casas decimais em double(48): " << pid << endl;
    std::cout << std::fixed << std::setprecision(66);
    cout << "Pi com o máximo de casas decimais em long(66): " << pilf << endl;
    //Não houve diferença ao usar double ou long double.

    std::cout << std::fixed << std::setprecision(2);
    cout << "Pi com 2 casas decimais em float: " << pif << endl;
    cout << "Pi com 2 casas decimais em double: " << pid << endl;

    std::cout << std::fixed << std::setprecision(4);
    cout << "Pi com 4 casas decimais em float: " << pif << endl;
    cout << "Pi com 4 casas decimais em double: " << pid << endl;

    std::cout << std::fixed << std::setprecision(8);
    cout << "Pi com 8 casas decimais em float: " << pif << endl;
    cout << "Pi com 8 casas decimais em double: " << pid << endl;

    //Começa a mostrar diferenças nos valores a partir de 8 casas decimais, pois o float começa a perder a precisão

    std::cout << std::fixed << std::setprecision(16);
    cout << "Pi com 16 casas decimais em float: " << pif << endl;
    cout << "Pi com 16 casas decimais em double: " << pid << endl;
    
    return 0;

}