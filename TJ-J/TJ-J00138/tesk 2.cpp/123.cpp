#include<bits/stdc++.h>
using namespace std;

int main()
{
int a,s,d[100001],f[1000001],g=0;
cin>>a>>s;
cin>>g;
int f[i]=g;
for(int i=0;i<a*s-1;i++)
{
	cin>>f[i+1];
}
for(int i=0;i<a*s;i++)
{
	int q=0,w=0;
	for(int j=0;j<a*s;j++)
	{
		if(f[i]>=q&&f[i]=-1)
		{
			q=f[i];
			w=i;
		}
	}
	if(q==g){
		z=w;
		break;
	}
	d[i]=q;
	f[w]=-1;
}
cout<<d[i]<<" "<<f[w];
	return 0;
}
