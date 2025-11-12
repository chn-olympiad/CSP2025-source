#include<bits/stdc++.h>
#define int long long

const int N=1145;

int mod1=998244353,mod2=1e9+7;
int base1=131,base2=1331;
int n,q;
//std::string s[N][3];
int ksm(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1)ans=(ans*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return ans;
}
int h1[N][3][2025],h2[N][3][2025];
void cur_hash1(int num,int x,int l,int r){
	return h1[num][x][r]+mod1-h1[num][x][l-1]*ksm(base1,r-l+1,mod1);
}
void cur_hash2(int num,int x,int l,int r){
	return h2[num][x][r]+mod2-h2[num][x][l-1]*ksm(base2,r-l+1,mod2);
}
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*f;
}
void solve(){
	while(q--){
		
	}
}
signed main(){
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	
	n=read(),q=read();
	for(int i=1;i<=n;++i){
		string s1=read(),s2=read();
		for(int j=1;j<=s1.length();++j){
			h1[i][1][j]=(h1[i][1][j-1]*base1+s[j-1])%mod1;
		}
		for(int j=1;j<=s1.length();++j){
			h2[i][1][j]=(h2[i][1][j-1]*base2+s[j-1])%mod2;
		}
		for(int j=1;j<=s2.length();++j){
			h1[i][2][j]=(h1[i][2][j-1]*base1+s[j-1])%mod1;
		}
		for(int j=1;j<=s2.length();++j){
			h2[i][2][j]=(h2[i][2][j-1]*base2+s[j-1])%mod2;
		}
	}
	solve();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
