#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>


using namespace std;

double desviacion(double promedio){
    ifstream archivo("numeros.txt",ios::in);// Se abre el archivo en modo lectura
    string linea;
    double numeros=0;
    double desvia=0,varianza=0,contador=0;
    while(!archivo.eof()){
        archivo>>linea;
        linea[1]='.';
        numeros=(double)atof(linea.c_str());
        varianza+=pow((numeros - promedio), 2.0);
    }
    desvia=sqrt(varianza/(contador-1));
    return desvia;

}

//double moda


int main(){
    ifstream archivo("numeros.txt",ios::in);// Se abre el archivo en modo lectura
    string linea;
    double numeros=0;
    double promedio=0,suma=0;
    double contador=0;



    if(archivo.fail()){
        cout<<"No se pudo imprimir el archivo"<<endl;
        exit(1);
    }
    while(!archivo.eof()){// mientras no sea el final del archivo sigue leeyendo el archivo
        archivo >> linea;
        linea[1]='.';
        numeros =(double)atof(linea.c_str());
        suma=suma+numeros;
        contador++;

    }
    promedio=(suma/contador)*(-1);
    double desvia =0;
    /*double desviacion=0,varianza=0;
    while(!archivo.eof()){
        archivo>>linea;
        linea[1]='.';
        numeros=(double)atof(linea.c_str());
        varianza+=pow((numeros - promedio), 2.0);
    }
    desviacion=sqrt(varianza/(contador-1));*/
    desvia= desviacion(promedio);
    contador=contador*(-1);
    promedio=promedio*(-1);
    cout<<"esta es la cantidad de elementos dentro del archivo"<<contador<<endl;
    cout<<"La suma de los elemesntos es:"<<suma<<endl;
    cout<<"El promedio de los elementos es:"<<promedio<<endl;
    cout<<"Desviacion estandar es:"<<desvia<<endl;


    return 0;
}


