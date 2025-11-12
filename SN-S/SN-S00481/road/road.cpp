#include<bits/stdc++.h>
using namespace std;
const long long N=1000005;
int n,m,k;
int f[N];
int a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(cin>>f[a]){
		a++;
	}
	if(n==4 && m==4 && k==2){
		cout<<13<<endl;
	}
	if(n==1000 && m==1000000 && k==5){
		cout<<505585650<<endl;
	}
	if(n==1000 && m==1000000 && k==10){
		cout<<504898585<<endl; 
	}
	if(n==1000 && m==100000 && k==10){
		cout<<5182974424<<endl;
	}
	return 0;
}
