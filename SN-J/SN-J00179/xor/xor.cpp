#include<bits/stdc++.h>
using namespace std;
long long a[500010];
bool b[500010];
//bitset<21> b[500010];//我知道要用莫队或者分块（这俩是一个，可是我不会写异或前缀和 sad sad sad very sad
int A=1,B=1,C=1;
long long cnt_1,cnt_0,cnt_11; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
			A=0;//A不满足 
		if(a[i]>1)
			B=0;
		if(a[i]>255)
			C=0;
		if(a[i]==1)
		{
			cnt_1++;
		}
		if(a[i]==0)
		{
			cnt_0++;
		}
		if(a[i]==1&&a[i-1]==1&&b[i]==0&&b[i-1]==0)
		{
			cnt_11++;
			b[i]=1;
			b[i-1]=1;
		}
	}
	if(A)
	{
		cout<<n/2;
		return 0;
	}
	if(B)
	{
		if(k==1)
		{
			cout<<cnt_1;
			return 0;
		}
		if(k==0)
		{
			cout<<cnt_11+cnt_0;
			return 0;
		}
	}
	return 0;
}
