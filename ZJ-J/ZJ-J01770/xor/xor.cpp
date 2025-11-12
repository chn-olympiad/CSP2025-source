#include<bits/stdc++.h>
using namespace std;
int n,k,qq,t,kk,x[25],a[500005][30],xx,ans,s[105],l[500005],f,u[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	t=1;
	kk=1;
	while(t<k)
	{
		t*=2;
		kk++;
	}
	if(t>k&&k!=0)
	{
		t/=2;
		kk--;
	}
	qq=kk;
	while(k!=0)
	{
		if(k>=t)
		{
			k-=t;
			s[kk]=1;
		}
		t/=2;
		kk--;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		t=1;
		kk=1;
		while(t<k)
		{
			t*=2;
			kk++;
		}
		if(t>k&&k!=0)
		{
			t/=2;
			kk--;
		}
		l[i]=kk;
		while(k!=0)
		{
			if(k>=t)
			{
				k-=t;
				a[i][kk]=1;
			}
			t/=2;
			kk--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(x,0,sizeof(x));
		f=0;
		xx=max(l[i],qq);
		if(!u[i])
		{
			for(int j=1;j<=xx;j++)
			{
				if(a[i][j])
					x[j]=1;
				if(x[j]!=s[j])
					f=1;
			}
			if(!f)
			{
				ans++;
				u[i]=1;
				continue;
			}
			for(int j=i+1;j<=n;j++)
			{
				f=0;
				xx=max(xx,l[j]);
				for(int q=1;q<=l[j];q++)
				if(a[j][q])
					x[q]=(x[q]+1)%2;
				for(int q=1;q<=xx;q++)
					if(x[q]!=s[q])
					{
						f=1;
						break;
					}
				if(!f)
				{
					ans++;
					for(int q=i;q<=j;q++)
						u[q]=1;
					break;
				}		
			}
		}
		else
		{
			for(int j=1;j<=xx;j++)
			{
				if(a[i][j])
					x[j]=1;
				if(x[j]!=s[j])
					f=1;
			}
			if(!f)
			{
				for(int q=i+1;q<=n;q++)
				{
					if(u[q])
					u[q]=0;
					else
					break;
				}
				continue;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(u[j])
				{
					f=0;
					xx=max(xx,l[j]);
					for(int q=1;q<=l[j];q++)
					if(a[j][q])
						x[q]=(x[q]+1)%2;
					for(int q=1;q<=xx;q++)
						if(x[q]!=s[q])
						{
							f=1;
							break;
						}
					if(!f)
					{
						for(int q=j+1;q<=n;q++)
						{
							if(u[q])
							u[q]=0;
							else
							break;
						}
						break;
					}
				}
				else
					break;		
			}
		}
	}
	cout<<ans;
	return 0;
}
