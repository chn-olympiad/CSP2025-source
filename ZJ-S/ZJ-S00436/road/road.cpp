#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
inline long long read()
{
	long long tot=0;char c=getchar();
	while(!('0'<=c&&c<='9'))c=getchar();
	while('0'<=c&&c<='9')tot=tot*10+c-'0',c=getchar();
	return tot;
}

int nxt[4000005],fir[20005],son[4000005],tt;
long long w[4000005],d[10105],a[15][10005];
int v[10105];
long long c[15];
struct data{
	int ip;
	long long wp;
	bool operator <(const data &x)const{
		return wp>x.wp;
	}
};
priority_queue<data>q;


inline void add(int x,int y,long long z)
{
	tt++;
	nxt[tt]=fir[x];
	fir[x]=tt;
	son[tt]=y;
	w[tt]=z;
	return ;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	long long u,vv,ww;
	for(int i=1;i<=m;++i)
	{
		u=read(),vv=read(),ww=read();
		add(u,vv,ww);
		add(vv,u,ww);
	}
	int ftt=0;
	for(int i=1;i<=k;++i)
	{
		c[i]=read();
		if(c[i]!=0)ftt=1;
		int fttt=0;
		for(int j=1;j<=n;++j)
		{
			a[i][j]=read();
			if(a[i][j]==0)fttt=1;
//			add(i+n,j,ww);
//			add(j,i+n,ww+c[i]);
		}
		if(fttt==0)ftt=1;
	}
	if(ftt==0)
	{
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(a[i][j]==0)
				{
					for(int h=1;h<=n;h++)
					{
						if(h==j)continue;
						add(j,h,a[i][h]);
						add(h,j,a[i][h]);
					}
					
				}
			}
		}
		
		long long res=0;
		memset(d,0x3f,sizeof(d));
		data o,oo;
		o.ip=1;
		o.wp=0;
		q.push(o);
		while(!q.empty())
		{
			//cout<<o.ip<<endl;
			o=q.top();
			q.pop();
			if(v[o.ip]==1)
			{
				continue;
			}
			else
			{
				v[o.ip]=1;
				res+=o.wp;
			}
			for(int j=fir[o.ip];j;j=nxt[j])
			{
				if(v[son[j]]==0&&w[j]<d[son[j]])
				{
					oo.ip=son[j];
					oo.wp=w[j];
					d[son[j]]=w[j];
					q.push(oo);
				}
			}
		}
		cout<<res;
		return 0;
	}
	
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=n;++j)
		{
			add(i+n,j,a[i][j]);
			add(j,i+n,a[i][j]+c[i]);
		}
	}

	//return 0;
	ans=-1;
	//cout<<tt<<endl;
	//k=0;
	for(int i=0;i<(1<<k);++i)
	{
		//cout<<i<<endl;
		int tut=0;
		long long res=0;
		memset(v,0,sizeof(v));
		memset(d,0x3f,sizeof(d));
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				v[j+n]=0;
			}
			else
			{
				v[j+n]=1;
			}
		}
		data o,oo;
		o.ip=1;
		o.wp=0;
		q.push(o);
		while(!q.empty())
		{
			//cout<<o.ip<<endl;
			tut++;
			o=q.top();
			q.pop();
			if(v[o.ip]==1)
			{
				continue;
			}
			else
			{
				v[o.ip]=1;
				res+=o.wp;
			}
			for(int j=fir[o.ip];j;j=nxt[j])
			{
				if(v[son[j]]==0&&w[j]<d[son[j]])
				{
					oo.ip=son[j];
					oo.wp=w[j];
					d[son[j]]=w[j];
					q.push(oo);
				}
			}
		}
		if(ans==-1)ans=res;
		ans=min(ans,res);
		//cout<<"k"<<' '<<tut<<endl;
	}
	cout<<ans;
	return 0;
}
