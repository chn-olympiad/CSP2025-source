#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt,num,l = 1,r = 1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			int ans = 0;
			for(int k = i;k<=j;k++){
				ans += a[k];
				num++;
			}
			if(ans > 2*a[j] && num >= 3){	
				cnt++;
			}
			num = 0;
		}
	}
	cout<<cnt;
}
