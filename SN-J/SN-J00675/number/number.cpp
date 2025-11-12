#include<bits/stdc++.h>
using namespace std;
int main(){


freopen("number.in","r",stdin);
freopen("number.out","w",stdout);


string a;
int b[1000009];
string c = "@";
cin>>a;
a = a+c;
int d = 0;
int e[11]={0,0,0,0,0,0,0,0,0,0,0};

e[0]=-1;
int ans=0;
for(int i = 0;i<=1000009;i++){
    if(a[i]=='1'){
        b[d]=1;
        d++;
    }
    if(a[i]=='2'){
        b[d]=2;
        d++;
    }
    if(a[i]=='3'){
        b[d]=3;
        d++;
    }
    if(a[i]=='4'){
        b[d]=4;
        d++;
    }
    if(a[i]=='5'){
        b[d]=5;
        d++;
    }
    if(a[i]=='6'){
        b[d]=6;
        d++;
    }
    if(a[i]=='7'){
        b[d]=7;
        d++;
    }
    if(a[i]=='8'){
        b[d]=8;
        d++;
    }
    if(a[i]=='9'){
        b[d]=9;
        d++;
    }
    if(a[i]=='0'){
        b[d]=0;
        d++;
    }
    if(a[i]=='@'){
        break;
    }
}
for(int i = 0;i<=d;i++){
    e[b[i]]++;
}
//for(int i = 0;i<=9;i++){
//    cout<<e[i];
//}
//cout<<endl;
for(int i=9;i>=0;i--){
    while(e[i]>0){
        cout<<i;
        e[i]--;
    }
}
	return 0;
}
