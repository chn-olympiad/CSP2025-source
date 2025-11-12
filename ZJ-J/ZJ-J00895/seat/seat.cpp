#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,m,a[N],num,ans,sum,maxn,minn;
string s,as;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++)cin>>a[i];
	sum=a[1];
	sort(a+1,a+1+c);
	for(int i=c;i>=1;i--){
		if(a[i]==sum){
			num=c-i+1;
			break;
		}
	}
	if(num%n==0){
		int d=num/n;
		if(d%2==0)cout<<d<<" "<<1;
		else cout<<d<<" "<<n;
	}
	else{
		int d=(num+n)/n;
		int cd=num/n;
		int cdd=num%n-1;
		if(cd%2==0)cout<<d<<" "<<1+cdd;
		else cout<<d<<" "<<n-cdd;
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4