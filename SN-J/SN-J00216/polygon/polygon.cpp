#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long n,ans;
long long a[5010];
bool cmp(long long x,long long y){
	return x>=y;
}
long long C(long long x,long long y){
	long long a=1,b=1;
	for(int i=1;i<=y;i++){
		a = a*x%p;
		x--;
	}
	for(int i=y;i>=1;i--) b = b*i%p;
	return (a/b)%p; 
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n<3){
		cout<<0;
		return;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		cout<<ans;
		return;
	}
	if(a[1]==1){
		for(int i=3;i<=n;i++){
			ans += C(n,i);
		}
		cout<<ans;
		return;
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		if(a[1]+a[2]+a[4]>a[4]*2) ans++;
		if(a[1]+a[3]+a[4]>a[4]*2) ans++;
		if(a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		cout<<ans;
		return;
	}
	if(n==5){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		if(a[1]+a[2]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[3]+a[4]+a[5]>a[5]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		cout<<ans;
		return;
	}
	if(n==6){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		if(a[1]+a[2]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[6]>a[6]*2) ans++;
		if(a[1]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[5]+a[6]>a[6]*2) ans++;
		
		if(a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[6]>a[6]*2) ans++;
		if(a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[4]+a[6]>a[6]*2) ans++;
		if(a[2]+a[5]+a[6]>a[6]*2) ans++;
		
		if(a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[3]+a[5]+a[6]>a[6]*2) ans++;
		
		if(a[4]+a[5]+a[6]>a[6]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[2]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		cout<<ans;
		return;
	}
	if(n==7){
		if(a[1]+a[2]+a[3]>a[3]*2) ans++;
		if(a[1]+a[2]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[7]>a[7]*2) ans++;
		if(a[1]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[7]>a[7]*2) ans++;
		if(a[1]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[4]+a[7]>a[7]*2) ans++;
		if(a[1]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[5]+a[7]>a[7]*2) ans++;
		if(a[1]+a[6]+a[7]>a[7]*2) ans++;
		
		if(a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[7]>a[7]*2) ans++;
		if(a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[4]+a[6]>a[6]*2) ans++;
		if(a[2]+a[4]+a[7]>a[7]*2) ans++;
		if(a[2]+a[5]+a[6]>a[6]*2) ans++;
		if(a[2]+a[5]+a[7]>a[7]*2) ans++;
		if(a[2]+a[6]+a[7]>a[7]*2) ans++;
		
		if(a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[3]+a[4]+a[7]>a[7]*2) ans++;
		if(a[3]+a[5]+a[6]>a[6]*2) ans++;
		if(a[3]+a[5]+a[7]>a[7]*2) ans++;
		if(a[3]+a[6]+a[7]>a[7]*2) ans++;
		
		if(a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[4]+a[5]+a[7]>a[7]*2) ans++;
		if(a[4]+a[6]+a[7]>a[7]*2) ans++;
		
		if(a[5]+a[6]+a[7]>a[7]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[3]+a[7]>a[7]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[4]+a[7]>a[7]*2) ans++;
		if(a[1]+a[2]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[5]+a[7]>a[7]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[4]+a[7]>a[7]*2) ans++;
		if(a[1]+a[3]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[5]+a[7]>a[7]*2) ans++;
		if(a[1]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[4]+a[5]+a[7]>a[7]*2) ans++;
		if(a[1]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[2]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[4]+a[7]>a[7]*2) ans++;
		if(a[2]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[2]+a[4]+a[5]+a[7]>a[7]*2) ans++;
		if(a[2]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		if(a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[3]+a[4]+a[5]+a[7]>a[7]*2) ans++;
		if(a[3]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		if(a[4]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[7]>a[7]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]+a[7]>a[7]*2) ans++;
		if(a[1]+a[2]+a[3]+a[6]+a[7]>a[7]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]+a[7]>a[7]*2) ans++;
		if(a[1]+a[2]+a[4]+a[6]+a[7]>a[7]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]+a[7]>a[7]*2) ans++;
		if(a[1]+a[3]+a[4]+a[6]+a[7]>a[7]*2) ans++;
		if(a[1]+a[3]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		if(a[1]+a[4]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]+a[7]>a[7]*2) ans++;
		if(a[2]+a[3]+a[4]+a[6]+a[7]>a[7]*2) ans++;
		if(a[2]+a[3]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		if(a[2]+a[4]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		if(a[3]+a[4]+a[5]+a[6]+a[7]>a[7]*2) ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[6]*2) ans++;
		cout<<ans;
		return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long t=1;
	while(t--){
		solve();
	}
	
	
	return 0;
}
