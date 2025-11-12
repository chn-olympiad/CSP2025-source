#include<bits/stdc++.h>
using namespace std;
long long n=0,num[5005],ans;	
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num,num+n+1);
	if(n==3){
		if(num[3]*2<num[1]+num[2]+num[3]){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
	if(n==4){
		if(num[3]*2<num[1]+num[2]+num[3]){
			ans++;
		}
		if(num[4]*2<num[1]+num[2]+num[4]){
			ans++;
		}
		if(num[4]*2<num[1]+num[4]+num[3]){
			ans++;
		}
		if(num[4]*2<num[4]+num[2]+num[3]){
			ans++;
		}
		if(num[4]*2<num[1]+num[2]+num[3]+num[4]){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==5){
		if(num[3]*2<num[1]+num[2]+num[3]){
			ans++;
		}
		if(num[4]*2<num[1]+num[2]+num[4]){
			ans++;
		}
		if(num[5]*2<num[5]+num[2]+num[1]){
			ans++;
		}
		if(num[4]*2<num[4]+num[1]+num[3]){
			ans++;
		}
		if(num[5]*2<num[1]+num[5]+num[3]){
			ans++;
		}
		if(num[5]*2<num[1]+num[5]+num[4]){
			ans++;
		}
		if(num[4]*2<num[2]+num[4]+num[3]){
			ans++;
		}
		if(num[5]*2<num[5]+num[2]+num[3]){
			ans++;
		}
		if(num[5]*2<num[5]+num[2]+num[4]){
			ans++;
		}
		if(num[5]*2<num[5]+num[4]+num[3]){
			ans++;
		}
		if(num[4]*2<num[1]+num[2]+num[3]+num[4]){
			ans++;
		}
		if(num[5]*2<num[1]+num[2]+num[3]+num[5]){
			ans++;
		}
		if(num[5]*2<num[1]+num[5]+num[3]+num[4]){
			ans++;
		}
		if(num[5]*2<num[5]+num[2]+num[3]+num[4]){
			ans++;
		}
		if(num[5]*2<num[1]+num[2]+num[5]+num[4]){
			ans++;
		}
		if(num[5]*2<num[1]+num[2]+num[3]+num[4]+num[5]){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
