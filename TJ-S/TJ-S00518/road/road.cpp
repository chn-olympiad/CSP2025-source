#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,s,d,f=0,y,u,i,o,p,c,b;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>s>>d;
		f+=d;
	}
	for(int j=0;j<k;j++){
    	cin>>y>>u>>i>>o>>p;
		c+=p;
	}
	cout<<f-c-1;
	return 0;
} 
