#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010],num[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		num[i]=num[i-1]+a[i];
	}
	for (int l=3;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l-1;
			if (j>n){
				continue;
			}
			int sum=num[j-1]-a[i-1];
			if (sum>a[j]){
				for (int l1=1;l1<=n;l1++){
					for (int x=i+1;x+l1-1<j;x++){
						int y=x+l1-1;
						if (sum-(num[y]-num[x-1])>a[j]){
							ans++;
						}
					}
				}
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
