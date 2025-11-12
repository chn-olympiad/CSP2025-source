#include <bits/stdc++.h>

using namespace std;

const int N=5e5+5;
int a[N],b[N],n,k,ans=0;
int yihuo(int num){
	int ans[1005],cnt=0,sum=0;
	while(num!=1){
		ans[cnt]=num%2;
		num/=2;
		if(ans[cnt]==1) ans[cnt]=0;
		else ans[cnt]=1;		
		cnt++;
	}
	ans[cnt]=num%2;
	num/=2;
	if(ans[cnt]==1) ans[cnt]=0;
	else ans[cnt]=1;		
	cnt++;
	if(cnt==1) return 1;
	for(int i=0;i<cnt;i++){
		sum+=pow(ans[i],cnt-i-1);
	}
	return sum;
}
int main(){
	cout << yihuo(2);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		
	}
	cout << ans;
	return 0;
}
