#include <bits/stdc++.h>
using namespace std;
int n,ans,a[5010];
int jc(int x,int y){
	int cnt=1;
	for (int i=x;i>=x-y+1;i--){
		cnt*=i;
	}
	for (int i=y;i>=2;i--){
		cnt=cnt/i;
	}
	return cnt;
}
int sl(int n){
	int cnt2=0;
	for (int i=1;i<=n;i++){
		cnt2+=jc(n,i)%998%244%353;
	}
	return cnt2;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for (int i=n;i>=3;i--){
		for (int j=i-1;j>=2;j--){
			if (a[j]+a[j-1]<=a[i]){
				break;
			}
			for (int k=j-1;k>=1;k--){
				if (a[k]+a[j]<=a[i]){
					break;
				}
				ans+=sl(k-1)%998%244%353+1;
			}
		}
	}
	cout<<ans%998%244%353;
	return 0;
}
