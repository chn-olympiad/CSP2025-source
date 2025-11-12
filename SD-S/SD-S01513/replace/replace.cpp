#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define endl "\n"
#define ft first
#define sd second
#define pb push_back
#define ull unsigned long long
using namespace std;
const ll N=1e6+5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,m,T,aans;
string s[N][2];
ll len[N];
ll tn;
string t1,t2,tx[N][2];
namespace sub1{
	ull h[N][2],p[N],t[N],tt;
	ull qjt(ll l,ll r){
		return t[r]-t[l-1]*p[r-l+1];
	}
	void sovle(){
		for(int i=0;i<=tn;i++){
			for(int j=1;j<=n;j++){
	//			cout<<j<<" "<<len[j]<<' '<<tn<<endl;
				if(i+len[j]>tn)continue;
				if(qjt(i+1,i+len[j])!=h[j][0])continue;
				ull ans=t[i]*p[tn-i]+h[j][1]*p[tn-i-len[j]]+qjt(i+len[j]+1,tn);
	//			cout<<i<<" "<<j<<endl;
	//			if(i==2&&j==3){
	////				for(int k=i+1;k<=i+len[j];k++)cout<<t1[k]<<' '<<s[j][0][k-i]<<'\n';
	////				cout<<j<<" "<<s[j][0]<<endl;
	////				cout<<bo <<' '<<s[j][1]<<endl;
	//				cout<<ans<<' '<<t2<<endl;
	//			}
				if(ans==tt){
	//				cout<<i<<" "<<j<<endl;
					aans++;
				}
			}
		}
		cout<<aans<<endl;
	}
	void ssovle(){
		
		ll ma=2000;
		for(int i=1;i<=n;i++){
			len[i]=s[i][0].size();
			s[i][0]=' '+s[i][0],s[i][1]=' '+s[i][1];
			for(int j=1;j<=len[i];j++)
				h[i][0]=h[i][0]*13331+(s[i][0][j]-'a'+1),
				h[i][1]=h[i][1]*13331+(s[i][1][j]-'a'+1);
		}
		p[0]=1;
		for(int i=1;i<=ma;i++)p[i]=p[i-1]*13331;
	//	for(int i=1;i<=n;i++){
	//		cout<<s[i][0]<<' '<<s[i][1]<<endl;
	//	}
		for(int ttt=1;ttt<=T;ttt++){
			t1=tx[ttt][0],t2=tx[ttt][1];aans=0;
			if(t1.size()!=t2.size()){cout<<0<<endl;continue;
			}
			tn=t1.size();
			t1=' '+t1,t2=' '+t2;
			for(int i=1;i<=tn;i++)t[i]=t[i-1]*13331+(t1[i]-'a'+1);
			tt=0;
			for(int i=1;i<=tn;i++)tt=tt*13331+(t2[i]-'a'+1);
			sovle();
		}
	}
}
namespace sub2{
	ll a[N][2],b[N];
	vector<ll > qz[N];
	const ll ppy=2e5+2;
	bool cmp(ll x,ll y){
		return a[x][1]<a[y][1];
	}
	void sovle(){
		for(int i=1;i<=n;i++){
			len[i]=s[i][0].size();
			s[i][0]=' '+s[i][0],s[i][1]=' '+s[i][1];
			for(int j=1;j<=len[i];j++)if(s[i][0][j]=='b')a[i][0]=j;
			for(int j=1;j<=len[i];j++)if(s[i][1][j]=='b')a[i][1]=j;
			b[i]=a[i][1]-a[i][0];
			qz[b[i]+ppy].pb(i );
		}
		for(int i=-2e5-1;i<=2e5+1;i++)sort(qz[i+ppy].begin(),qz[i+ppy].end(),cmp);
		for(int ttt=1;ttt<=T;ttt++){
			t1=tx[ttt][0],t2=tx[ttt][1];aans=0;
			if(t1.size()!=t2.size()){cout<<0<<endl;continue;
			}
			tn=t1.size();
			t1=' '+t1,t2=' '+t2;
			ll py=0,ks;
			for(int j=1;j<=tn;j++)if(t1[j]=='b')py=ks=j;
			for(int j=1;j<=tn;j++)if(t2[j]=='b')py=j-py;
			auto wz=upper_bound(qz[py+ppy].begin(),qz[py+ppy].end(),ks);wz--;
			ll ans=wz-qz[py+ppy].begin()+1;
			cout<<ans<<endl;
		}
	}
}
namespace sub3{
	ll a[N][2],b[N];
	void sovle(){
		for(int i=1;i<=n;i++){
			len[i]=s[i][0].size();
			s[i][0]=' '+s[i][0],s[i][1]=' '+s[i][1];
			for(int j=1;j<=len[i];j++)if(s[i][0][j]=='b')a[i][0]=j;
			for(int j=1;j<=len[i];j++)if(s[i][1][j]=='b')a[i][1]=j;
			b[i]=a[i][1]-a[i][0];
		}
		for(int ttt=1;ttt<=T;ttt++){
			t1=tx[ttt][0],t2=tx[ttt][1];aans=0;
			if(t1.size()!=t2.size()){cout<<0<<endl;continue;
			}
			tn=t1.size();
			t1=' '+t1,t2=' '+t2;
			ll py=0,ks=0;
			for(int j=1;j<=tn;j++)if(t1[j]=='b')py=ks=j;
			for(int j=1;j<=tn;j++)if(t2[j]=='b')py=j-py;
			ll ans=0;
			for(int i=1;i<=n;i++)if(a[i][0]<=ks&&py==b[i])ans++;
			cout<<ans<<endl;
		}
	}
}
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=T;i++)cin>>tx[i][0]>>tx[i][1];
	ll bopd=0;
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(char j:s[i][0]){
			if(j!='a'&&j!='b'){bopd=1;break;
			}
			if(j=='b'){sum++;
			}
		}
		if(sum!=1){bopd=1;
		}
		sum=0;
		for(char j:s[i][1]){
			if(j!='a'&&j!='b'){bopd=1;break;
			}
			if(j=='b'){sum++;
			}
		}
		if(sum!=1){bopd=1;
		}
	}
	for(int i=1;i<=T;i++){
		ll sum=0;
		for(char j:tx[i][0]){
			if(j!='a'&&j!='b'){bopd=1;break;
			}
			if(j=='b'){sum++;
			}
		}
		if(sum!=1){bopd=1;
		}
		sum=0;
		for(char j:tx[i][1]){
			if(j!='a'&&j!='b'){bopd=1;break;
			}
			if(j=='b'){sum++;
			}
		}
		if(sum!=1){bopd=1;
		}
	}
	if(!bopd){
	if(n<=2000){sub3::sovle();return 0;
	}
	sub2::sovle();return 0;
	}
	if(n<=2000){sub1::ssovle();return 0;
	}
	return 0;
}

