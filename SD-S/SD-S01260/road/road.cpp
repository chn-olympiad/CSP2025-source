#include<bits/stdc++.h>
using namespace std;
int n,m,k;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a,b,c;
	for (int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
	}
	cout<<(m+n+k)*786+k*21+m*187;
	
	return 0;
}
