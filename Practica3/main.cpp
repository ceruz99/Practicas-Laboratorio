#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <math.h>

#define DOC "doc.txt"
#define COD "cod.txt"

using namespace std;

void codificacion(int );//Realiza el proceso de la codificacion de un txt.
int counterDigits(int );
void aBinario(int ,char * );
int potencia(int , int );
void metodoCodificacion(int );
void decodificacion(int );

ifstream leer;
ofstream guardar;

int main()
{   int n=4;
    //codificacion(n);
    decodificacion(n);
    return 0;
}

void codificacion(int n){
    string linea;
    leer.open(DOC);
    guardar.open(COD,ios::out);
    string num;
    int decimal=0;
    while(getline(leer,linea)){
        int longitud=linea.length();
        for(int i=0;i<longitud;i++){
                num=linea.substr(i,1);
                decimal=num[0];
                char *p=new char[8];
                aBinario(decimal,p);
                for(int j=0;j<8;j++){
                    guardar<<*(p+j);

                }
                delete[] p;
        }
        guardar<<endl;
    }
    leer.close();
    guardar.close();
    metodoCodificacion(n);
}

void aBinario(int n,char *p ){
    int dato=n, result=0;
    for(int i=0;i<8;i++){
        if((dato%2)!=0) result+=1*potencia(10,i);
        dato=dato/2;
    }
    int lenght=counterDigits(result);
    for(int i=7;i>=0;i--){
        if(i>lenght-1){
            p[7-i]='0';
        }
        else{
            p[7-i]=(result/potencia(10,i))+48;
            result=result%potencia(10,i);
        }
    }
}

void metodoCodificacion(int n ){
    leer.open(COD);
    guardar.open("temp.txt",ios::out);
    char numeroTemp[n], numeroFinal[n];
    string linea,value;
    while(getline(leer,linea)){
        int longitud=linea.length(),position=0;
        for(int i=0;i<longitud/n;i++){
            for(int j=0;j<n;j++){
                value=linea.substr(position,1);
                numeroTemp[j]=value[0];
                position+=1;
            }
            for(int j=0,k=-1;j<n;j++,k++){
                if(j==0) numeroFinal[j]=numeroTemp[n-1];
                else numeroFinal[j]=numeroTemp[k];
            }
            for(int j=0;j<n;j++){
                guardar<<numeroFinal[j];
            }
        }
        for(int i=0;i<(longitud%n);i++){
            guardar<<linea.substr(position,1);
            position+=1;
        }
        guardar<<endl;
    }
    leer.close();
    guardar.close();
    remove(COD);
    rename("temp.txt",COD);
    cout<<"El archivo doc.txt se ha codificado y ahora se llama cod.txt"<<endl;
}

int counterDigits(int a){
    int count=1;
    while(a>9){
        a=a/10;
        count+=1;
    }
    return count;
}

int potencia(int a, int b){
    int resultado=1;
    for(int i=0; i<b; i++)
    {
        resultado*=a;
    }
    return resultado;
}

void decodificacion(int n){
    ofstream temp;

    leer.open(COD);
    guardar.open("doc.txt",ios::out);
    temp.open("temp.txt",ios::out);
    char numeroTemp[n], numeroFinal[n];
    string linea,value;
    while(getline(leer,linea)){
        int longitud=linea.length(),position=0;
        for(int i=0;i<longitud/n;i++){
            for(int j=0;j<n;j++){
                value=linea.substr(position,1);
                numeroTemp[j]=value[0];
                position+=1;
            }
            for(int j=0,k=-1;j<n;j++,k++){
                if(j==0) numeroFinal[n-1]=numeroTemp[j];
                else numeroFinal[k]=numeroTemp[j];
            }
            for(int j=0;j<n;j++){
                temp<<numeroFinal[j];
            }
        }
        for(int i=0;i<(longitud%n);i++){
            temp<<linea.substr(position,1);
            position+=1;
        }
        temp<<endl;
    }
    temp.close();
    leer.close();
    leer.open("temp.txt",ios::out);
    while(getline(leer,linea)){
        char letra;
        int position=0,decimal=0;
        int longitud=linea.length();
        for(int i=0;i<longitud/8;i++){
            decimal=0;
            for(int j=0;j<8;j++){
                if(linea.substr(position,1)=="1") decimal=decimal+potencia(2,7-j);
                position+=1;
            }
            letra=decimal;
            guardar<<letra;
        }
        guardar<<endl;
    }

    leer.close();
    guardar.close();
    remove("temp.txt");

}
