#include<bits/stdc++.h>
using namespace std;
int T,cnt[5],n,m,a[5][100005];
struct node{
	int a,b,c;
}p[100005];
struct edge{
	int va,vb,vc,v1;
}q[100005];
long long ans;
bool cmp(edge x,edge y)
{
	return x.v1<y.v1;
}
void tiaoa()
{
	for(int i=1;i<=cnt[1];i++)
	{
		q[i].vb=p[a[1][i]].a-p[a[1][i]].b;
		q[i].vc=p[a[1][i]].a-p[a[1][i]].c;
		q[i].v1=min(q[i].vc,q[i].vb);
	}
	sort(q+1,q+cnt[1]+1,cmp);
	int k=cnt[1]-m;
	for(int i=1;i<=k;i++)
	{
		edge u=q[i];
		if(u.vb<=u.vc){
			ans-=u.vb;
		}else{
			ans-=u.vc;
		}
	}
	return;
}
void tiaob()
{
	for(int i=1;i<=cnt[2];i++)
	{
		q[i].va=p[a[2][i]].b-p[a[2][i]].a;
		q[i].vc=p[a[2][i]].b-p[a[2][i]].c;
		q[i].v1=min(q[i].va,q[i].vc);
	}
	sort(q+1,q+cnt[2]+1,cmp);
	int k=cnt[2]-m;
	for(int i=1;i<=k;i++)
	{
		edge u=q[i];
		if(u.va<=u.vc){
			ans-=u.va;
		}else{
			ans-=u.vc;
		}
	}
	return;
}
void tiaoc()
{
	for(int i=1;i<=cnt[3];i++)
	{
		q[i].va=p[a[3][i]].c-p[a[3][i]].a;
		q[i].vb=p[a[3][i]].c-p[a[3][i]].b;
		q[i].v1=min(q[i].va,q[i].vb);
	}
	sort(q+1,q+cnt[3]+1,cmp);
	int k=cnt[3]-m;
	for(int i=1;i<=k;i++)
	{
		edge u=q[i];
		if(u.va<=u.vb){
			ans-=u.va;
		}else{
			ans-=u.vb;
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			m=max({p[i].a,p[i].b,p[i].c});
			if(p[i].a==m){
				a[1][++cnt[1]]=i;
			}else if(p[i].b==m){
				a[2][++cnt[2]]=i;
			}else{
				a[3][++cnt[3]]=i;
			}
			ans+=m;
		}
		m=n/2;
		if(cnt[1]<=m&&cnt[2]<=m&&cnt[3]<=m){
			cout<<ans<<"\n";
		}else{
			if(cnt[1]>m){
				tiaoa();
			}else if(cnt[2]>m){
				tiaob();
			}else{
				tiaoc();
			}
			cout<<ans<<"\n";
		}
	}

	return 0;
}
