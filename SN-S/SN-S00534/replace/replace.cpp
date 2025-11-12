#include<bits/stdc++.h>
#define ll long long
#define N 1005
#define L 20005
#define P 13331
#define ull unsigned long long
using namespace std;

int n,m;
string s[2][N];
int ld[N],rd[N],dis[N];
ull p[L],hs[2][N][L],h[2][L];

ull gethash(int l,int r,ull *h){
	return h[r]-h[l-1]*p[r-l+1];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=20000;i++)p[i]=p[i-1]*P;
	for(int i=1;i<=n;i++){
		cin>>s[0][i]>>s[1][i];
		ld[i]=s[0][i].size()+1;
		for(int j=0;j<(int)s[0][i].size();j++){
			if(s[0][i][j]!=s[1][i][j])ld[i]=min(ld[i],j),rd[i]=max(rd[i],j);
		}
		for(int j=0;j<(int)s[0][i].size();j++){
			hs[0][i][j+1]=hs[0][i][j]*P+s[0][i][j]-'a';
			hs[1][i][j+1]=hs[1][i][j]*P+s[1][i][j]-'a';
		}
	}
	
	for(int i=1;i<=m;i++){
		int cnt=0;
		string t[2];
		cin>>t[0]>>t[1];
		int l=t[0].size()+1,r=0;
		if(t[0].size()!=t[1].size()){
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<(int)t[0].size();j++){
			if(t[0][j]!=t[1][j]){
				l=min(l,j),r=max(r,j);
			}
			h[0][j+1]=h[0][j]*P+t[0][j]-'a';
			h[1][j+1]=h[1][j]*P+t[1][j]-'a';
		}
		for(int j=1;j<=n;j++){
			if(!rd[j])continue;
			if(rd[j]-ld[j]==r-l){
				if(gethash(ld[j]+1,rd[j]+1,hs[0][j])==gethash(l+1,r+1,h[0])&&
				   gethash(ld[j]+1,rd[j]+1,hs[1][j])==gethash(l+1,r+1,h[1])){
					++cnt;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
