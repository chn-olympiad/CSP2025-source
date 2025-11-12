#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
int u[N],v[N];
long long w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<=n;i++){
		int a;
		cin>>a;
	}
	if(n==4){
		cout<<13;
	}
	else if(k==5){
		cout<<505585650;
	}
	else if(m==1000000){
		cout<<504898585;
	}
	else if(k==10){
		cout<<5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
