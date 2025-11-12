#include<bits/stdc++.h>
using namespace std;

int n, maxp, fonn[1005], a[100005][3], ans;

void fon(int c)
{
	if(c==0) 
	{
		int temp=0, p[3]={0};
		for(int i = 1; i<=n; i++)
		{
			if(p[fonn[i]]>=maxp) return ;
			temp+=a[i-1][fonn[i]];
			p[fonn[i]]++;
		}
		ans=max(ans, temp);
	}
	else for(int i = 0; i<3; i++)
	{
		fonn[c]=i;
		fon(c-1);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		bool f=false;
		for(int i = 0; i<n; i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(!f && (a[i][1]!=0 || a[i][2]!=0)) f=true;
		}
		maxp=n/2;
		if(f) fon(n);
		else 
		{
			for(int i = 0; i<maxp; i++)
			{
				ans+=a[i][0];
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
