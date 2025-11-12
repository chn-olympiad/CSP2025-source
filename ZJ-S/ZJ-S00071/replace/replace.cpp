#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define _F(i,a,b) for(int i=(a);i>=(b);i--)
#define ull unsigned long long
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
ull h1[N],h2[N],g1[N],g2[N],t[int(2e6+5)];
int l1[N],r1[N];
ull p[int(2e6+5)];
void dohash(int x){
	int l=0,r=sizeof(s1[x])-1;
	ull tmp=0;
	F(i,0,s1[x].size()-1)
		if(s1[x][i]!=s2[x][i]){
			l=i;
			break;
		}
	_F(i,s1[x].size()-1,0)
		if(s1[x][i]!=s2[x][i]){
			r=i;
			break;
		}
	l1[x]=l;
//	printf("%d %d %d\n",x,l,r);	
	F(i,l,r){
		h1[x]=h1[x]*37+s1[x][i];
		h2[x]=h2[x]*37+s2[x][i];
	}
	F(i,0,s1[x].size()-1){
		g1[x]=g1[x]*37+s1[x][i];
		g2[x]=g2[x]*37+s2[x][i];
	}
	return;
}
void check(int x){
	int l=0,r=t1[x].size()-1;
	ull tmp1=0,tmp2=0;
	F(i,0,t1[x].size()-1)
		if(t1[x][i]!=t2[x][i]){
			l=i;
			break;
		}
	_F(i,t1[x].size()-1,0)
		if(t1[x][i]!=t2[x][i]){
			r=i;
			break;
		}
	int ttp=0;
	F(i,0,t1[x].size()-1){
		t[i]=ttp*37+t1[x][i];
		ttp=t[i];
	}
	F(i,l,r){
		tmp1=tmp1*37+t1[x][i];
		tmp2=tmp2*37+t2[x][i];
	}
	int ret=0;
	F(i,1,n){
//		printf("%lld %lld\n",h2[i],tmp2);
		if(tmp1==h1[i]&&tmp2==h2[i]){
			int lq=l-l1[i];
			int rq=lq+s1[i].size()-1;
			if(lq>=0){
				if(g1[i]==t[rq]-p[rq-lq+1]*(lq==0?0:t[lq-1]))
					ret++;
//				cout<<g1[i]<<" "<<t[rq]-p[rq-lq+1]*(lq==0?0:t[lq-1]);
			}
		}
	}
	cout<<ret<<"\n";
}
signed main()
{
 freopen("replace.in","r",stdin);
 freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	F(i,1,n){
		cin>>s1[i]>>s2[i];
	}
	F(i,1,q){
		cin>>t1[i]>>t2[i];
	}
	p[0]=1;
	F(i,1,int(2e6)){
		p[i]=p[i-1]*37;
	}
	F(i,1,n){
		dohash(i);
	}
	F(i,1,q){
		check(i);
	}
   return 0;
}
//why string
//he yi wei
