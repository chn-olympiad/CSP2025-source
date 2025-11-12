#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		int twoma=a[i]*2;
		int sum=a[i];
		for(int j=i-1;j>=1;j--){
			sum+=a[j];
			if(sum>twoma){
				ans+=j;
			}
		}
	}
	int answer=ans%998244353;
	printf("%d",answer);
	return 0;
}
