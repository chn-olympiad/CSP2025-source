#include<bits/stdc++.h>
using namespace std;
int n,k,a[50];
int m;
int mx;
string s[50005];
int c[50005];
int f;
int b,t;
int tot;
int ans;
struct stu{
	int l;
	int r;
};
stu d[50005];
bool cmp(stu a,stu b)
{
	return a.l<b.l;
}
void ax(int z,int y)
{
	t=0;
	for(int i=0;i<=20;i++)
	{
		t=0;
		for(int j=z;j<=y;j++)
		{
			if(s[j][i]=='1') t++;
		}
		if(t%2!=0) b=b+a[i];
	}
	if(z==y) b=c[z];
	if(b==k)
	{
		tot++;
		d[tot].l=z;
		d[tot].r=y;
	}
}
void fin(int h)
{
	for(int i=h;i<=tot;i++)
	{
		if(d[i].l>d[h].r)
		{
			fin(i);
			ans++;
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	a[0]=1;
	for(int i=1;i<=21;i++)
	{
		a[i]=a[i-1]*2;
	}
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		c[i]=m;
		f=0;
		for(int j=26;j>=0;j--)
		{
			if(m>=a[j])
			{
				f=1;
			}
			
			if(f==1)
			{
				if(m>=a[j])
				{
					m=m-a[j];
					s[i]+="1";
				}
				else s[i]+="0";
			}
		}
		for(int j=0;j<s[i].length()/2;j++)
		{
			swap(s[i][j],s[i][s[i].length()-1-j]);
		}
		if(s[i].length()==0) s[i]+="0";
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			b=0;
			t=0;
			ax(i,j);
		}
	}
	sort(d+1,d+1+tot,cmp);
	for(int i=1;i<=tot;i++)
	{
		ans=0;
		fin(i);
		mx=max(mx,ans);
	}
	cout<<mx+1;
	return 0;
	
 } 
