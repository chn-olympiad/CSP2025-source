#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define endl "\n"
const int p=131;
ll n,q,h[2005],k[2005],s[2005],ans,cnt[10005],len,cnj[10005];
string pd[1005];
map<ll,ll> ha;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		a=" "+a;
		b=" "+b;
		ll sum=0;
		for(int i=1;i<=a.size();++i){
			sum=sum*p+a[i]-'a';
		}
		ll num=0;
		for(int i=1;i<b.size();++i){
			num=num*p+b[i]-'a';
		}
		ha[sum]=num;
		cnt[++len]=sum;
		pd[len]=b;
	}
	while(q--){
		ans=0;
		string a,b;
		cin>>a>>b;
		a=" "+a;
		b=" "+b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		k[0]=1;
		for(int i=1;i<a.size();++i){
			h[i]=h[i-1]*p+a[i]-'a';
			s[i]=s[i-1]*p+b[i]-'a';
			k[i]=k[i-1]*p;
		}
		for(int i=1;i<=len;++i){
			bool flag=0,p=0;
			int l,r;
			string tp;
			for(int j=1;j<a.size();++j){
				for(int w=j;w<=a.size();++w){
					if(h[w]-h[j-1]*k[w-j+1]==cnt[i]){
						l=j;
						r=w;
						flag=1;
						break;
					}
				}
				if(flag) break;
			}
			for(int j=1;j<b.size();++j){
				for(int w=j;w<=b.size();++w){
					if(s[w]-s[j-1]*k[w-j+1]==cnt[i]){
						p=1;
						break;
					}
				}
				if(p) break;
			}
			if(!flag||!p) continue;
			for(int j=0;j<l;++j) tp+=a[j];
			for(int j=1;j<pd[i].size();++j) tp+=pd[i][j];
			for(int j=r+1;j<a.size();++j) tp+=a[j];
			if(tp==b) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}