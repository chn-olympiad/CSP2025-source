#include<bits/stdc++.h>
#define int long long
using namespace std;
const int md=998244353;
int n,m,c[501];
int a[501];
string s;
bool chk(){
	for(int i=1;i<=n;i++)
		if(a[i]!=i)
			return true;
	return false;
}
int gt(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(i-cnt-1>=c[a[i]])
			continue;
		if(s[i-1]=='1')
			cnt++;
	}
	return (cnt>=m);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]=='0'||c[i+1]==0){
				cout<<0;
				return 0;
			}
		}
		int ans=1;
		for(int i=2;i<=n;i++)
			ans=ans*i%md;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		a[i]=i;
	int ans=gt();
	next_permutation(a+1,a+1+n);
	for(;chk();next_permutation(a+1,a+1+n))
		ans+=gt();
	cout<<ans;
	return 0;
}
