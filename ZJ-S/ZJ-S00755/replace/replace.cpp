#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q;
string s[N][3];
int len[N];
string t[N][3];
vector<int> nxt[N][3];
int ok[N],ok2[N];
int pos1[N][3],pos2[N][3];
bool check(){
	int cnt1,cnt2;
	for(int i=1;i<=n;i++){
		cnt1=cnt2=0;
		for(int j=0;j<len[i];j++){
			if(s[i][1][j]!='a'&&s[i][1][j]!='b')return false;
			if(s[i][2][j]!='a'&&s[i][2][j]!='b')return false;
			cnt1+=(s[i][1][j]=='b');cnt2+=(s[i][2][j]=='b');
			if(s[i][1][j]=='b')pos1[i][1]=j;
			if(s[i][2][j]=='b')pos1[i][2]=j;
		}
		if(cnt1!=1||cnt2!=1)return false;
	}
	for(int i=1;i<=q;i++){
		if(t[i][1].size()^t[i][2].size())continue;
		cnt1=cnt2=0;
		for(int j=0,k=t[i][1].size();j<k;j++){
			if(t[i][1][j]!='a'&&t[i][1][j]!='b')return false;
			if(t[i][2][j]!='a'&&t[i][2][j]!='b')return false;
			cnt1+=(t[i][1][j]=='b');cnt2+=(t[i][2][j]=='b');	
			if(t[i][1][j]=='b')pos2[i][1]=j;
			if(t[i][2][j]=='b')pos2[i][2]=j;
		}
		if(cnt1!=1||cnt2!=1)return false;		
	}
	return true;
}
const int base=137,mod=998244353;
int h[N][3];
int H[N],L[N];
map<pair<int,int>,int> mp;
int qpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=(ll)ret*a%mod;
		a=(ll)a*a%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		len[i]=s[i][1].size();
		int j1=0,j2=0;
		nxt[i][1].resize(len[i]);nxt[i][2].resize(len[i]);
		for(int k=1;k<len[i];k++){
			while(j1&&s[i][1][j1]!=s[i][1][k])j1=nxt[i][1][j1-1];
			if(s[i][1][j1]==s[i][1][k])j1++;
			nxt[i][1][k]=j1;
			while(j2&&s[i][2][j2]!=s[i][2][k])j2=nxt[i][2][j2-1];
			if(s[i][2][j2]==s[i][2][k])j2++;
			nxt[i][2][k]=j2;
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	if(q==1&&check()){
		if(t[1][1].size()!=t[1][2].size()){
			cout<<"0\n";return 0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(pos1[i][1]-pos2[1][1]==pos1[i][2]-pos2[1][2]&&pos2[1][1]>=pos1[i][1]&&pos2[1][1]+len[i]-pos1[i][1]-1<t[1][1].size())ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}else{
		for(int i=1;i<=q;i++){
			if(t[i][1].size()!=t[i][2].size())printf("0\n");
			else{
				int u,v;
				ll ans=0;
				for(int j=1;j<=n;j++){
					u=v=0;
					if(t[i][1].size()<len[i])continue;
					ok[0]=(t[i][1][0]==t[i][2][0]);
					for(int k=1;k<t[i][1].size();k++)ok[k]=(ok[k-1]&&t[i][1][k]==t[i][2][k]);
					ok2[t[i][1].size()-1]=(t[i][1][t[i][1].size()-1]==t[i][2][t[i][1].size()-1]);
					for(int k=t[i][1].size()-2;k>=0;k--)ok2[k]=(ok2[k+1]&&t[i][1][k]==t[i][2][k]);
					for(int k=0;k<t[i][1].size();k++){
						while(u&&s[j][1][u]!=t[i][1][k])u=nxt[j][1][u-1];
						if(s[j][1][u]==t[i][1][k])u++;
						while(v&&s[j][2][v]!=t[i][2][k])v=nxt[j][2][v-1];
						if(s[j][2][v]==t[i][2][k])v++;
						if(u==len[j]&&v==len[j]&&(k==len[j]-1||ok[k-len[j]])&&(k==t[i][1].size()-1||ok2[k+1]))ans++;
						if(u==len[j])u=nxt[j][1][u-1];
						if(v==len[j])v=nxt[j][2][v-1];
					}
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex


*/
