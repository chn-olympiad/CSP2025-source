#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,m,a[N],num,ans,maxn,minn,b[N],INF=998244353;
string s,as;
void f(int d,int sum,int maxn,int ij){
	if(d>3){
		if(sum>maxn*2){
			ans++;
			ans%=INF;
		}
	}
	if(d>n)return;
	for(int i=ij;i<=n;i++){
		f(d+1,sum+a[i],a[i],i+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f(1,0,0,1);
	cout<<ans%INF;
	return 0;
}//#Shang4Shan3Ruo6Shui4