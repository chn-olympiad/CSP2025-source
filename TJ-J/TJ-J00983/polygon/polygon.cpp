#include <bits/stdc++.h>
using namespace std;
int n;
long long a[5010]={0};
long long s[5010]={0};
int ct=0;
int cmp(int x,int y)
{
	return x>y;
}
void q(int ll,int xx)
{
	
	for(int j=ll;j<n;j++)
	{
		ct++;
		if(a[j]+a[n-1]>=xx)
		{
			continue;
		}
		for(int k=j+1;k<n;k++)
		{
			if(a[j]+a[k]<xx)
			{
				q(k,xx-a[j]);
			}
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		s[i]=(a[i]+s[i-1]);
	}
	for(int i=0;i<n-2;i++)
	{
		if(s[n-1]-s[i]>a[i])
		{
			ct++;
			int l=i;
			int x=s[n-1]-s[i]-a[i];
			for(int j=l+1;j<n;j++)
			{
				if(a[j]<x)
				{
					l=j;
					break;
				}
			}
			while(a[l+1]==a[l])
			{
				l++;
			}
			if(l==i)
			{
				continue;
			}
			else if(l==n-1)
			{
				ct++;
				continue;
			}
			q(l,x);
		}
	}
	cout << ct;
	return 0;
}


