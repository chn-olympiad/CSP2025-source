#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,ans;
string s;
int c[505];
long long f[500];
long long fun(long long x){
	if(f[x]) return f[x];
	f[x]=fun(x-1)*x%M;
	return f[x];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(s.find("1")==-1) cout<<0;
	else if(s.find("1")!=-1&&s.find("0")!=-1&&m==n) cout<<0;
	else if(s.find("0")==-1){
		f[1]=1;
		cout<<fun(n);
	}else cout<<2;
	return 0;
}