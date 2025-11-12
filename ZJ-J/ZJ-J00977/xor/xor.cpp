#include<bits/stdc++.h>
using namespace std;
int n,k,len1,len2;
const int N=5e5+10;
int a[N],c[N],d[N],e[N];
struct st{
	int l,r;
}q[N];
int b[N];
long long cnt;
int sjz(int p[],int len)
{
	int sum=0;
	for(int i=0;i<=len;i++)
	{
		//if(p[i]==0) break;
		sum+=pow(2,i)*p[i];
	}
	return sum;
}
void ejz1(int x)
{
	memset(c,0,sizeof(c));
	int ans=0;
	while(x)
	{
		c[++ans]=x%2;
		x/=2;
	}
	len1=ans;
}
void ejz2(int x)
{
	memset(d,0,sizeof(d));
	int ans=0;
	while(x)
	{
		d[++ans]=x%2;
		x/=2;
	}
	len2=ans;
}
int eh( )
{
	memset(e,0,sizeof(e));
	int l=max(len1,len2);
	for(int i=1;i<=l;i++)
	{
		//if(c[i]==0&&d[i]==0) break;
		if(c[i]!=d[i]) e[i-1]=1;
		else e[i-1]=0;
	}
	return sjz(e,l);
}
bool cmp(st x,st y)
{
	if(x.l!=y.l)
	return x.l<y.l;
	else return x.r<y.r;
}
int main()
{
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
			if(x==k) 
			{
				q[++cnt].l=i;
				q[cnt].r=i;
			}		
		for(int j=i+1;j<=n;j++)
		{
			ejz1(x);
			ejz2(a[j]);
			x=eh();
				if(x==k) 
			{
				q[++cnt].l=i;
				q[cnt].r=j;
			}
		}
	}
	sort(q+1,q+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		b[i]=1;
		for(int j=1;j<i;j++)
		{
			if(q[i].l>q[j].r)
			{
				b[i]=max(b[i],b[j]+1);
			}
		}
		ans=max(ans,b[i]);
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
