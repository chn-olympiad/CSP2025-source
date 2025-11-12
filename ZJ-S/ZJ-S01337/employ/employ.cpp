#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
const int inf=0x3f3f3f3f,mod=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
int n,m,ans=0,tot=0,cnt[2],c[505],a[505],p[505];
bool b[505];
inline int getfct(int n){
	int res=1;
	for(int i=1;i<=n;++i)res=(1ll*res*i)%mod;
	return res;
}
//inline int popcnt(int x){
//	int res=0;
//	while(x)res+=x&1,x>>=1;
//	return res;
//}
//void dfs(int x){
//	if(x>n){
//		if(tot<m)return;
//		vec.clear();
//		int lst=0,res=1,st=0;
//		for(int i=1;i<=n;++i)
//			if(b[i]==1)vec.push_back(i-lst-1),lst=i;
//		for(int i=1,cc=0;i<=n;++i){
//			if(c[i]){
//				if(b[i])st|=(1<<cc);
//				++cc;
//			}
//		}
//		sort(vec.begin(),vec.end());
//		for(int i=(int)vec.size()-1;i>=0;--i){
//			if(s[vec[i]+1]>((int)vec.size()-1)-i)res=(1ll*res*(s[vec[i]+1]+i-((int)vec.size()-1)));
//			else res=0;
//		}
////		int w=(tot%2==m%2)?1:(-1);
////		printf("%lld\n",res*getfct(n-tot));
//		ans=(ans+1ll*res*getfct(n-tot)*ss[st]%mod+mod)%mod;
//		return;
//	}
//	if(c[x]==0)dfs(x+1);
//	else{
//		b[x]=0,dfs(x+1);
//		b[x]=1,++tot,dfs(x+1),b[x]=0,--tot;
//	}
//}
void dfs(int x){
	if(x>n){
		int lst=0,cnt=0;
		for(int i=1;i<=n;++i){
			if(c[i]&&a[p[i]]>lst)lst=0,++cnt;
			else ++lst;
		}
		ans=(ans+(cnt>=m))%mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(b[i])continue;
		b[i]=1,p[x]=i,dfs(x+1),b[i]=0;
	}
}
inline bool check(){
	for(int i=1;i<=n;++i)
		if(c[i]==0||a[i]==0)return 0;
	return 1;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		char ch;cin>>ch;
		c[i]=ch-'0',++cnt[ch-'0'];
	}
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	if(n<=10){
		dfs(1);
		printf("%lld\n",ans);
	}
	else{
		if(check())printf("%lld\n",getfct(n));
		else printf("0\n");
	}
	return 0;
}
//8(:D
