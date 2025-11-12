#include<bits/stdc++.h>
using namespace std;

const int N=1e+6;

int n,m,k;

int sum;
int u[N+10],v[N+10],w[N+10]; 
int c[10+10];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	bool flag=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)	flag=0;
	}	
	
	sort(w+1,w+m+1);
	if(k==0||flag==0)	{
		cout<<w[m]+w[m-1];
	}
	
	
	return 0;
} 