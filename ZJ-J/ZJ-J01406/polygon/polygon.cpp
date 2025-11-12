#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],he=1,mas[5001],s;
#define inf 998244353 
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int sk,int sl,int sp,int rf)
{
	
	if(sk>=sl && sp>=3 && rf==1)
	{
//		cout<<x<<" "<<sk<<" "<<sl<<" "<<sp<<"\n";
		s++;
		rf=1;
	}
	if(x<n)
	{
		dfs(x+1,sk+a[x+1],sl,sp+1,1);
		dfs(x+1,sk,sl,sp,0);
	}
}
void init()
{
	mas[0]=1;
	for(int i=1;i<=500;i++)
	{
		mas[i]=mas[i-1]*2;
//		if(mas[i]>=inf)mas[i]=mas[i]%inf;
//		for(int j=1;j<=i;j++)
//		{
//			mas[i]+=sk;
//			if(mas[i]>=inf)mas[i]=mas[i]%inf;
//		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)dfs(i,a[i],a[i]*2+1,1,1);
	cout<<s;
	return 0;
}//#Shang4Shan3Ruo6Shui4
