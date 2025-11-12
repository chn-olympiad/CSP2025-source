//西安高新第二初级中学  姜璟烁  SN-J00237 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int n,k;
int xorr[maxn],cnt,sum;
void pd(int a,int b)
{
	if((a ^ b)==k)
	{
		cnt++;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
 	cin>>n>>k;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>xorr[i];
 		if(xorr[i]==k)
 		{
 			cnt++;
		}
	}
 	for(int i=1;i<=n;i++)
	{
		int sum=xorr[i];
	 	for(int j=i+1;j<=n;j++)
	 	{
	 		pd(sum,xorr[j]);
	 		sum=sum^xorr[j];
		}
	}
	cout<<cnt/2;	
	return 0;
}
