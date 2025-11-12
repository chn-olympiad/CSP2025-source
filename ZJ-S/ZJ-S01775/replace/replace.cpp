#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=1e17;
constexpr int B=131,mod=998244353;
int qpow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=x*x%mod)
		if(y&1) res=res*x%mod;
	return res;
}
int pw[5000005];
int n,q;
string s[200005][3];
string t[200005][3];
int poss[200005][3];
int post[200005][3];
int dis[200005];
int pos[200005][3];
int hsh[200005][3];
map<int,int> mp;
vector<int> len[500005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=5000000;i++)
		pw[i]=pw[i-1]*B%mod;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int numa=0,numb=0;
		int num=0,bas=1;
		for(int j=0;j<s[i][1].size();j++){
			num=(num+pw[j]*(s[i][1][j]-'a'+1)%mod)%mod;
			if(s[i][1][j]=='a') numa++;
			else if(s[i][1][j]=='b') numb++,poss[i][1]=j;
			else numa=-inf;
		}
		if(!(numb==1&&numa>=0)) flag=0;
		hsh[i][1]=num;
		mp[num]=i;
		num=0,bas=1;
		numa=0,numb=0;
		for(int j=0;j<s[i][2].size();j++){
			num=(num+pw[j]*(s[i][2][j]-'a'+1)%mod)%mod;
			if(s[i][2][j]=='a') numa++;
			else if(s[i][2][j]=='b') numb++,poss[i][2]=j;
			else numa=-inf;
		}
		if(!(numb==1&&numa>=0)) flag=0;
		hsh[i][2]=num;
	}
//	for(int i=1;i<=n;i++)
//		cout<<hsh[i][1]<<' '<<hsh[i][2]<<'\n';
//	cout<<'\n';
	for(int o=1;o<=q;o++){
		cin>>t[o][1]>>t[o][2];
		int numa=0,numb=0;
		for(int j=0;j<t[o][1].size();j++)
			if(t[o][1][j]=='a') numa++;
			else if(t[o][1][j]=='b') numb++,post[o][1]=j;
			else numa=-inf;
		if(!(numb==1&&numa>=0)) flag=0;
		numa=0,numb=0;
		for(int j=0;j<t[o][2].size();j++)
			if(t[o][2][j]=='a') numa++;
			else if(t[o][2][j]=='b') numb++,post[o][2]=j;
			else numa=-inf;
		if(!(numb==1&&numa>=0)) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			dis[i]=poss[i][1]-poss[i][2]+2e5;
			len[dis[i]].push_back(i);
		}
		for(int o=1;o<=q;o++){
			int ans=0;
			int num=post[o][1]-post[o][2]+2e5;
			for(int x:len[num]){
				if(poss[x][1]<=post[o][1]&&poss[x][2]<=post[o][2]&&
				s[x][1].size()-poss[x][1]<=t[o][1].size()-post[o][1]&&
				s[x][2].size()-poss[x][2]<=t[o][2].size()-post[o][2])
					ans++;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int o=1;o<=q;o++){
		int ans=0;
		if(t[o][1].size()!=t[o][2].size()){
			cout<<0<<'\n';
			continue;
		}
		bool flag1=1,flag2=0;
		for(int j=0;j<t[o][1].size();j++){
			if(t[o][1][j]!=t[o][2][j]&&flag1)
				pos[o][1]=j,flag1=0,flag2=1;
			if(t[o][1][j]==t[o][2][j]&&flag2)
				pos[o][2]=j-1,flag2=0;
		}
		if(flag2) pos[o][2]=t[o][1].size()-1;
		for(int i=pos[o][1];i>=max(pos[o][1]-2005ll,0ll);i--){
			int hsh1=0,hsh2=0;
			string now1,now2;
			for(int j=i;j<=pos[o][2];j++){
				now1+=t[o][1][j];now2+=t[o][2][j];
				hsh1=(hsh1+(t[o][1][j]-'a'+1)*pw[j-i]%mod)%mod;
				hsh2=(hsh2+(t[o][2][j]-'a'+1)*pw[j-i]%mod)%mod;
			}
			if(mp[hsh1]&&hsh[mp[hsh1]][2]==hsh2) ans++;
//			cout<<hsh1<<' '<<hsh2<<'\n';
			for(int j=pos[o][2]+1;j<min(pos[o][2]+2005ll,(int)t[o][1].size());j++){
				hsh1=(hsh1+(t[o][1][j]-'a'+1)*pw[j-i]%mod)%mod;
				hsh2=(hsh2+(t[o][2][j]-'a'+1)*pw[j-i]%mod)%mod;
				if(mp[hsh1]&&hsh[mp[hsh1]][2]==hsh2) ans++;
//				cout<<hsh1<<' '<<hsh2<<'\n';
			}
		}
//		cout<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
