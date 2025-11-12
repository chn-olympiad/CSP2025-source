#include<bits/stdc++.h>
using namespace std;
const int P=998244353;

int n,m,c[505],s[505],ans=0;
char s1[505];

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		s[i]=int(s1[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	
	
	cout<<ans%P;
	
	return 0;
}
