#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,base=233,mod=19491001;
int n,q;
string s[N][5];
vector<int>h1[N],h2[N];
int pw[N<<5];
int st[N],en[N];
int hh1[N],hh2[N];
int Len[N];
string qs[5];
bool ql1(int l,int r,int j){
	if((hh1[r]-pw[r-l+1]*hh1[l-1]%mod+mod)%mod==h1[j][Len[j]]){
		return 1;
	}
	return 0;
}
bool ql2(int l,int r,int j){
	if((hh2[r]-pw[r-l+1]*hh2[l-1]%mod+mod)%mod==h2[j][Len[j]]){
		return 1;
	}
	return 0;
}
signed main(){
//	system("fc replace.out replace3.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=5e6;i++){
		pw[i]=pw[i-1]*base%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int len=s[i][1].size();
		h1[i].resize(len+5);
		h2[i].resize(len+5);
		s[i][1]=" "+s[i][1];
		s[i][2]=" "+s[i][2];
		for(int j=1;j<=len;j++){
			if(s[i][1][j]!=s[i][2][j]){
				st[i]=j;
				break;
			}
		}
		for(int j=len;j>=1;j--){
			if(s[i][1][j]!=s[i][2][j]){
				en[i]=j;
				break;
			}
		}
		h1[i][0]=h2[i][0]=0;
		for(int j=1;j<=len;j++){
			h1[i][j]=(h1[i][j-1]*base%mod+s[i][1][j])%mod;
			h2[i][j]=(h2[i][j-1]*base%mod+s[i][2][j])%mod;
		}
		Len[i]=len;
//		mp[mk(ql1(j,st[j],en[j]),ql2(j,st[j],en[j]))].push_back(i);
	}
//	for(int i=1;i<=n;i++){
//		cout<<h1[i][Len[i]]<<' '<<h2[i][Len[i]]<<endl;
//	}
	for(int i=1;i<=q;i++){
		cin>>qs[1]>>qs[2];
		int len=qs[1].size();
		if(len!=qs[2].size()){
			cout<<0<<'\n';
			continue;
		}
		qs[1]=" "+qs[1];
		qs[2]=" "+qs[2];
		int qst,qen;
		for(int j=1;j<=len;j++){
			if(qs[1][j]!=qs[2][j]){
				qst=j;
				break;
			}
		}
		for(int j=len;j>=1;j--){
			if(qs[1][j]!=qs[2][j]){
				qen=j;
				break;
			}
		}
		int ans=0;
		for(int j=1;j<=len;j++){
			hh1[j]=(hh1[j-1]*base%mod+qs[1][j])%mod;
			hh2[j]=(hh2[j-1]*base%mod+qs[2][j])%mod;
		}
		for(int j=1;j<=n;j++){
			if(qst<st[j]){
				continue;
			}
			if(qen+Len[j]-en[j]>len){
				continue;
			}
			if(Len[j]>len){
				continue;
			}
			if(qen-qst!=en[j]-st[j]){
				continue;
			}
			if(ql1(qst-st[j]+1,qen+Len[j]-en[j],j)&&ql2(qst-st[j]+1,qen+Len[j]-en[j],j)){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
