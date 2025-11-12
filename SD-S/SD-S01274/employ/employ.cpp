#include <bits/stdc++.h>
using namespace std;
int c[2005];
int n,m,p[2005],res;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m>>s;
	s='#'+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	do{
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]){
				cnt++;
				continue;
			} 
			if(s[i]=='1') ans++;
			else cnt++;
		}
		if(ans>=m) res++;
	}while(next_permutation(p+1,p+n+1));
	cout<<res%998244353<<endl;
	return 0; 
}
