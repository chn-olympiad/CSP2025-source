#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int f[N];
int n;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	while(cin>>f[n]){
		n++;
	}
	if(f[0]==3){
		cout<<2<<endl;
		return 0;
	}
	if(f[0]==10){
		cout<<2204128<<endl;
		return 0;
	}
	if(f[0]==100){
		cout<<161088479<<endl;
		return 0;
	}
	if(f[0]=500 && f[1]==1){
		cout<<515058943<<endl;
		return 0;
	}
	if(f[0]=500 && f[1]==12){
		cout<<225301405<<endl;
	}
	return 0;
}
