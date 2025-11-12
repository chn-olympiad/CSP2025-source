#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int sum;
int ans;
int fq;
int cishu;
char s[100000000];
int s1[100000000];
int c[100000000];
int ii;
bool cmp(int a,int b)
{
	return a>b;
}
int interview(int b)
{
	for(int i=0;i<n;i++)
	{
		if(s1[i]=1&&fq>c[i])
		{
			b++;
		}
		else 
		{
			fq++;
		}
	}
	return b;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		s1[i]=s[i]-'0';
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(s1[i]==1)
		{
			sum++;
		}
	}
	if(sum<m)
	{
		ans=0%998244353;
		cout<<ans;
		return 0;
	}
	ans=1;
	sum=interview(0);
	sort(c,c+n,cmp);
	while(sum>m)
	{
		swap(c[sum-cishu-ii],c[sum-cishu-ii-1]);
		sum=interview(0);
		ii++;
		ans++;
	}
    ans++;
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
 } 
