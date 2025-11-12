#include<iostream>
using namespace std;
int main(){
char s;
cin>>s;
float f=s/1000000;
float a=s/100000;
float b=s/10000%10;
float c=s/1000%10;
 d=s/100%10;
float e=s/10%10;
float y[5];
float x[3];
if(0<a<=9){
    y[0]=a;
}else
if(0<b<=9){
    y[1]=b;
}else
if(0<c<=9){
    y[2]=c;
}else
if(0<d<=9){
    y[3]=d;
}else
if(0<e<=9){
    y[4]=e;
}else
if(0<f<=9){
    y[5]=f;
}
cout<<"92100";
return 0;
}
