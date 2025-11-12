#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=11;
const ll mod=998244353;
int n,m,ans,a[505],c[505];
string s;
void solve(){
	do{
		int num=0;
		for(int i=1;i<=n;++i){
			int x=a[i];
			if(num>=c[x]){
				++num;
				continue;
			}
			if(s[i]=='0')
				++num;
		}
		ans+=(n-num>=m);
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	int A=0,B=0;
	for(int i=1;i<=n;++i){
		cin>>c[i],a[i]=i;
		B+=(c[i]!=0);
		A+=(s[i]=='1');
	}		
	solve();
	return 0;
}
