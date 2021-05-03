/* Practica 2 Juan Camilo Mazo Castro grupo 6.
Problemas realizados:
3,5,7,8,9,11,13,16,17*/

#include <iostream>


using namespace std;
void problema8();
void problema9();
int lengthArrayInt(int []);//Cuenta la cantidad de digitos en un arreglo de tipo entero.
int counterDigits(int );//Cuenta la cantidad de digitos que tiene un entero.
void makeArrayInt(int *,int ,int );//Genera un arreglo de enteros a partir de un dato de tipo entero.
int potencia(int , int );//Toma un numero a y lo eleva a un exponente b
bool comparison(char [], char [], int );//Toma dos arreglos char y verifica si ambos son iguales.
int lengthArrayChar(char []);//Indica cual es la medida de un arreglo tipo char.
void makeArrayInt(int *,int ,int );//Realiza un arreglo con los digitos de un entero.
void problem7();//Toma un arreglo char e imprime el arreglo sin los caracteres repetidos.
void problem11();//Enseña las reservas en una sala de cine y permite hacer reservas y cancelarlas.
void numberStars(int **,int ,int );//Toma la matriz e indica cuántas estrellas hay en ella.
void problem16();//Recibe un numero n para crear la matrix nxn e indicar el numero de caminos en esta.
unsigned long int sumDivisor(unsigned long int );//Toma un numero y suma sus divisores exceptuando el mismo numero.

int main()
{
    int i=-1;
    while (i!=0) {
        cout<<"Introduzca el numero del problema que desea observar o ingrese 0 para salir: "<<endl;
        cin>>i;
        switch (i) {
        case 0:{
            i=0;
            break;
        }
        case 3:{
            char word1[25]; char word2[25];
            cout<<"Ingrese la primera palabra "<<endl; cin>>word1;
            cout<<"Ingrese la segunda palabra "<<endl; cin>>word2;
            if(lengthArrayChar(word1)!=lengthArrayChar(word2)) cout<<"Las palabras son diferentes "<<endl;
            else{
                if(comparison(word1,word2,lengthArrayChar(word1))==true) cout<<"Las palabras son iguales "<<endl;
                else
                    cout<<"Las palabras son diferentes "<<endl;
            }
            cout<<word1<<endl;
            cout<<word2<<endl;
            break;
        }
        case 5:{
            int number=0;
            cout<<"Ingrese el numero entero: "<<endl; cin>>number;
            int numberDigits=counterDigits(number);
            int array[numberDigits];
            int *pArray=array;
            makeArrayInt(pArray, number, numberDigits);
            cout<<" ' ";
            for(int k=0;k<numberDigits;k++){
                char lyrics=*(pArray+k)+48;
                cout<<lyrics;
            }
            cout<<" ' ";
            cout<<endl;
            break;
        }
        case 7:{
            problem7();
            break;
        }
        case 8:{
            problema8();
            break;
        }
        case 9:{
            problema9();
            break;
        }
        case 11:{
            problem11();
            break;
        }
        case 13:{
            int filas=0,columnas=0;
            cout<<"Introduzca el numero de filas de la matriz: "; cin>>filas;
            cout<<"Introduzca el numbero de columnas de la matriz: "; cin>>columnas;
            int **matrix;
            matrix= new int *[filas];
            for(int i=0;i<filas;i++){
                matrix[i]=new int[columnas];
            }
            for(int j=0; j<filas;j++){
                for(int k=0;k<columnas;k++){
                    cout<<"Ingrese el valor para la posicion ["<<j<<"]["<<k<<"] "<<endl; cin>>*(*(matrix+j)+k);
                }
            }
            numberStars(matrix,filas,columnas);
            delete [] matrix;
            break;
        }
        case 16:{
            problem16();
            break;
        }
        case 17:{
            unsigned long int n=0;
            cout<<"Ingrese el numero n para hallar la suma de los numeros amigables menores que n: "; cin>>n; cout<<endl;
            if(n<285) cout<<"El resultado es 0 ";
            else{
                unsigned long int result=0;
                for(unsigned long int i=220;i<n;i++){
                    unsigned long int result1=sumDivisor(i);
                    unsigned long int result2=sumDivisor(result1);
                    if(result2==i && i<n && result2<n && result1!=result2){
                        result=result+i+result1;
                    }
                }
                cout<<"El resultado es: "<<result/2<<endl;
            }
            break;
        }
        }
    }
    return 0;
}

void problema8(){

    char string[25]; char numbers[25]; char lyrics[25];
    cout<<"Ingrese la cadena de caracteres: "<<endl;
    cin>>string;
    for(int i=0,j=0,k=0;string[i]!='\0';i++){
        if(string[i]>47 and string[i]<58){
            numbers[j]=string[i];
            j+=1;
        }
        else{
            lyrics[k]=string[i];
            k+=1;
        }
    }
    cout<<"Original: "<<string<<endl;
    cout<<"Texto: "<<lyrics<<". Numero: "<<numbers<<". "<<endl;
}

void problema9(){
    unsigned long long int number=0;
    int n=0;
    cout<<"Ingrese el numero n: "<<endl;
    cin>>n;
    cout<<"Ingrese la cadena de caracteres numericos: "<<endl;
    cin>>number;
    int result[25];
    int length=counterDigits(number)-1;
    int position=length;
    int numbers[25];
    int *pointer=numbers;
    int sum=0;
    makeArrayInt(pointer, number, length+1);
    for(int i=0;i<length/n;i++){
        for(int j=0;j<n;j++){
            sum=sum+(numbers[position]*potencia(10,j));
            position-=1;
        }
        result[(length/n)-i]=sum;
        sum=0;
    }
    int k=position;
    int i=1;
    while(i!=0){
        if(position<0) i=0;
        else{
            for(int j=0;j<=k;j++){
                sum=sum+(numbers[position]*potencia(10,j));
                position-=1;
            }
            result[0]=sum;
            i=0;
        }
    }
    sum=0;
    if((length+1)%n==0){
        for(int j=0;j<(length/n)+k-1;j++){
            sum=sum+result[j];
        }
    }
    else{
        for(int j=0;j<(length/n)+k+1;j++){
            sum=sum+result[j];
        }
    }
    cout<<"Original: "<<number<<" ";
    cout<<"Suma: "<<sum<<endl;
}

int lengthArrayInt(int array[]){
    int count=0;
    for(int i=0; array[i]!='\0';i++){
        count+=1;
    }
    return count;
}

int counterDigits(int a){
    int count=1;
    while(a>9){
        a=a/10;
        count+=1;
    }
    return count;
}

void makeArrayInt(int *p,int num,int length){
    int divider=1;
    for(int i=1;i<length;i++){
        divider=divider*10;
    }
    //234
    //2
    int n=0;
    for(int j=0;j<length;j++){
        n=num/divider;
        num=num%divider;
        *(p+j)=n;
        divider=divider/10;
    }
}

int potencia(int a, int b){
    int resultado=1;
    for(int i=0; i<b; i++)
    {
        resultado*=a;
    }
    return resultado;
}

int lengthArrayChar(char array[]){
    int count=1;
    int i=1;
    while(i!=0){
        if(array[i]=='\0')
            i=0;
        else{
            count+=1;
            i+=1;
        }
    }
    return count;
}

bool comparison(char array1[],char array2[],int length){
    bool equal=true;
    for(int i=0;i<length && equal==true;i++){
        if(array1[i]!=array2[i]) equal=false;
    }
    return equal;
}

void problem7(){
    char word[25];
    cout<<"Ingrese la palabra a la cual se le retiraran las letras repetidas: "<<endl; cin>>word;
    int n=lengthArrayChar(word);
    char newWord[n];
    for(int i=0;i<n;i++){
        newWord[i]='-';
    }
    newWord[0]=word[0];
    int k=1;
    for(int i=1;i<n;i++){
        char lyrics=word[i];
        bool include=true;
        for(int j=0;j<n;j++){
            if(newWord[j]==lyrics){
                include=false;
                break;
            }
        }
        if(include==true){
            newWord[k]=lyrics;
            k+=1;
        }
    }
    newWord[k]='\0';
    for(int l=0;l<n;l++){
        cout<<newWord[l];
        if(newWord[l+1]=='\0') l=n;
    }
    cout<<endl;
}

void problem11(){
    int **matrix;
    matrix=new int *[15];
    for(int i=0;i<15;i++){
        matrix[i]=new int[20];
    }
    for(int j=0;j<15;j++){
        for(int k=0;k<20;k++){
            *(*(matrix+j)+k)=0;
        }

    }
    bool finished=false;
    while(finished==false){
        for(int j=0;j<15;j++){
            for(int k=0;k<20;k++){
                if((*(*(matrix+j)+k))==0) cout<<"- ";
                else cout<<"+ ";
            }
            cout<<endl;
        }
        char fila, option; int columna;
        cout<<"Ingrese a para reservar un asiento "<<endl<<"Ingrese b para cancelar una reserva "<<endl;
        cin>>option;
        if(option!='a' && option!='b') break;
        cout<<"Ingrese la fila A-O "<<endl; cin>>fila;
        cout<<"Ingrese la columna 1-20 "<<endl; cin>>columna;
        switch (fila) {
        case 'A':{
            if(option=='a') *(*(matrix)+(columna-1))=1;
            else *(*(matrix)+(columna-1))=0;
            break;
        }
        case 'B':{
            if(option=='a') *(*(matrix+1)+(columna-1))=1;
            else *(*(matrix+1)+(columna-1))=0;
            break;
        }
        case 'C':{
            if(option=='a') *(*(matrix+2)+(columna-1))=1;
            else *(*(matrix+2)+(columna-1))=0;
            break;
        }
        case 'D':{
            if(option=='a') *(*(matrix+3)+(columna-1))=1;
            else *(*(matrix+3)+(columna-1))=0;
            break;
        }
        case 'E':{
            if(option=='a') *(*(matrix+4)+(columna-1))=1;
            else *(*(matrix+4)+(columna-1))=0;
            break;
        }
        case 'F':{
            if(option=='a') *(*(matrix+5)+(columna-1))=1;
            else *(*(matrix+5)+(columna-1))=0;
            break;
        }
        case 'G':{
            if(option=='a') *(*(matrix+6)+(columna-1))=1;
            else *(*(matrix+6)+(columna-1))=0;
            break;
        }
        case 'H':{
            if(option=='a') *(*(matrix+7)+(columna-1))=1;
            else *(*(matrix+7)+(columna-1))=0;
            break;
        }
        case 'I':{
            if(option=='a') *(*(matrix+8)+(columna-1))=1;
            else *(*(matrix+8)+(columna-1))=0;
            break;
        }
        case 'J':{
            if(option=='a') *(*(matrix+9)+(columna-1))=1;
            else *(*(matrix+9)+(columna-1))=0;
            break;
        }
        case 'K':{
            if(option=='a') *(*(matrix+10)+(columna-1))=1;
            else *(*(matrix+10)+(columna-1))=0;
            break;
        }
        case 'L':{
            if(option=='a') *(*(matrix+11)+(columna-1))=1;
            else *(*(matrix+11)+(columna-1))=0;
            break;
        }
        case 'M':{
            if(option=='a') *(*(matrix+12)+(columna-1))=1;
            else *(*(matrix+12)+(columna-1))=0;
            break;
        }
        case 'N':{
            if(option=='a') *(*(matrix+13)+(columna-1))=1;
            else *(*(matrix+13)+(columna-1))=0;
            break;
        }
        case 'O':{
            if(option=='a') *(*(matrix+14)+(columna-1))=1;
            else *(*(matrix+14)+(columna-1))=0;
            break;
        }
        default:{
            cout<<"Los valores ingresados son invalidos "<<endl;
        }
        }
    }
    delete [] matrix;
}

void numberStars(int **p,int filas ,int columnas){
    int result=0;
    int count=0;
    for(int i=1;i<(filas-1);i++){
        for(int j=1;j<(columnas-1);j++){
            result=(*(*(p+i)+j)+*(*(p+(i-1))+(j-1))+*(*(p+(i-1))+(j+1))+*(*(p+(i+1))+(j-1))+*(*(p+(i+1))+(j+1)))/5;
            if(result>6) count+=1;
        }
    }
    cout<<"El numero de estrellas encontradas es: "<<count<<endl;
}

void problem16(){
    unsigned int n;
    cout<<"Ingrese el numero n para crear la matriz nxn "<<endl; cin>>n;
    long int matrix[n+1][n+1];
    for(unsigned int i=0;i<=n;i++){
        for(unsigned int j=0;j<=n;j++){
            if(i==0 || j==0) matrix[i][j]=1;
            else matrix[i][j]=(matrix[i-1][j])+(matrix[i][j-1]);
        }
    }
    cout<<"La matriz tiene "<<matrix[n][n]<<" caminos. "<<endl;
}

unsigned long int sumDivisor(unsigned long int number){
    unsigned long int sum=1;
    for(unsigned long int i=2; i<number; i++){
        if(number%i==0) sum=sum+i;
    }
    return sum;
}
