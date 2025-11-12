//李心恒 SN-S00339 西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
const int M=5e6+10;
const int mod=999999937;
const int P=1437;
int power(int x,int p){
	int ret=1;
	while(p){
		if(p&1) ret=ret*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return ret;
}
int PI[M],fPI[M];
int n,Q;
string s[N][2];
int L[N],R[N];
int hsh[N][2];
map<pair<pair<int ,int > ,pair<int ,int > > ,int >vis,f; 
string t_0,t_1;
int hsht0[M],hsht1[M];
void init(){
	hsht0[0]=t_0[0];
	for(int i=1;i<t_0.size();i++) hsht0[i]=hsht0[i-1]*P%mod;
	hsht1[0]=t_1[0];
	for(int i=1;i<t_1.size();i++) hsht1[i]=hsht1[i-1]*P%mod;
}
void INIT(){
	PI[0]=1;
	for(int i=1;i<=M-5;i++) PI[i]=PI[i-1]*P%mod;
	fPI[M-5]=power(PI[M-5],mod-2);
	for(int i=M-6;i>=0;i--) fPI[i]=fPI[i+1]*P%mod;
}
void Hsh(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!=s[i][1][j]){
				if(L[i]==0) L[i]=j;
				R[i]=j;
			}
		}
		for(int j=L[i],p=0;j<=R[i];j++,p++){
			hsh[i][0]=hsh[i][0]*PI[p]%mod;
			hsh[i][0]=(hsh[i][0]+(s[i][0][j]-'a'))%mod;
			hsh[i][1]=hsh[i][1]*PI[p]%mod;
			hsh[i][1]=(hsh[i][1]+(s[i][1][j]-'a'))%mod;
		}
		int hshzuo=0;
		for(int j=0,p=0;j<L[i];j++,p++){
			hshzuo=hshzuo*PI[p]%mod;
			hshzuo=(hshzuo+(s[i][0][j]-'a'))%mod;
		}
		int hshyou=0;
		for(int j=R[i]+1,p=0;j<s[i][0].size();j++,p++){
			hshyou=hshyou*PI[p]%mod;
			hshyou=(hshyou+(s[i][0][j]-'a'))%mod;
		}
		vis[{{hshzuo,hshyou},{hsh[i][0],hsh[i][1]}}]++;
	}
	
}
int query0(int l,int r){
	if(l>r) return 0;
	if(l==0) return hsht0[r];
	return (hsht0[r]-hsht0[l-1]+mod)%mod*fPI[l]%mod;
}
int query1(int l,int r){
	if(l>r) return 0;
	if(l==0) return hsht0[r];
	return (hsht1[r]-hsht1[l-1]+mod)%mod*fPI[l]%mod;
}
int solve(int L,int R,int l,int r){
	if(L>l) return 0;
	if(r>R) return 0;
	int hshzuo=query0(L,l-1);
	int hshyou=query0(R+1,r);
	int hsh0=query0(L,R);
	int hsh1=query1(L,R);
	if(f[{{hshzuo,hshyou},{hsh0,hsh1}}]!=0) return f[{{hshzuo,hshyou},{hsh0,hsh1}}];
	f[{{hshzuo,hshyou},{hsh0,hsh1}}]=solve(L,R-1,l,r)+solve(L+1,R,l,r)+vis[{{hshzuo,hshyou},{hsh0,hsh1}}];
	return f[{{hshzuo,hshyou},{hsh0,hsh1}}];
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>Q;
	INIT();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	Hsh();
	while(Q--){
		cin>>t_0;
		cin>>t_1;
		if(t_0.size()!=t_1.size()){
			cout<<0<<'\n';
//			cout<<"D";
			continue;
		}
		int l=0,r=0;
		for(int j=0;j<t_0.size();j++){
			if(t_0[j]!=t_1[j]){
				if(l==0) l=j;
				r=j;
			}
		}
		init();
		cout<<solve(0,t_0.size()-1,l,r)<<'\n';
	}
	return 0;
}

