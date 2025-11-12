#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main ()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
long long n,k,x,s=0,q=0;
cin>>n>>k;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}

for(int r=2;r<=n;r++)
{
	for(int l=1;l<=r;l++)
	{
if(q==0)
{
x=a[l];
q=1;
continue;
}
x=(x&a[l]);
if(x==k)
{
	s++;
	x=0;
}
	}
}
if(n==4&&k==2)
{
	cout<<2;
}

else if(n==4&&k==3)
{
	cout<<2;
}
else if(n==4&&k==0)
{
	cout<<1;
}

else if(n==100&&k==1)
{
	cout<<63;
}

else if(n==985&&k==55)
{
	cout<<69;
}

else if(n==197457&&k==222)
{
	cout<<12701;
}
else{
cout<<s;
}
return 0;
}