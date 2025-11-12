#include<bits/stdc++.h>
using namespace std;
int n,k,a1[500010],ans;
bool a2[500010];
bool check(int z1,int z2)
{
	for(int i=z1;i<=z2;i++)
	{
		if(a2[i]==1) return 0;
	}
	return 1;
}
bool cover(int z3,int z4)
{
	for(int i=z3;i<=z4;i++)
	{
		a2[i]=1;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
		if(a1[i]==k) ans++,a2[i]=1;//cout<<i<<" "<<i<<" "<<ans<<endl;//льеп 
	}
	int num1=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if(check(l,r)==1)
			{
				for(int i=l;i<=r;i++)
				{
					num1^=a1[i];	
				}
				//cout<<l<<" "<<r<<" "<<num1;	
				if(num1==k)
				{
					ans++;
					cover(l,r);
					//cout<<" "<<ans; 
				}
				//cout<<endl;
			}
			num1=0;	
		}	
	} 
	cout<<ans;
	return 0;
}
