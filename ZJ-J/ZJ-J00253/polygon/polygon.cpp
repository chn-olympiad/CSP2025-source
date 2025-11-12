#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,n[5010],m[5010],s;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>n[i];
	}
	sort(n+0,n+a);
	m[0]=1;
	for(int i=0;i<a;i++){
		for(int j=n[i]+1;j<=5001;j++){
			s+=m[j];
			s%=998244353;
		}
		for(int j=5001;j>=5001-n[i];j--){
			m[5001]+=m[j];
			m[5001]%=998244353;
		}
		for(int j=5000;j>=n[i];j--){
			m[j]+=m[j-n[i]];
			m[j]%=998244353;
		}
	}
	cout<<s;
	return 0;
}
