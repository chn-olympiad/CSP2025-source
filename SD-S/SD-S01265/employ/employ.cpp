#include <iostream>
typedef long long ll;
const int N=5e2+10,mod=998244353;
int n,m;
std::string s;
int a[N],p[N];
int ans,len,cnt;
bool st[N];
void work1(int depth){
	if(depth==n){
		int fail=0,ress=0;
		for(int i=0;i<n;i++){
			if(fail>=a[p[i]]){
				fail++;
			}else{
				if(s[i]=='0'){
					fail++;
				}else{
					ress++;
				}
			}
		}
		if(ress>=m) ans++;
		if(ans==mod) ans=0;
		return;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==false){
			st[i]=true;
			p[depth]=i;
			work1(depth+1);
			p[depth]=0;
			st[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::cin>>n>>m>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='1') cnt++;
	}
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	if(n<=10){//1,2
		work1(0);
		std::cout<<ans<<'\n';
		return 0;
	}
	if(cnt==len){//6,7,8,16,17
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0) cntt++;
		}
		if(cntt>=m){
			ll res=1ll;
			for(ll i=1ll;i<=(ll)cntt;i++){
				res=res*i%mod;
			}
			for(ll i=1ll;i<=(ll)(n-cntt);i++){
				res=res*i%mod;
			}
			std::cout<<res<<'\n';
		}else std::cout<<"0\n";
		return 0;
	}
	if(m==n){//15
		if(cnt!=len) std::cout<<"0\n";
		else{
			int cntt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) cntt++;
			}
			if(cntt==0){
				ll res=1ll;
				for(ll i=1ll;i<=(ll)n;i++){
					res=res*i%mod;
				}
				std::cout<<res<<'\n';
			}else std::cout<<"0\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
