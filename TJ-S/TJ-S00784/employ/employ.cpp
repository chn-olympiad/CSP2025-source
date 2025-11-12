#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,m,c[505],cnt,t[505],d[505];
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if (s[i]=='0') d[++cnt]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ans=ans*d[c[i]]%md;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
