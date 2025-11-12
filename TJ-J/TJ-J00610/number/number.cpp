#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	cout<<a;
	char b[1000000]['-1'],c[1000000]['-1'];
	b[1000000]==a;
    for(int i=0;i<1000000;i++){
        if(b[i]%'0'==1 || b[i]%'0'==2 || b[i]%'0'==3 || b[i]%'0'==4 || b[i]%'0'==5 || b[i]%'0'==6 || b[i]%'0'==7 || b[i]%'0'==8 || b[i]%'0'==9){
            c[i]==b[i];
        }
    }
    for(int i=0;i<=1000000;i++){
        if(c[i]%'0'!=-1){
            cout<<c[i];
        }
    }
	return 0;
}
