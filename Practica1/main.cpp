//Práctica número 1 Juan Camilo Mazo Castro G6.

#include <iostream>

using namespace std;

void problema2();
void problema4();
void problema5();
void problema7();
void problema9();
void problema11();
void problema13();
void problema14();
void problema15();
void problema17();
int potencia(int ,int );
int counterDigits(int );
bool palindromo(int );

int main()
{
    int i=-1;
    while (i!=0) {
        cout<<"Introduzca el numero del problema que desea observar: "<<endl;
        cin>>i;
        switch (i) {
        case 0:{
            i=0;
            break;
        }
        case 2:{
            problema2();
            break;
        }
        case 4:{
            problema4();
            break;
        }
        case 5:{
            problema5();
            break;
        }
        case 7:{
            problema7();
            break;
        }
        case 9:{
            problema9();
            break;
        }
        case 11:{
            problema11();
            break;
        }
        case 13:{
            problema13();
            break;
        }
        case 14:{
            problema14();
            break;
        }
        case 15:{
            problema15();
            break;
        }
        case 17:{
            problema17();
            break;
        }
        }
    }
    return 0;
}

void problema2(){
    int quantity=0;
    cout<<"Ingrese la cantidad deseada: "<<endl;
    cin>>quantity;
    int multiplier=10000;
    for(int i=0; i<=3; i++){
        int firstNumber=5, counter=0, j=1;
        while(j!=0){
            if (quantity<(firstNumber*multiplier)){
                cout<<firstNumber*multiplier<<": "<<counter<<endl;
                counter=0;
                if (firstNumber==1 or (firstNumber*multiplier)==50){
                    multiplier=multiplier/10;
                    j=0;
                }
                else {
                    firstNumber=firstNumber/2;
                }
            }
            else{
                quantity=quantity-(firstNumber*multiplier);
                counter+=1;
            }
        }
    }
    cout<<"restante: "<<quantity<<endl;
}

void problema4(){
    int number1=0,number2=0;
    bool finished=false;
    while(finished==false){
    cout<<"Ingrese el primer numero: "<<endl; cin>>number1;
    cout<<"Ingrese el segundo numero: "<<endl; cin>>number2;
    if((number1/100)>23 or (number1/100)<0 or (number1%100)>59 or (number1%100)<0)
        cout<<"El primer numero ingresado es incorrecto, ingreselo nuevamente"<<endl;
    else if((number1/100)>23 or (number1/100)<0 or (number1%100)>59 or (number1%100)<0)
        cout<<"El primer numero ingresado es incorrecto, ingreselo nuevamente"<<endl;
    else{
        int a1=number1/100, b1=number1%100, a2=number2/100, b2=number2%100;
        b1=b1+b2;
        a1=a1+a2;
        while(b1>59){
            b1=b1-60;
            a1+=1;
        }
        while(a1>23){
            a1=a1-24;
        }
        if(a1==0 and b1>9)
            cout<<"La hora es "<<"0"<<a1<<b1<<endl;
        else if(a1!=0 and b1<10)
            cout<<"La hora es "<<a1<<"0"<<b1<<endl;
        else if(a1==0 and b1<10)
            cout<<"La hora es "<<"00"<<"0"<<b1<<endl;
        else
            cout<<"La hora es "<<a1<<b1<<endl;
        finished=true;
    }
    }
}

void problema5(){
    int number;
    cout<<"Ingrese un numero impar "<<endl; cin>>number;
    if((number % 2)!=0){
        int temporal; temporal=number/2;
        int asterisk; asterisk=-1;
        for(int j=0;j<((number/2)+1);j++){

            asterisk+=2;
            for(int k=(temporal); k>0;k--){
                cout<<" ";
            }
            for(int k=0; k<asterisk;k++){
                cout<<"*";
            }
            for(int k=(temporal); k>0;k--){
                cout<<" ";
            }
            cout<<endl;
            temporal-=1;
        }
        asterisk=number; temporal=1;
        for(int j=0;j<(number/2);j++){
            asterisk-=2;
            for(int k=temporal;k>0;k--){
                cout<<" ";
            }
            for(int k=asterisk;k>0;k--){
                cout<<"*";
            }
            for(int k=temporal;k>0;k--){
                cout<<" ";
            }
            cout<<endl;
            temporal+=1;
        }
    }
    else
        cout<<"El numero ingresado no es un numero impar "<<endl;
}

void problema7(){
    int count=0,value=0;
    cout<<"Ingrese un numero"<<endl; cin>>value;
    for(int i=2,j=1,k=1;i<value;){
        if(i%2==0){
             count=count+i;
        }
        k=i;
        i=i+j;
        j=k;
    }
    cout<<"El resultado de la suma es "<<count<<endl;
}

void problema9(){
    cout<<"Ingrese el numero: "<<endl;
    int number=0;
    cin>>number;
    if(number<0)
        number=number*-1;
    int a=0,b=number,result=0;
    for(int i=0;i<counterDigits(number);i++){
        a=b%10;
        b=b/10;
        result=result+ potencia(a,a);
    }
    cout<<"El resultado de la suma es: "<<result<<endl;

}

void problema11(){
    int number=0;
    cout<<"Introduzca el numero para calcular el mcm: "<<endl;
    cin>>number;
    if(number<1)
        cout<<"El numero ingresado es invalido, intentelo nuevamente."<<endl;
    else{
        bool finished=false; int j=1, mcmNumber=0;
        while(finished==false){
            mcmNumber=number*j;
            int k=0, l=0; bool valid=true;
            while(valid==true){
                if((number-k)*l==mcmNumber){
                    if(k<number-1){
                        k+=1;
                        l+=1;
                    }
                    else{
                        finished=true;
                        valid=false;
                    }
                }
                else if((number-k)*l>mcmNumber){
                    j+=1;
                    valid=false;
                }
                else l+=1;
            }
        }
        cout<<"El minimo comun multiplo de "<<number<<" y los numeros enteros inferiores a este es: "<<mcmNumber<<endl;
    }
}

void problema13(){
    int number=0;
    cout<<"Introduzca el numero con el cual se calculara la suma de los primos menores a el. "<<endl; cin>>number;
    if(number==1) cout<<"El resultado de la suma es 1"<<endl;
    else if(number==2) cout<<"El resultado de la suma es 3"<<endl;
    else{
        int result=2;
        for(int count=1;count<number;count+=2){
            bool prime=true;
            for(int j=2;j<count && prime==true; j++){
                if(count%j==0 && count<number) prime=false;
            }
            if(prime==true) result=result+count;
        }
        cout<<"El resultado de la suma es "<<result-1<<endl;
    }
}

void problema14(){
    int result=0, maxpalindromo=0, a=0,b=0;
    for(int i=100;i<1000;i++){
        for(int j=100;j<1000;j++){
            result=i*j;
            if(palindromo(result)==true and result>maxpalindromo){
                maxpalindromo=result;
                a=i;
                b=j;
            }
        }
    }
    cout<<a<<"*"<<b<<"="<<maxpalindromo<<endl;
}

void problema15(){
    int n=0,sum=1,increasing=2,aux=1,substraction=2;
    cout<<"Ingrese el numero n del espiral nxn: "<<endl; cin>>n;
    for(int w=3;w<n;w+=2){
        substraction+=1;
    }
    if(n==3) cout<<"En un espiral de 3x3, la suma es: 25"<<endl;
    else{
        int iteration=n-substraction;
        for(int j=0;j<iteration;j++){
            for(int k=0;k<4;k++){
               aux=aux+increasing;
               sum=sum+aux;
               if(k==3) increasing+=2;
            }
        }
        cout<<"En un espiral de "<<n<<"x"<<n<<", la suma es: "<<sum<<endl;
    }
}

void problema17(){
    int k=0, n=0, triangular=0,divider=0;
    cout<<"Ingrese el numero k para calcular el primer numero triangular que tiene mas de k divisores "<<endl; cin>>k;
    bool found=false;
    while(found==false){
        n+=1;
        triangular=(n*(n+1))/2;
        divider=0;
        for(int j=1;j<=triangular;j++){
            if(triangular%j==0)
                divider+=1;
        }
        if(divider>k) found=true;
    }
    cout<<"El numero es: "<<triangular<<" que tiene "<<divider<<" divisores "<<endl;
}

int potencia(int a, int b){
    int resultado=1;
    for(int i=0; i<b; i++)
    {
        resultado*=a;
    }
    return resultado;
}

int counterDigits(int a){
    int count=1;
    while(a>9){
        a=a/10;
        count+=1;
    }
    return count;
}

bool palindromo(int a){
    int i=counterDigits(a);
    bool answer=true;
    int array[i];
    int k=i-1;
    for(int j=0; j<=i; j++){
        array[j]=a/potencia(10,k);
        a=a%potencia(10,k);
        k-=1;
    }
    k=i-1;
    for(int l=0;l<=(i/2);l++){
        if(array[l]!= array[k]){
            answer=false;
        }
        k-=1;
    }
    return answer;
}
