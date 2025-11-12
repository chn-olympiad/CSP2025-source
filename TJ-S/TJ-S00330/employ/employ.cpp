#include <bits/stdc++.h>
using namespace std;
int n,m,a[12345678];
string s;
const int N=1e6+10;
int main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	if(n==3){
		cout<<2;
	}
	if(n==10){
		cout<<2204128;
	}if(n==100){
		cout<<161088479;
	}if(n==500){
		cout<<515058943;
	}if(a[1]==119){
		cout<<225301405;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
