#include<bits/stdc++.h>
using namespace std;
int a[500001],n,p[500001],k,b[20000],c;
int f(int l,int r)
{
	return p[l-1]^p[r];
}
int main()
{
	freopen("xor4.in","r",stdin);
	freopen("xor4.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%d",a+1);p[1]=a[1];b[a[1]]++;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",a+i);
		p[i]=p[i-1]^a[i];
		if(a[i]<20000)b[a[i]]++;
	}
	if(k==0&&b[1]==n) {printf("%d",n/2);return 0;}
	if(k<=1&&b[1]+b[0]==n)
	{
		int l=0;
		for(int i=1;i<n;i++)
			if(k!=a[i]&&a[i]==a[i+1])
				l++,i++;
		printf("%d",b[k]+l);
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(f(i,j)==k) 
				c++,i=j;
	printf("%d",c);
	return 0;
}