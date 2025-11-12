#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,mx=-1;
int a[500005];
bool nw[25];
bool kw[25];int flag;
bool vis[500005];
void two(int k)
{
	flag=0;
	while(k)
	{
		kw[++flag]=k%2;
		k/=2;
	}
}
//将十进制数转为二进制数
void bing(int l)
{
	two(l);
	//将目前遍历的数字转为二进制数
	for(int i=1;i<=flag;++i)
	{
		if(nw[i]!=kw[i])
		{
			nw[i]=true;
		}
		else
		{
			nw[i]=false;
		}
	}
	//按位异或和 
}
//将目前的权值和目前遍历的数字进行按位异或和 
bool pan()
{
	int p=0;
	for(int i=1;i<=21;++i)
	{
		if(nw[i])
		{
			p+=pow(2,i-1);
		}
	}
	if(p==k)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//判断权值是否为k 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];		
	}
	for(int k=1;k<=n;++k)
	{
		ans=0;
		for(int i=k;i<=n;++i)
		{
			if(vis[i])
			{
				continue;
			}
			memset(nw+1,false,sizeof(nw));
			bool flag=false;
			for(int j=i;j<=n;++j)
			{
				bing(a[j]);
				vis[j]=true;
				if(pan())
				{
					++ans;
					flag=true;
					break;
				}
			}
			if(!flag)
			{
				for(int j=i;j<=n;++j)
				{
					vis[j]=false;
				}
			}			
		}	
		mx=max(mx,ans);
	}	
	cout<<mx;
	return 0;
}
