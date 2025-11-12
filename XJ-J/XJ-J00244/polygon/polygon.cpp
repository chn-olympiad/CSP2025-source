#include<bits/stdc++.h>
using namespace std;
long long int a[6666],v[101][101][101],i,j,ans,k,n,s;
int main()
{
		freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
cin>>n;
for(i=1;i<=n;i++)
cin>>a[i];

if(n<3)
{cout<<0;return 0;}

for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
for(k=1;k<=n;k++)
{
	if(i!=k&&j!=k)
	if(2*max(a[i],max(a[j],a[k]))<a[i]+a[j]+a[k]) 				 ///  ok
	s=1;														//v[i][j][k]=v[j][i][k]=v[k][j][i]=v[i][k][j]=v[j][i][k]=v[k][i][j]=1,cout<<i<<" "<<j<<" "<<k<<endl;
}
cout<<s;
return 0;
}


//¹ý²âÊÔµã1-3   12·Ö 
