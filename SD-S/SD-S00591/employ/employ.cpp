#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,c[20],a[20],ans=0;
string s; 

signed main(){
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i],a[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]])cnt++;
			else if(s[i-1]=='0')cnt++;
		}
		if(n-cnt>=m)ans++;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans;
}
