#include<bits/stdc++.h>
#define int long long 
using namespace std;
int read(){
	int x=0,f=1;
	char c=0;
	while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c&15);c=getchar();}
	return x*f;
}
int n,q,L1,L2;
string s[201000][2],t[200100][2];
namespace sub1{
	bool check(){
		return n<=1000&&q<=1000&&L1<=2000&&L2<=2000;
	}
	const int mod=1e9+7,pp=13331;
	map<pair<int,int>,int> vis;
	int hsh[2][10100],power[10010];
	int gethsh(int l,int r,int op){
		int len=r-l+1;
		return (hsh[op][r]-hsh[op][l-1]*power[len]%mod+mod)%mod;
	}
	void calc(){
		for(int i=1;i<=n;i++){
			int hsh1=0,hsh2=0;
			for(int j=0;j<s[i][0].size();j++){
				hsh1=(hsh1*pp+s[i][0][j])%mod;
				hsh2=(hsh2*pp+s[i][1][j])%mod;
			}
			vis[{hsh1,hsh2}]++;
		}
		power[0]=1;
		for(int i=1;i<=2000;i++)
			power[i]=power[i-1]*pp%mod;
		for(int i=1;i<=q;i++){
			if(t[i][0].size()!=t[i][1].size()){
				cout<<0<<"\n";
				continue;
			}
			int ans=0,nn=t[i][0].size();
			hsh[0][0]=t[i][0][0];
			hsh[1][0]=t[i][1][0];
			for(int j=1;j<nn;j++){
				hsh[0][j]=(hsh[0][j-1]*pp+t[i][0][j])%mod;
				hsh[1][j]=(hsh[1][j-1]*pp+t[i][1][j])%mod;
			}
			int l,r;
			for(int j=0;j<nn;j++)
				if(t[i][0][j]!=t[i][1][j]){
					l=j;
					break;
				}
			for(int j=nn-1;j>=0;j--)
				if(t[i][0][j]!=t[i][1][j]){
					r=j;
					break;
				}
			for(int i=0;i<=l;i++)
				for(int j=r;j<nn;j++)
					ans+=vis[{gethsh(i,j,0),gethsh(i,j,1)}];
			cout<<ans<<"\n";
		}
	}
}
namespace sub2{
	bool check(){
		for(int i=1;i<=n;i++){
			int num=0;
			for(int j=0;j<s[i][0].size();j++)
				if(s[i][0][j]=='b')
					num++;
			if(num!=1)	return 0;
			num=0;
			for(int j=0;j<s[i][1].size();j++)
				if(s[i][1][j]=='b')
					num++;
			if(num!=1)	return 0;
		}
		for(int i=1;i<=q;i++){
			int num=0;
			for(int j=0;j<t[i][0].size();j++)
				if(t[i][0][j]=='b')
					num++;
			if(num!=1)	return 0;
			num=0;
			for(int j=0;j<t[i][1].size();j++)
				if(t[i][1][j]=='b')
					num++;
			if(num!=1)	return 0;
		}
		return 1;
	}
	vector<int> st[2010000];
	map<pair<int,int>,int> vis[2];
	int cnt;
	void calc(){
		for(int i=1;i<=n;i++){
			if(s[i][0]==s[i][1])	continue;
			int l,r,nn=s[i][0].size();
			for(int j=0;j<nn;j++)
				if(s[i][0][j]!=s[i][1][j]){
					l=j;
					break;
				}
			for(int j=nn-1;j>=0;j--)
				if(s[i][0][j]!=s[i][1][j]){
					r=j;
					break;
				}
			if(!vis[s[i][0][l]-'a'][{r-l+1,l}])
				vis[s[i][0][l]-'a'][{r-l+1,l}]=++cnt;
			int root=vis[s[i][0][l]-'a'][{r-l+1,l}];
			st[root].push_back(nn-r-1);
		}
		for(int i=1;i<=cnt;i++)
			sort(st[i].begin(),st[i].end());
		for(int i=1;i<=q;i++){
			if(t[i][0].size()!=t[i][1].size()){
				cout<<0<<"\n";
				continue;
			}
			int l,r,nn=t[i][0].size();
			for(int j=0;j<nn;j++)
				if(t[i][0][j]!=t[i][1][j]){
					l=j;
					break;
				}
			for(int j=nn-1;j>=0;j--)
				if(t[i][0][j]!=t[i][1][j]){
					r=j;
					break;
				}
			int ans=0;
			for(int j=l;j>=0;j--){
				int root=vis[t[i][0][l]-'a'][{r-l+1,j}];
				if(root){
					int x=upper_bound(st[root].begin(),st[root].end(),nn-r-1)-st[root].begin();
					ans+=x;
				}
			}
			cout<<ans<<"\n";
		}
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		L1+=s[i][0].size()*2;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		L2+=t[i][0].size()+t[i][1].size();
	}
	if(sub1::check())
		sub1::calc();
	else if(sub2::check())
		sub2::calc();
	return 0;
}


