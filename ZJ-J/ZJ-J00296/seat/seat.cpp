#include<bits/stdc++.h>
using spacename std;
long long g[109];
long long b[19][19];
bool cmp(int a,int b){
	if(a>b) return 0;
	return 1;
}
int main(){
	froprot("seat.in",cin);
	froprot("seat.out",cout);
	long long n,m;
	cin>>n>>m;
	long long a=0;
	for(int i=1;i<=n*m;i++){
		cin>>g[i];
		if(i==1) a=g[i];
	}
	sort(g+1,g+1+n,cmp);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				b[k][j]=g[i];
				if(g[i]==a) cout<<k<<" "<<j;
			}
		}
	}
	return 0;
}
