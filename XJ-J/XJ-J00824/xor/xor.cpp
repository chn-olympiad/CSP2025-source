#include<bits/stdc++.h>//xor
using namespace std;
long long int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int i,j,s,maxn=0,mun=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	  cin>>a[i];
	  
	for(i=1;i<=n;i++)
	{
		s=0;
		for(j=i;j<=n;j++)
		s^=a[j];
		if(s==k)
		{
		  if(j-i+1>maxn)
		  {
			maxn=j-i+1;
			mun++;
			//cout<<i<<' '<<j<<endl;
		  }
				
		}
		
	}
	cout<<mun<<endl;
	return 0;
	/*
	°´Î»Òì»ò  ^ 
	*/
}
