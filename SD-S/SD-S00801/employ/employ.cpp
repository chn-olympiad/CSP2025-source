#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+10;
const int p=998244353;
int n,m,a[N],ans,gj[N];
bool _1=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++){
		_1&=(s[i]=='1');
	}
	if(_1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=p;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		gj[i]=i;
		cin>>a[i];
	}
	do{
		int ac=0,c=0;
//		for(int i=1;i<=n;i++){
//			cout<<a[gj[i]]<<" ";
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') c++;
			else if(c>=a[gj[i]]) c++;
			else ac++;
		}
		if(ac>=m) ans++;
	}while(next_permutation(gj+1,gj+n+1));
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
