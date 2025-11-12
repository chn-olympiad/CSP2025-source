#include <bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
const int L=5e6+3,SZ=26;
int crt=1,q[L],h,t,n,Q,son[L][SZ+1],len[L],fail[L],to[L][25],w[L];
string str1,str2;
void ins(){
	int u=1;
	for(int i=1,x;i<=str1.size()*2;i++){
		if((i&1)) x=str1[(i+1)/2-1]-'a';
		else x=str2[i/2-1]-'a';
		if(!son[u][x]) len[son[u][x]=++crt]=i/2;
		u=son[u][x];
	}w[u]++;
}void build(){
	h=0,t=0;
	int u;
	for(int i=0;i<SZ;i++){
		if(son[1][i]) q[t++]=son[1][i],fail[son[1][i]]=1;
		else son[1][i]=1;
	}while(h<t){
		u=q[h++];
		to[u][0]=fail[u];
		for(int j=1;j<=23;j++)
			to[u][j]=to[to[u][j-1]][j-1];
		w[u]+=w[fail[u]];
		for(int i=0;i<SZ;i++){
			if(son[u][i]) q[t++]=son[u][i],fail[son[u][i]]=son[fail[u]][i];
			else son[u][i]=son[fail[u]][i];
		}
	}
}int solve(){
	int u=1,n=str1.size(),l=n+1,r=0;
	int ans=0;
	if(n!=str2.size()) return 0;
	for(int i=1,x;i<=n;i++)
		if(str1[i-1]!=str2[i-1]){
			l=i;
			break;
		}
	for(int i=n;i>0;i--)
		if(str1[i-1]!=str2[i-1]){
			r=i;
			break;
		}
	for(int i=1,now,x,lln;i<=2*n;i++){
		if((i&1)) x=str1[(i+1)/2-1]-'a',u=son[u][x];
		else{
			x=str2[i/2-1]-'a';
			u=son[u][x];
			if(i/2>=r){
				now=u,lln=i/2-l+1;
				if(len[u]<lln) continue;
				for(int j=23;j>=0;j--)
					if(len[to[now][j]]>=lln) now=to[now][j];
				ans+=w[u]-w[fail[now]];
			}
		}
	}
//	cout<<'\n';
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
//	freopen("zj.out","w",stdout);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>str1>>str2;
		ins();
	}
	/*
	for(int i=1;i<=crt;i++){
		cout<<i<<":\n";
		for(int j=0;j<SZ;j++)
			if(son[i][j]>1) cout<<(char)(j+'a')<<" "<<son[i][j]<<"\n";
	}*/
	build();
	/*
	for(int i=1;i<=crt;i++) cout<<fail[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=crt;i++){
		cout<<i<<":\n";
		for(int j=0;j<3;j++) cout<<to[i][j]<<" ";
		cout<<'\n';
	}*/
	while(Q--){
		cin>>str1>>str2;
		cout<<solve()<<"\n";
	}
	return 0;
}
/*
8 10
bba aca
abc bcb
ba aa
bbaca bcabb
ab aa
baa bbb
bb bb
ba aa
aa bc
abaca aaccb
caacc bbcbc
ba aa
aa ca
caabb bbbbb
ba bb
abbbc bccca
bcc bbc
bcca caac

0
0
0
2
0
0
0
0
0
0

*/