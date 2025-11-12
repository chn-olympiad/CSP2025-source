#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef double db;

void IOP(){
	cin.tie(0) ,cout.tie(0);
	ios::sync_with_stdio(0);
}

void frop(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}

const int MOD = 998244353,N = 5005;
int n;
int a[N],ans;

signed main(){
//	frop();//必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 
	IOP();//注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int b=0,d=1;
	for(int j=500;j<=5000;j++){
		b = 0,d=1;
		for(int i=3;i<=n;i++){
			d = 1;
			d*=i;
		}
		b+=d;
		
	}
	ans = b;
	
	cout<<ans%MOD;
	return 0;
}
