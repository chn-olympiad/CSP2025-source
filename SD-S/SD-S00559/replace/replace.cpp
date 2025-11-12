//by SmileMask
#include<bits/stdc++.h>
using namespace std;

namespace SmileMask{
	#define rd read()
	typedef long long ll;
	int read(){
		int num=0,sign=1;char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') sign=-1;
			ch=getchar();
		}
		while(isdigit(ch)){
			num=(num<<3)+(num<<1)+ch-'0';
			ch=getchar();
		}
		return num*sign;
	}
	
	const int N=2e5+10;
	const ll mod=1e9+7;
	const ll base=233;
	const int M=5e6+10;
	
	ll qmi(ll x,int y){
		ll res=1;
		while(y){
			if(y&1) res=res*x%mod;
			x=x*x%mod;y>>=1;
		} 
		return res;
	}
	
	string S[N][2],T[N][2];
	int lenS[N][2],lenT[N][2];
	
	int n,m;
	
	vector <ll> HashS[N][2],HashT[N][2];
	ll pw[M];
	
	ll get(int l,int r,vector <ll> &h){
		if(l==0||r==0) return 0; 
		if(l>r) return 0;
		return (h[r]-h[l-1]*pw[l-1]%mod+mod)%mod;
	}

	void Main(){
		n=rd,m=rd,pw[0]=1;
		for(int i=1;i<M;i++)
			pw[i]=pw[i-1]*base%mod;
		for(int i=1;i<=n;i++)
			cin>>S[i][0]>>S[i][1],lenS[i][0]=S[i][0].size(),lenS[i][1]=S[i][1].size();
		for(int i=1;i<=m;i++){
			cin>>T[i][0]>>T[i][1],lenT[i][0]=T[i][0].size(),lenT[i][1]=T[i][1].size();
		}
		for(int i=1;i<=n;i++){
			S[i][0]=" "+S[i][0],S[i][1]=" "+S[i][1];
			HashS[i][0].resize(S[i][0].size());
			HashS[i][1].resize(S[i][1].size());
			for(int j=1;j<=lenS[i][0];j++)
				HashS[i][0][j]=(HashS[i][0][j-1]*base%mod+S[i][0][j])%mod;
			for(int j=1;j<=lenS[i][1];j++)
				HashS[i][1][j]=(HashS[i][1][j-1]*base%mod+S[i][1][j])%mod;
		}
		for(int i=1;i<=m;i++){
			T[i][0]=" "+T[i][0],T[i][1]=" "+T[i][1];
			HashT[i][0].resize(T[i][0].size());
			HashT[i][1].resize(T[i][1].size());
			for(int j=1;j<=lenT[i][0];j++)
				HashT[i][0][j]=(HashT[i][0][j-1]*base%mod+T[i][0][j])%mod;
			for(int j=1;j<=lenT[i][1];j++)
				HashT[i][1][j]=(HashT[i][1][j-1]*base%mod+T[i][1][j])%mod;
		}
		if((n<=3000&&m<=3000)||(m==1)){
			map <array<ll,3>,vector<ll>> mp;
			//(<x,y>,z) 
			for(int i=1;i<=n;i++){
				int p=0,q=lenS[i][0]+1;
				while(S[i][0][p+1]==S[i][1][p+1]) p++;
				while(S[i][0][q-1]==S[i][1][q-1]) q--;
				if(p+1>=q) continue; 
				mp[{get(p+1,q-1,HashS[i][0]),get(p+1,q-1,HashS[i][1]),get(1,p,HashS[i][0])}].push_back(get(q,lenS[i][0],HashS[i][0]));
//				cout<<get(p+1,q-1,HashS[i][0])<<' '<<get(p+1,q-1,HashS[i][1])<<' '<<get(1,p,HashS[i][0])<<' '<<get(q,lenS[i][0],HashS[i][0])<<endl; 
			}
			for(int i=1;i<=m;i++){
				map <ll,int> cnt;
				int p=0,q=lenT[i][0]+1;
				while(T[i][0][p+1]==T[i][1][p+1]) p++;
				while(T[i][0][q-1]==T[i][1][q-1]) q--;
				if(p+1>=q) continue;
				ll ans=0;
				ll x=get(p+1,q-1,HashT[i][0]),y=get(p+1,q-1,HashT[i][1]);
				for(int j=1;j<=p+1;j++){
					ll z=get(j,p,HashT[i][0]);
//					cout<<x<<' '<<y<<' '<<z<<endl; 
					for(ll ss:mp[{x,y,z}])
						cnt[ss]++;
				} 
				for(int j=q-1;j<=lenT[i][0];j++){
//					cout<<q<<endl;
					ll z=get(q,j,HashT[i][0]);
//					cout<<z<<endl;
					ans+=cnt[z];
				}
				printf("%lld\n",ans);
			}
		}
		else{
			
		}
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	SmileMask::Main();
	return 0;
}
/*
完蛋了家人们啊。。。。 
*/ 


