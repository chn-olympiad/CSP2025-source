#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=1e5+10;
string str;
int p[N],n,m,anss;
int c[N];
int main(){	
	freopen("employ.in","r",stdin); 	
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=n;++i)p[i]=i;
	do{
		int cnt=0,ans=0;
		for(int i=0;i<str.size();++i){
			if(str[i]=='0'){
				cnt++;
			} 
			else{
				if(c[p[i+1]]<=cnt){
					cnt++;
				}
				else{
					ans++;
				}
			}
		} 
		if(ans>=m){
			anss++;
			anss%=MOD;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<anss;
	return 0;
}
