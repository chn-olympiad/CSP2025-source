//#include<bits/stdc++.h>
//using namespace std;
//int n,k,a[500001],ANS;
//int xorr(int x,int y)
//{
//	return x^y;
//}
//int main()
//{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
//	cin>>n>>k;
//	int flag=1;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//		if(a[i]!=1)flag=0;
//	}
//	if(flag==1&&k==0)
//	{
//		cout<<floor(n/2);
//		return 0;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		int left=i;//[l,r]ÖÐµÄl 
//		int ans=a[i],length=1;//ans=[left,left+length] 
//		int flge=1;
//		while(left+length<=n)
//		{
//			ans=xorr(ans,a[left+length]);
//			if(xorr(ans,a[left+length])==k)
//			{
//				flge=0;
//				break;
//			}
//			length++;
//		}
//		if(flge==0)i=left+length+1,ANS++;
//	}
//	cout<<ANS;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ANS,f[10001][10001],sum[10001][10001];
int xorr(int x,int y)
{
	return x^y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(a,-1,sizeof(a));
	cin>>n>>k;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];		
		if(a[i]!=a[i+1]&&i<n)flag=0;
	}
	if(flag==1&&k==0)
	{
		cout<<floor(n/2);
		return 0;
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+1])
			{
				ANS++,i++;
			}
		}
		cout<<ANS;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sum[i][i]=k;
		if(f[i][i]==k)f[i][i]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int mid=i;mid<j;mid++)
			{
				if(xorr(sum[i][mid],sum[mid+1][j])==k)
				{
					f[i][j]=max(f[i][j],f[i][mid]+f[mid+1][j]);
					sum[i][j]=xorr(sum[i][mid],sum[mid+1][j]);
				}
			}
//				f[i][j]=max(xorr(f[i][mid],f[mid+1][j]),max(f[i][j],max(f[i][j-1],f[i-1][j])));
	cout<<f[1][n];
	return 0;
}
