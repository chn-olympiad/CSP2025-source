#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int n,q;
string s[5000005][2]; 
string t1,t2;
ull hs[5000005],hs1[5000005],hs2[5000005],hs3[5000005];
ull pw[5000005],pw1[5000005];
int mod1=1e9+7,mod2=1e9+9;
int bas1=131,bas2=97;
unordered_map<ull,int>qt;
struct node{
	ull l,r,h1,h2,b1,b2,frm;
};
vector<node>qh[200005];
int cnt=0;
pair<int,int> sbstr(int l,int r){
	if(l==0){
		return {hs[r],hs1[r]};
	}
	return {(hs[r]-hs[l-1]*pw[r-l]%mod1+mod1)%mod1,(hs1[r]-hs1[l-1]*pw1[r-l]%mod2+mod2)%mod2};
}
pair<int,int> sbstr1(int l,int r){
	if(l==0){
		return {hs2[r],hs3[r]};
	}
	return {(hs2[r]-hs2[l-1]*pw[r-l]%mod1+mod1)%mod1,(hs3[r]-hs3[l-1]*pw1[r-l]%mod2+mod2)%mod2};
}
/*
int mian()
feropen
frepoen
freopen("replace.in","r",stdout);
freopen("replace4.out","w",stdout);
y1
pw[-114514]
反正都寄了，我想上迷惑行为 
*/ 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	pw[0]=1;
	pw1[0]=1; 
	for(int i=1;i<=5000000;i++){
		pw[i]=pw[i-1]*bas1;
		pw[i]%=mod1;
		pw1[i]=pw1[i-1]*bas2;
		pw1[i]%=mod2;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		int l=-1,r=-1,m=s[i][0].size();
		for(int j=0;j<m;j++){
			if(s[i][0][j]!=s[i][1][j]){
				r=j;
				if(l==-1){
					l=j;
				}
			}
		}
		int a1=0,a2=0;
		for(int j=l;j<=r;j++){
			a1=a1*bas1+s[i][0][j]-'a';
			a1%=mod1;
		}
		for(int j=l;j<=r;j++){
			a2=a2*bas2+s[i][0][j]-'a';
			a2%=mod2;
		}
		for(int j=l;j<=r;j++){
			a1=a1*bas1+s[i][1][j]-'a';
			a1%=mod1;
		}
		for(int j=l;j<=r;j++){
			a2=a2*bas2+s[i][1][j]-'a';
			a2%=mod2;
		}
		ull s1=0,s2=0,b1=0,b2=0;
		for(int j=0;j<m;j++){
			s1=s1*bas1+s[i][0][j]-'a';
			s1%=mod1;
		}
		for(int j=0;j<m;j++){
			s2=s2*bas2+s[i][0][j]-'a';
			s2%=mod2;
		}
		for(int j=0;j<m;j++){
			b1=b1*bas1+s[i][1][j]-'a';
			b1%=mod1;
		}
		for(int j=0;j<m;j++){
			b2=b2*bas2+s[i][1][j]-'a';
			b2%=mod2;
		}
		ull at=a1;
		at=at*(1000000009ull);
		at+=a2;
		if(qt[at]==0){
			qt[at]=++cnt;
		}
		qh[qt[at]].push_back({l,m-1-r,s1,s2,b1,b2,i});
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int l=-1,r=-1,m=t1.size();
		for(int j=0;j<m;j++){
			if(t1[j]!=t2[j]){
				r=j;
				if(l==-1){
					l=j;
				}
			}
		}
		int a1=0,a2=0;
		for(int j=l;j<=r;j++){
			a1=a1*bas1+t1[j]-'a';
			a1%=mod1;
		}
		for(int j=l;j<=r;j++){
			a2=a2*bas2+t1[j]-'a';
			a2%=mod2;
		}
		for(int j=l;j<=r;j++){
			a1=a1*bas1+t2[j]-'a';
			a1%=mod1;
		}
		for(int j=l;j<=r;j++){
			a2=a2*bas2+t2[j]-'a';
			a2%=mod2;
		}
		
		for(int j=0;j<m;j++){
			if(j==0){
				hs[j]=t1[j]-'a';
			}
			else{
				hs[j]=hs[j-1]*bas1+t1[j]-'a';
				hs[j]%=mod1;
			}
		}
		for(int j=0;j<m;j++){
			if(j==0){
				hs1[j]=t1[j]-'a';
			}
			else{
				hs1[j]=hs1[j-1]*bas2+t1[j]-'a';
				hs1[j]%=mod2;
			}
		}
		for(int j=0;j<m;j++){
			if(j==0){
				hs2[j]=t2[j]-'a';
			}
			else{
				hs2[j]=hs2[j-1]*bas1+t2[j]-'a';
				hs2[j]%=mod1;
			}
		}
		for(int j=0;j<m;j++){
			if(j==0){
				hs3[j]=t2[j]-'a';
			}
			else{
				hs3[j]=hs3[j-1]*bas2+t2[j]-'a';
				hs3[j]%=mod2;
			}
		}
		ull at=a1;
		at=at*(1000000009ull);
		at+=a2;
		if(qt[at]==0){
			cout<<0<<endl;
			continue;
		}
		int u=qt[at];
		int ans=0,d=qh[u].size();
		for(int j=0;j<d;j++){
			node v=qh[u][j];
			int nl=l-v.l,nr=r+v.r,flg=0;
			if(nl<0||nr>=m){
				continue;
			}
			for(int j=nl;j<=nr;j++){
				if(t1[j]!=s[v.frm][0][j-nl]||t2[j]!=s[v.frm][1][j-nl]){
					flg=1;
					break;
				}
			}
			ans+=1-flg; 
		}
		cout<<ans<<endl;
	}
	return 0;
}