#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <math.h>

#define DOC "doc.txt"
#define COD "cod.txt"
#define SUD "sudo.txt"
int n=4; //semilla de codificacion

using namespace std;

void codificacion(int );//Realiza el proceso de la codificacion de un txt.
int counterDigits(int );
void aBinario(int ,char * );
int potencia(int , int );
void decodificacion(int,string );
bool esAdmin();
void agregarUsuario();
void usuarios();

ifstream leer;
ofstream guardar;

int main()
{
    //Menú.
    int opcion1=0;
    bool trabajando=true;
    while(trabajando==true){
        cout<<"Bienvenido"<<endl;
        cout<<"Indique el tramite que desea realizar:"<<endl;
        cout<<"1.Acceder como administrador"<<endl;
        cout<<"2.Acceder como usuario"<<endl;
        cout<<"Ingrese cualquier otro valor para salir"<<endl;
        cin>>opcion1;
        system("CLS");
        switch(opcion1){
        case 1:{
            bool siEs=esAdmin();
            if(siEs==false)
                cout<<"Contrasena de administrador incorrecta."<<endl<<endl;
            else{
                int opcion2=0;
                while(true){
                    cout<<"Ingrese el numero 1 si desea registrar a un usuario"<<endl;
                    cout<<"De lo contrario ingrese otro valor para regresar al menu anterior"<<endl;
                    cin>>opcion2;
                    if(opcion2==1){
                        decodificacion(n,COD);
                        guardar.open(DOC,ios::app);
                        string cedula,contrasena,saldo;
                        cout<<"Ingrese la cedula del usuario:"<<endl;
                        cin>>cedula;
                        cout<<"Ingrese la contraseña del usuario:"<<endl;
                        cin>>contrasena;
                        cout<<"Ingrese el saldo actual del usuario:"<<endl;
                        cin>>saldo;
                        guardar<<cedula<<','<<contrasena<<','<<saldo<<endl;
                        guardar.close();
                        codificacion(n);
                    }
                    else break;
                    system("CLS");
                }
            }
            break;
        }
        case 2:{
            usuarios();
            break;
        }
        default:{
            trabajando=false;
            break;
        }
        }
    }
    //codificacion(n);
    //string archi=COD;
    //decodificacion(n, COD);
    return 0;
}

void codificacion(int n){
    try {
        remove(COD);
        string linea;
        leer.open(DOC);
        if(!leer.is_open())
            throw '1';
        guardar.open(COD,ios::out);
        if(!guardar.is_open())
            throw '2';
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

        //metodo codificacion

        leer.open(COD);
        if(!leer.is_open())
            throw '3';
        guardar.open("temp.txt",ios::out);
        if(!guardar.is_open())
            throw '4';
        char numeroTemp[n], numeroFinal[n];
        string value;
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
        remove(DOC);

    }  catch (char c) {
        if(c=='1')
            cout<<"Problema con la lectura del archivo doc.txt"<<endl;
        else if(c=='2')
            cout<<"Problema para el guardado en el archivo cod.txt"<<endl;
        else if(c=='3')
            cout<<"Problema con la lectura del archivo cod.txt"<<endl;
        else if(c=='4')
            cout<<"Problema para guardar en el archivo temp.txt"<<endl;
        else
            cout<<"Error inesperado"<<endl;
    }


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

void decodificacion(int n,string codificado){
    try {
        ofstream temp;
        leer.open(codificado);
        if(!leer.is_open())
            throw '1';
        guardar.open(DOC,ios::out);
        if(!guardar.is_open())
            throw '2';
        temp.open("temp.txt",ios::out);
        if(!temp.is_open())
            throw '3';
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
            if(!leer.is_open())
                throw '4';
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
    catch (char c) {
        if(c=='1')
            cout<<"Problema con la lectura del archivo cod.txt"<<endl;
        else if(c=='2')
            cout<<"Problema con el guardado en el archivo doc.txt"<<endl;
        else if(c=='3')
            cout<<"Problema con el guardado en el archivo temp.txt usando temp"<<endl;
        else if(c=='4')
            cout<<"Problema con la lectura del archivo temp.txt"<<endl;
        else
            cout<<"Error inesperado";
    }


}

bool esAdmin(){
    bool es=true;
    try {
        string contrasena;
        cout<<"Ingrese la contrasena de administrador: "<<endl;
        cin>>contrasena;
        string archi=SUD;
        decodificacion(n,archi);
        leer.open(DOC);
        if(!leer.is_open())
            throw '1';
        string contraReal;
        getline(leer,contraReal);
        if(contraReal!=contrasena)
            es=false;
        leer.close();
        remove(DOC);
    }  catch (char c) {
        if(c=='1')
                cout<<"Error con la lectura de sudo.txt"<<endl;
    }
    return es;
}

void usuarios(){
    string cedula,contrasena,saldo;
    cout<<"Ingrese su numero de cedula"<<endl;
    cin>>cedula;
    cout<<"Ingrese su contrasena"<<endl;
    cin>>contrasena;
    system("CLS");
    decodificacion(n, COD);
    try {
        string splitted[3];
        string linea;
        bool encontrado=false;
        int fila=-1;
        leer.open(DOC);
        if(!leer.is_open())
            throw '1';
        while(getline(leer,linea)){
            int pini=0,pfin=0;
            for(int i=0;i<3;i++){
                if(i<2){
                    pfin=linea.find(',',pini);
                    splitted[i]=linea.substr(pini,pfin-pini);
                    pini=pfin+1;
                }
                else
                    splitted[i]=linea.substr(pini);
            }
            fila+=1;
            if(cedula==splitted[0] and contrasena==splitted[1]){
                encontrado=true;
                break;
            }
        }
        leer.close();
        if(encontrado==false)
            cout<<"Ha ingresado los datos incorrectos, intentelo nuevamente"<<endl;
        else{
            int opcion=0;
            string saldostr=splitted[2];
            int longitud=saldostr.length()-1;
            int saldo=0;
            for(int i=0,j=0;i<longitud;i++){
                j=saldostr[i];
                saldo=saldo+((j-48)*potencia(10,longitud-i));
            }
            if(saldo<1000){
                cout<<"Saldo insuficiente para consultar o retirar";
                leer.close();
                guardar.close();
                remove(DOC);
            }
            else{
                cout<<"Indique el proceso que desea realizar: "<<endl;
                cout<<"1.Consultar saldo."<<endl;
                cout<<"2.Retirar dinero especificando la cantidad deseada"<<endl;
                cin>>opcion;
                switch (opcion) {
                case 1:{
                    cout<<saldo<<endl;
                    saldo-=1000;
                    system("PAUSE");
                    break;
                }
                case 2:{
                   cout<<"Cuanto dinero desea retirar?"<<endl;
                   int retiro=0;
                   cin>>retiro;
                   cout<<"transaccion realizada"<<endl;
                   saldo-=retiro;
                   system("PAUSE");
                   break;
                }
                }
                guardar.open("temp.txt",ios::out);
                if(!guardar.is_open())
                    throw '2';
                leer.open(DOC);
                if(!leer.is_open())
                    throw '1';
                int filaArchivo=0;
                while(getline(leer,linea)){
                    if(filaArchivo==fila){
                        guardar<<splitted[0]<<','<<splitted[1]<<','<<saldo<<endl;
                    }
                    else{
                        guardar<<linea<<endl;
                    }
                    filaArchivo+=1;
                }
                leer.close();
                guardar.close();
                remove(DOC);
                rename("temp.txt",DOC);
                codificacion(n);
                remove(DOC);
            }
        }

    }  catch (char c) {
        if(c=='1')
            cout<<"Error con la lectura del archivo doc.txt"<<endl;
        if(c=='2')
            cout<<"Error para guardar en temp.txt"<<endl;

    }

}
