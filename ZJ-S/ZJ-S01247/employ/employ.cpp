#include <bits/stdc++.h>
using namespace std;
long long n,m;string str;
long long vis[505];
long long a[505];

long long pa[505];
long long mn(){
	long long out= 0;
	long long sum = 0;
	for(long long j = 1;j<=n;j++){
		long long i = a[j];
		if(out<pa[i] && str[j-1]=='1'){
			sum++;
		}else{
			out++;
		}
	}
	if(sum>=m){
		return 1;
	}else{
		return 0;
	}
}
long long ans = 0;
void pl(long long x){
	if(x>n){
		bool flag = 0;
		ans+=mn();
		return;
	}
	for(long long i = 1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[x]=i;
			pl(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> str;
	for(long long i = 1;i<=n;i++){
		cin >> pa[i];
	}
	pl(1);
	cout << ans;
	return 0;
}
