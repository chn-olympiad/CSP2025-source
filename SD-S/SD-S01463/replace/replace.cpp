#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e5+5,inf=1e18;
int n,q;
vector<int>v[2][N],vi[2];
int len[N];
char c[N*25];
int bs1=73,bs2=39,mod1=998244353,mod2=1e9+7;
map<pii,int>mp;
int cnt;
pii hs[N],al[N];
int la[N];
vector<int>p[N];
pii pre[N*25];
int bs1_[N*25],bs2_[N*25];
void sl(){
	cin>>n>>q;
	bs1_[0]=bs2_[0]=1;
	for(int i=1;i<=5e6;i++){
		bs1_[i]=bs1_[i-1]*bs1%mod1;
		bs2_[i]=bs2_[i-1]*bs2%mod2;
	}
	for(int i=1;i<=n;i++){
		cin>>c+1;
		int m=strlen(c+1);
		v[0][i].resize(m+1);
		for(int j=1;j<=m;j++){
			v[0][i][j]=c[j]-'a';
		}
		cin>>c+1;
		m=strlen(c+1);
		v[1][i].resize(m+1);
		len[i]=m;
		for(int j=1;j<=m;j++){
			v[1][i][j]=c[j]-'a';
		}
		int flag=0;
		pii x;
		x.fi=x.se=0;
		for(int j=1;j<=m;j++){
//			cout<<v[0][i][j]<<" "<<v[1][i][j]<<"\n";
			if(v[0][i][j]!=v[1][i][j]){
				la[i]=j;
			}
		}
		if(!la[i])continue;
		for(int j=1;j<=la[i];j++){
			if(v[0][i][j]!=v[1][i][j]){
				flag=1;
			}
			if(flag){
//				cout<<v[0][i][j]<<" ";
				x.fi=x.fi*bs1%mod1+v[0][i][j];x.fi%=mod1;
				x.fi=x.fi*bs1%mod1+v[1][i][j];x.fi%=mod1;
				x.se=x.se*bs2%mod2+v[0][i][j];x.se%=mod2;
				x.se=x.se*bs2%mod2+v[1][i][j];x.se%=mod2;
				
				
			}
		}
		hs[i]=x;
		if(!mp[x]){
			mp[x]=++cnt;
		}
//		cout<<"???? "<<mp[x]<<"\n";
		p[mp[x]].push_back(i);
		x.fi=x.se=0;
		for(int j=1;j<=m;j++){
			x.fi=x.fi*bs1%mod1+v[0][i][j];
			x.se=x.se*bs2%mod2+v[0][i][j];
			x.fi%=mod1;
			x.se%=mod2;
		}
		al[i]=x;
	}
	for(int i=1;i<=q;i++){
		cin>>c+1;
		int lenn=strlen(c+1);
		vi[0].resize(lenn+1);
		for(int j=1;j<=lenn;j++){
			vi[0][j]=c[j]-'a';
		}
		cin>>c+1;
		int lop=strlen(c+1);
		if(lop!=lenn){
			cout<<"0\n";
			continue;
		}
		vi[1].resize(lenn+1);
		for(int j=1;j<=lenn;j++){
			vi[1][j]=c[j]-'a';
		}
		int lst=0,flag=0;
		pii x;
		x.fi=x.se=0;
		for(int j=1;j<=lenn;j++){
			if(vi[0][j]!=vi[1][j]){
				lst=j;
			}
		}
		for(int j=1;j<=lst;j++){
			if(vi[0][j]!=vi[1][j]){
				flag=1;
			}
			if(flag){
				x.fi=x.fi*bs1%mod1+vi[0][j];x.fi%=mod1;
				x.fi=x.fi*bs1%mod1+vi[1][j];x.fi%=mod1;
				x.se=x.se*bs2%mod2+vi[0][j];x.se%=mod2;
				x.se=x.se*bs2%mod2+vi[1][j];x.se%=mod2;
			}
		}
		for(int j=1;j<=lenn;j++){
			pre[j].fi=pre[j-1].fi*bs1%mod1+vi[0][j];
			pre[j].fi%=mod1;
			pre[j].se=pre[j-1].se*bs2%mod2+vi[0][j];
			pre[j].se%=mod2;
		}
		int pl=mp[x];
//		cout<<"???? "<<mp[x]<<"\n";
		int ans=0;
		for(int j=0;j<p[pl].size();j++){
//			cout<<"?";
			int ii=p[pl][j];
			int l=lst-la[ii]+1,r=len[ii]+lst-la[ii];
//			cout<<l<<" "<<r<<"\n";
			if(l<1||r>lenn)continue;
			if((pre[r].fi-pre[l-1].fi*bs1_[r-l+1]%mod1+mod1)%mod1==al[ii].fi){
				if((pre[r].se-pre[l-1].se*bs2_[r-l+1]%mod2+mod2)%mod2==al[ii].se){
//					cout<<l<<" "<<r<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int tt=1;
//	cin>>tt;
	while(tt--)sl();
	return 0;
}

