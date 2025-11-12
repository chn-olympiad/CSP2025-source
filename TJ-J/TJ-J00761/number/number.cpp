#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
char a[1000],s[10000];
int b=0;
char c,d;
for(int i=0;i<1000;i++){
    cin>>c;
    if(c>='0'&&c<='9'){a[i]=c;b++;}
}for(int j=0;j<b;j++){
for(int i=0;i<b;i++){
    int q=b,n=0;

    if(a[q]>a[j]){
        d=a[j];
        a[q]=a[j];
        a[j]=d;
    }
}}
for(int i=0;i<b;i++){
    cout<<a[i];
}
return 0;
}
