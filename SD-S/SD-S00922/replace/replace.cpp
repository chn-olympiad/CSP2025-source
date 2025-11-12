#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define ret return
#define mp make_pair
#define pb push_back
#define mid (l+r>>1)
#define Mod 1000000007
using namespace std;
using namespace __gnu_pbds;
int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	ret s*f;
}
const int N=2e5+10;
gp_hash_table<int,int> Map,Vis,Tag;
int len[N],id[N];
vector<char> a[N],b[N];
vector<int> ha[N],hah;
bool cmp(int x,int y){ret len[x]<len[y];}
void solve(){
	int n=read(),q=read(),siz;char ch;
	for(int i=1;i<=n;i++){
		ch=getchar();siz=0;while(ch!=' '&&ch!='\n')a[i].pb(ch),ch=getchar(),++siz;
		ch=getchar();siz=0;while(ch!=' '&&ch!='\n')b[i].pb(ch),ch=getchar(),++siz;
		len[i]=siz;id[i]=i;for(int j=0;j<siz;j++)ha[i].pb(((j?ha[i][j-1]:0)*13331+(a[i][j]-'a')*26+b[i][j]-'a'+1)%Mod);
	}
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++){
		int sum=0;Map[ha[id[i]][len[id[i]]-1]]++;
		for(int j=0;j<len[id[i]];j++){
			sum+=Map[ha[id[i]][j]];
			Vis[ha[id[i]][j]]=sum;
			Tag[ha[id[i]][j]]=1;
		}
	}
	while(q--){
		vector<char> s,t;int ans=0,pw=1,ed;
		ch=getchar();while(ch!=' '&&ch!='\n')s.pb(ch),ch=getchar();
		ch=getchar();while(ch!=' '&&ch!='\n')t.pb(ch),ch=getchar();
		if(s.size()!=t.size()){puts("0");continue;}siz=s.size();hah.resize(siz);
		for(int i=0;i<siz;i++)hah[i]=((i?hah[i-1]:0)*13331+(s[i]-'a')*26+t[i]-'a'+1)%Mod;
		for(int i=siz-1;i>=0;i--){ed=i;if(s[i]!=t[i])break;}
		for(int i=0;i<siz;i++){
			int l=i,r=siz-1;
			while(l<=r){
				if(Tag[(hah[mid]-(i?hah[i-1]:0)*pw%Mod+Mod)%Mod])l=mid+1;
				else r=mid-1;
			}
			if(r>=i&&r>=ed)ans+=Vis[(hah[r]-(i?hah[i-1]:0)*pw%Mod+Mod)%Mod];pw=pw*13331%Mod;
			if(s[i]!=t[i])break;
		}
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t=1;while(t--)solve();ret 0;
}
