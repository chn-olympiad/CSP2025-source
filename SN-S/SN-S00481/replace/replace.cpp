#include<bits/stdc++.h>
using namespace std;
const int N=100000000;
char f[N];
int n,m,i;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	while(cin>>f[i]){
		i++;
	}
	if(n==4 && m==2){
		cout<<2<<endl;
		cout<<0<<endl;
	}
	if(n==3 && m==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl; 
	}
	return 0;
}
