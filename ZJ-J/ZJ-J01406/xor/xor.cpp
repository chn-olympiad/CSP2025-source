#include<bits/stdc++.h>
using namespace std;
int a[1000055],n,k,t[1000055],s,p[1000055][21],r[21];
void tk(int x,int w)
{
	int re=0;
	while(w!=0)
	{
		p[x][++re]=w%2;
		w=w>>1;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;int w=k;
	int re=0;
	while(w!=0)
	{
		r[++re]=w%2;
		w=w>>1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			s++;
			t[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		tk(i,a[i]);
		for(int j=1;j<=20;j++)p[i][j]+=p[i-1][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int yrk=0;
			for(int kp=1;kp<=20;kp++)
			{
				if((p[i][kp]-p[j][kp])%2!=r[kp])
				{
					yrk=1;
					break;
				}
			}
			if(yrk==1)continue;
			for(int kp=j+1;kp<=i;kp++)
			{
				if(t[kp]==1)
				{
					yrk=1;
					break;
				}
				else t[kp]=1;
			}
			if(yrk==1)
			{
//				cout<<j+1<<" "<<i<<endl;
				continue;
				
			}
			else s++;
		}
	}
	cout<<s;
	return 0;
}//#Shang4Shan3Ruo6Shui4
