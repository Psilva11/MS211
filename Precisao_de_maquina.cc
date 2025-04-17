#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>

float precisao_float();
double precisao_double();

int main(){
    double Dval;
    float Fval;

    double Da = 1;
    float Fa = 1;

    std::cout<<"Valor de referência: "<<std::endl;
    std::cin>>Dval>>Fval;

    double Ds = Da + Dval;
    float Fs = Ds + Fval;
    
    while(Ds>Dval){
        Da = Da/2;
        Ds = Dval + Da;
    }

    while(Fs>Fval){
        Fa = Fa/2;
        Fs = Fval + Fa;
    }

    /* Acredito que o motivo de multiplicar por 2 seja por conta da definição do erro absoluto e relativo
       que ficam dividos por 2;
       E acredito que o motivo para conforme maior o valor do número de referência, menor a precisão é que
       ao aumentarmos o número de referência chegamos próximo do limite superior da mantissa, fazendo uma
       soma que da resultados imprecisos por aritmetica de ponto flutuante;
    */

    double double_p = 2*Da;
    float float_p = 2*Fa;

    std::cout<< "Precisões com referência 1:\n" << "Double: " << precisao_double() << "\nFloat: " << precisao_float() << std::endl;
    std::cout<< "Precisões com referência dada:\n" << "Double: " << double_p << "\nFloat: " << float_p << std::endl;

    return 0;
}

float precisao_float(){
    float A = 1;
    float s = 2;

    while(s>1){
        A /= 2;
        s = 1+A;
    }

    return 2*A;
}

double precisao_double(){
    double A = 1;
    double s = 2;

    while(s>1){
        A /= 2;
        s = 1+A;
    }

    return 2*A;
}
