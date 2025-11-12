#include <bits/stdc++.h>
using namespace std;
int a[5010],n,sumLen,maxLen,ans;
void findPolygon(int num,int m){
	if(num >=3 && sumLen>2*maxLen){
		ans++;
		ans%=998244353;
		if(num == n) return;
	}
	for(int i=m+1;i<=n;i++){
		maxLen = a[i];
		sumLen+=a[i];
		int temp=ans;
		findPolygon(num+1,i);
		maxLen = 0;
		sumLen-=a[i];
		if(ans == temp) break;
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	findPolygon(0,0);
	cout<<ans%998244353;
	return 0;
}
