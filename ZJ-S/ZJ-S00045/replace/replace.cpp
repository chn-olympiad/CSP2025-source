#include<bits/stdc++.h>
namespace sol {
	using namespace std;
	int n,q;
	constexpr int maxn=2e5+7,maxl=5e6+7;
	typedef unsigned long long ull;
	constexpr ull base=113,mod=20080117;
	struct Rep {
		string s1,s2;
		ull h1,h2;
	} rep[maxn],t;
	ull th1[maxl/2],th2[maxl/2],powbs[maxl/2];
	bool cmp1(const Rep&lhs,const Rep&rhs) {
		return lhs.s1.size()>rhs.s1.size();
	}
	ull geths(ull*h,int l,int r) {
		if(l<=r)
			return (h[r]+mod-h[l-1]*powbs[r-l+1]%mod)%mod;
		else return 0;
	}
	int main() {
		powbs[0]=1;
		for(int i=1; i<maxl/2; ++i)
			powbs[i]=powbs[i-1]*base%mod;
		ios::sync_with_stdio(false);
		scanf("%d%d",&n,&q);
		for(int i=1,j; i<=n; ++i) {
			cin>>rep[i].s1>>rep[i].s2;
			for(j=0; j<rep[i].s1.length(); ++j)
				rep[i].h1=(rep[i].h1*base+(rep[i].s1[j]-'a'+1))%mod;
			for(j=0; j<rep[i].s2.length(); ++j)
				rep[i].h2=(rep[i].h2*base+(rep[i].s2[j]-'a'+1))%mod;
		}
		sort(rep+1,rep+n+1,cmp1);
		for(int i=1,j,l,r,k; i<=q; ++i) {
			cin>>t.s1>>t.s2;
			if(t.s1.size()!=t.s2.size()){
				puts("0");
				continue;
			}
			for(j=1; j<=t.s1.length(); ++j)
				th1[j]=(th1[j-1]*base+(t.s1[j-1]-'a'+1))%mod;
			bool flag=true;
			l=0,r=t.s1.size()+1;
			for(j=1; j<=t.s1.length(); ++j) {
				th2[j]=(th2[j-1]*base+(t.s2[j-1]-'a'+1))%mod;
				if(flag&&t.s1[j-1]==t.s2[j-1])
					++l;
				else flag=false;
			}
			for(j=t.s1.size()-1; j>=0; --j)
				if(t.s1[j]==t.s2[j])
					--r;
				else break;
			int len=r-l-1;
			long long ans=0;
			for(j=1; j<=n&&rep[j].s1.size()>=len; ++j)
				if(rep[j].s1.size()<=t.s1.size()) {
					int slen=rep[j].s1.size(),tlen=t.s1.size();
					for(k=max(1,r-slen-1); k<=min(l+slen+1,tlen-slen+1); ++k)
						if(geths(th1,k,k+slen-1)==rep[j].h1
						        &&geths(th2,k,k+slen-1)==rep[j].h2) {
							int tr=k+slen-1;
//							if((geths(th1,1,k-1)*powbs[tlen-k+1]%mod+rep[j].h2*powbs[tlen-tr]%mod+geths(
//							            th1,tr+1,tlen)%mod)%mod==th2[tlen]) {
//								printf("%d:",q);
//								cout<<rep[j].s1<<' '<<rep[j].s2<<endl;
//							}
							ans+=(geths(th1,1,k-1)==geths(th2,1,k-1)&&geths(th1,tr+1,tlen)==geths(th2,tr+1,tlen));
//							ans+=((geths(th1,1,k-1)*powbs[tlen-k+1]%mod+rep[j].h2*powbs[tlen-tr]%mod+geths(
//							           th1,tr+1,tlen)%mod)%mod==th2[tlen]);
						}
				}
			printf("%lld\n",ans);
		}
		cout.flush();
		fflush(stdout);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return sol::main();
}