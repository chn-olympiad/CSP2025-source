#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,P=998244353;
int n,m,c[N],fac[N];//n^2
string a,b;//0²»Â¼+1,1Â¼
map<int,int>mp;
int mul(int a,int b){
	a%=P,b%=P;
	return(a*b)%P;
}void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=mul(i,fac[i-1]);
}
signed main(){
	init(N-5);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;b=a;
	for(int i=0;i<n;++i)cin>>c[i],++mp[c[i]];
sort(b.begin(),b.end());
if(a==b&&b[0]=='1'){//A
	int sum=1;
	for(int i=2;i<=n;++i)
		(sum*=i)%=P;
	cout<<sum;
}sort(c,c+n);
int p=0,x=0;
	for(int i=0;i<n;++i){
		if(a[i]=='0')++p;
		if(p<c[i])++x;
	}if(x>=m){
		int ans=1;
		for(auto it:mp){
			ans=mul(ans,fac[it.second]);
		}cout<<ans;
	}else cout<<0;
	return 0;
}
