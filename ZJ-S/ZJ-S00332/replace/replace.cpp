#include<bits/stdc++.h>
using namespace std;
#define int long long
 const int N=1000009961,bse=29;
 int n,q;
 int bs[5000010];
 int sz[200010],hsh[2][200010];
 char c1[5000010],c2[5000010];
 vector<int>hh[2];
int gethh(int l,int r,int fg){return (hh[fg][r]-hh[fg][l-1]*bs[r-l+1]%N+N)%N;}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	bs[0]=1;
	for(int i=1;i<=5000000;i++)bs[i]=bs[i-1]*bse%N;
	for(int i=1;i<=n;i++){
		cin>>(c1+1)>>(c2+1);
		sz[i]=strlen(c1+1);
		for(int j=1;j<=sz[i];j++)hsh[0][i]=(hsh[0][i]*bse+(c1[j]-'a'))%N;
		for(int j=1;j<=sz[i];j++)hsh[1][i]=(hsh[1][i]*bse+(c2[j]-'a'))%N;
	}
	while(q--){
		cin>>(c1+1)>>(c2+1);
		int m=strlen(c1+1);
		hh[0].clear();
		hh[1].clear();
		hh[0].push_back(0);
		hh[1].push_back(0);
		for(int j=1,x;j<=m;j++){
			x=(hh[0][j-1]*bse+(c1[j]-'a'))%N;
			hh[0].push_back(x);
		}
		for(int j=1,x;j<=m;j++){
			x=(hh[1][j-1]*bse+(c2[j]-'a'))%N;
			hh[1].push_back(x);
		}
		int as=0;
		for(int i=1;i<=n;i++){
			for(int l=1,r=sz[i];r<=m;l++,r++){
				if(c1[l-1]!=c2[l-1])break;
				if(gethh(r+1,m,0)!=gethh(r+1,m,1))continue;
				if(gethh(l,r,0)==hsh[0][i]&&gethh(l,r,1)==hsh[1][i]){
					as++;
					break;
				}
			}
		}
		cout<<as<<"\n";
	}
	return 0;
}
