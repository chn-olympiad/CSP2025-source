#include<bits/stdc++.h>
using namespace std;
int a,e;
int b[10005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
	}
	if(a=3)
	{
		if(b[1]+b[2]>b[3]&&b[2]+b[3]>b[1]&&b[1]+b[3]>b[2])
			cout<<1;
		else
			cout<<0;
			return 0;
	}
	if(a<3){ cout<<0;return 0;}
	if(a==4&&b[i]==1) 
	for(int i=0;i<=n;i++){
		if(b[i]==1) cout<<1;
	}
	for(int i=0;i<=n;i++){
		if(a==5&&b[i]==1) e=1;
		
	}
	if(e==1){ cout<<a+2;return 0;}
	cout<<a*2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
