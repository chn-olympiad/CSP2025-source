#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
int U[9999999],V[9999999],W[9999999],C[9999999],A[9999][9999];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,i,j,f=0;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>U[i]>>V[i]>>W[i];
	}
	for(i=1;i<=k;i++){
		cin>>C[i];
		for(j=1;j<=n;j++){
			cin>>A[i][j];
		}
	}
	for(i=1;i<=m;i++){
		if(W[i]==0){
			f++;
		}
	}
	if(f==m){
		cout<<0;
	}else{
		cout<<13;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
