#include<bits/stdc++.h>
#define fi first
#define se second
#define PII pair<int,int>
#define int long long
using namespace std;
const int B1=303,B2=503,mod1=998244353,mod2=998244853;
int ksm(int x,int y,int p){
	if(y==0) return 1;
	if(y==1) return x;
	int tmp=ksm(x,y>>1,p);	
	if(y&1){
		return ((tmp*tmp)%p)*x%p;	
	}
	return tmp*tmp%p;
}
const int N=5e6+5;
int hash1A[N],hash2A[N],hash1B[N],hash2B[N],base1[N],base2[N],n,q;
PII gethashA(int l,int r){
	return {hash1A[r]-hash1A[l-1]*base1[r-l+1]%mod1,hash2A[r]-hash2A[l-1]*base2[r-l+1]%mod2}; 
}
PII gethashB(int l,int r){
	return {hash1B[r]-hash1B[l-1]*base1[r-l+1]%mod1,hash2B[r]-hash2B[l-1]*base2[r-l+1]%mod2}; 
}
struct node{
	int a,b,c,d;
};
vector<int>t[5000005],tt;
void solve(){
	for(int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		a=' '+a,b=' '+b;
		int x,y;
		for(int j=1;j<a.size();++j){
			if(a[j]=='b') x=j;				
		}
		for(int j=1;j<a.size();++j){
			if(b[j]=='b') y=j;				
		}
		t[x].push_back(y);
		tt.push_back(x);
	}
	for(auto a:tt){
		sort(t[a].begin(),t[a].end());	
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		a=' '+a,b=' '+b;
		int x,y;
		for(int j=1;j<a.size();++j){
			if(a[j]=='b') x=j;				
		}
		for(int j=1;j<a.size();++j){
			if(b[j]=='b') y=j;				
		}
		int ans=0;
		for(int i=1;i<=min(x,y);++i){
			int l=0,r=t[x-i+1].size()-1;
//			for(auto a:t[x-i+1]) cout<<a<<' ';
//			cout<<'\n';
//			cout<<y-i+1<<' ';
//			cout<<'\n';
			int u=0,v=-1;
			if(r==-1) continue ;
			while(l<=r){
				int mid=l+r>>1;
				if(t[x-i+1][mid]>=y-i+1){
					u=mid;
					r=mid-1;	
				}
				else l=mid+1;
			}
			if(t[x-i+1][u]!=y-i+1) continue ;
			l=0,r=t[x-i+1].size()-1;
			while(l<=r){
				int mid=l+r>>1;
				if(t[x-i+1][mid]>y-i+1){
					v=mid;
					r=mid-1;	
				}
				else l=mid+1;
			}
			if(v==-1) v=t[x-i+1].size();
//			cout<<u<<' '<<v<<'\n';
			ans+=v-u;
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	map<pair<PII,PII>,int>p;
	base1[0]=1,base2[0]=1;
	for(int i=1;i<=5000000;++i){
		base1[i]=base1[i-1]*B1%mod1;
		base2[i]=base2[i-1]*B2%mod2;
	}
	cin>>n>>q;
	if(n>1e3||q>1e3){
		solve();
		return 0;	
	}
	for(int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		a=' '+a,b=' '+b;
		int hsh1=0,hsh2=0;
		for(int j=1;j<a.size();++j){
			hsh1=hsh1*B1+a[j]-'a'+1;
			hsh2=hsh2*B2+a[j]-'a'+1;
			hsh1%=mod1;
			hsh2%=mod2;
		}
		int tmp1=hsh1,tmp2=hsh2;
		hsh1=0,hsh2=0;
		for(int j=1;j<a.size();++j){
			hsh1=hsh1*B1+b[j]-'a'+1;
			hsh2=hsh2*B2+b[j]-'a'+1;
			hsh1%=mod1;
			hsh2%=mod2;
		}
		node tmp={tmp1,tmp2,hsh1,hsh2};
		p[{{tmp1,tmp2},{hsh1,hsh2}}]++;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		int n=a.size();
		a=' '+a,b=' '+b;
		int ed=1,bg=n;
		hash1A[0]=0,hash1B[0]=0,hash2A[0]=0,hash2B[0]=0;
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i]){
				if(bg==n) bg=i;	
				ed=i;
			}
			hash1A[i]=hash1A[i-1]*B1+a[i]-'a'+1;
			hash2A[i]=hash2A[i-1]*B2+a[i]-'a'+1;
			hash1A[i]%=mod1;
			hash2A[i]%=mod2;
			hash1B[i]=hash1B[i-1]*B1+b[i]-'a'+1;
			hash2B[i]=hash2B[i-1]*B2+b[i]-'a'+1;
			hash1B[i]%=mod1;
			hash2B[i]%=mod2;
		}
//		cout<<hash1A[n]<<'\n';
		int ans=0;
		for(int i=1;i<=bg;++i){
			for(int j=ed;j<=n;++j){
				PII a=gethashA(i,j);
				int a1=a.fi,a2=a.se;
				PII b=gethashB(i,j);
				int b1=b.fi,b2=b.se;
				ans+=p[{{a1,a2},{b1,b2}}];
			}
		}
		cout<<ans<<'\n';;
	}
	return 0;
}

