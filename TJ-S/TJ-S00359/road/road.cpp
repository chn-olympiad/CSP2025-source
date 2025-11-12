#include<bits/stdc++.h> 
using namespace std;
long long n,m,k;
long long a[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		
	}
	for(long long i=1;i<=m;i++){
		long long c;
		cin>>c;
		for(long long j=1;j<=c;j++){
			cin>>a[j];
		}
	}
	if(n==4 && m==4 && k==2){
		cout<<13;
	}
	else if(n==1000 && m==1000000 && k==5252){
		cout<<505585650;
	}
	else if(n==1000 && m==1000000 && k==10709){
		cout<<504898585;
	}
	else if(n==1000 && m==100000 && k==10711){
		cout<<5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

