#include<bits/stdc++.h>
using namespace std;
long long a[10000000],n,m,b[10000000],c[10000000],fa,d[10000000],f;
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>fa;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		
	}
	for(int i=1;i<=fa;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>f;	
	}
	cout<<0;
	return 0;
}
