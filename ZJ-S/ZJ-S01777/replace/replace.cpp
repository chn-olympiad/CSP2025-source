#include<bits/stdc++.h>
using namespace std;
//const int N=1e4+5,KK=15,M=1e6+5,MM=1200; 
#define fst first
#define scd second
#define llg long long
#define pii pair<int,int>
#define mkp make_pair
const int inf=2e9;
const int M=2500000,N=1e6+5,B=29;
const llg mod=998244353;

//unorded_map<int,int> tr[N];
int n,q,cnt;
int h[5][M];
int hed[N],til[N],len[N];
int b[M];
string s,t;

inline int hsh(int L,int R,int id){
	if(L>R) return 0;
	return (mod+h[id][R]-(1ll*h[id][L-1]*b[R-L+1]%mod))%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	b[0]=1; for(int i=1; i<=N-5; i++) b[i]=1ll*b[i-1]*B%mod;
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s; cin>>t;
		len[i]=s.length(); s=" "+s; t=" "+t;
		hed[i]=cnt+1;
		for(int j=1; j<=len[i]; j++){
			++cnt;
			h[0][cnt]=(1ll*h[0][cnt-1]*B+s[j]-'a'+1)%mod;
			h[1][cnt]=(1ll*h[1][cnt-1]*B+t[j]-'a'+1)%mod;
		}
		til[i]=cnt;
	}
	for(int i=1; i<=q; i++){
		cin>>s; cin>>t;
		int u=s.length(),v=t.length(); s=" "+s; t=" "+t;
		llg ans=0;
		if(u!=v){
			cout<<0<<"\n"; continue;
		}
		cnt=0;
		for(int j=1; j<=u; j++){
			++cnt;
			h[2][cnt]=(1ll*h[2][cnt-1]*B+s[j]-'a'+1)%mod;
			h[3][cnt]=(1ll*h[3][cnt-1]*B+t[j]-'a'+1)%mod;
		}
		int l=0,r=u+1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(hsh(1,mid,2)==hsh(1,mid,3)) l=mid;
			else r=mid-1;
		}
		int L=l+1;
		l=0,r=u+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(hsh(mid,u,2)==hsh(mid,u,3)) r=mid;
			else l=mid+1;
		}
		int R=r-1;
	//	cout<<L<<" "<<R<<"\n";
		if(true){
			for(int j=R; j<=u; j++)
				for(int k=1; k<=n; k++) if(j-len[k]+1<=L){
					if(hsh(hed[k],til[k],0)==hsh(j-len[k]+1,j,2)&&hsh(hed[k],til[k],1)==hsh(j-len[k]+1,j,3)){
						ans++;
					//	cout<<hed[k]<<" "<<til[k]<<" "<<j-len[k]+1<<" "<<j<<"\n";
					}
				}
		}
//		else{
//			for(int j=1; j<=L; j++)
//				for(int k=1; k<=n; k++) if(j+len[k]-1>=R){
//					if(hsh(hed[k],til[k],0)==hsh(j,j+len[k]-1,2)&&hsh(hed[k],til[k],1)==hsh(j,j+len[k]-1,3)){
//						ans++;
//					//	cout<<hed[k]<<" "<<til[k]<<" "<<j-len[k]+1<<" "<<j<<"\n";
//					}
//				}
//		}
		
		cout<<ans<<"\n";
	}
}
