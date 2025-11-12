#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    bool b;
    cin>>a;
    for(int i=0;i!=a.size();i++){
        if(a[i]=='9'){
            cout<<9;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='8'){
            cout<<8;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='7'){
            cout<<7;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='6'){
            cout<<6;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='5'){
            cout<<5;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='4'){
            cout<<4;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='3'){
            cout<<3;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='2'){
            cout<<2;
            b=true;
        }
    }
    for(int i=0;i!=a.size();i++){
        if(a[i]=='1'){
            cout<<1;
            b=true;
        }
    }
    if(b==false){
    	cout<<0;
    	return 0;
	}
    for(int i=0;i!=a.size();i++){
        if(a[i]=='0'){
            cout<<0;
        }
    }
    return 0;
}
