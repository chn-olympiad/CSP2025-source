#include <bits/stdc++.h>
using namespace std;
int t,n,cnt[200005],n_,max_[5],cnt_[5],cnt__,max__,s[200005][5];
struct xx
{
	int s__,id,id_;
}s_[5];
struct node
{
	int n1,id;
}a[200005];
struct node_
{
	int n2,id;
}b[200005];
struct node__
{
	int n3,id;
}c[200005];
bool cmp(node x,node y)
{
	return x.n1>=y.n1;
}
bool cmp_(node_ x,node_ y)
{
	return x.n2>=y.n2;
}
bool cmp__(node__ x,node__ y)
{
	return x.n3>=y.n3;
}
bool cm(xx x,xx y)
{
	return x.s__>=y.s__;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		n_=n/2;
		cnt__=0;
		for(int i=1;i<=3;i++)
		{
			cnt[i]=1;
			max_[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			cnt_[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>s[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			a[i].n1=s[i][1];
			b[i].n2=s[i][2];
			c[i].n3=s[i][3];
			a[i].id=i;
			b[i].id=i;
			c[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp_);
		sort(c+1,c+1+n,cmp__);
		for(int i=1;i<=n;i++)
		{
			s_[1].s__=a[i].n1;
			s_[1].id=1;
			s_[1].id_=a[i].id;
			s_[2].s__=b[i].n2;
			s_[2].id=2;
			s_[2].id_=b[i].id;
			s_[3].s__=c[i].n3;
			s_[3].id=3;
			s_[3].id_=c[i].id;
			sort(s_+1,s_+4,cm);
			if(cnt[s_[1].id]<=n_)
			{
				if(cnt_[s_[1].id_]==0)
				{
					cnt__+=s_[1].s__;
					cnt_[s_[1].id_]=1;
					cnt[s_[1].id]++;
				}
			}
			if(cnt[s_[2].id]<=n)
			{
				if(cnt_[s_[2].id_]==0)
				{
					cnt__+=s_[2].s__;
					cnt_[s_[2].id_]=1;
					cnt[s_[2].id]++;
				}
			}
			if(cnt[s_[3].id]<=n)
			{
				if(cnt_[s_[3].id_]==0)
				{
					cnt__+=s_[3].s__;
					cnt_[s_[3].id_]=1;
					cnt[s_[3].id]++;
				}
			}
		}
		cout<<cnt__<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	
 } 
