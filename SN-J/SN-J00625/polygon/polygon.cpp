#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,a[N];
long long sum,ans=1,cnt=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3){
		printf("%d",0);
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[3]<a[2]+a[1]) printf("%d",1);
		else printf("%d",0);
		return 0;
	}
	for(int i=3,ii;i<=n;i++){
		if(i>n/2) ii=n-i;
		else ii=i;
		for(int j=1;j<=ii;j++){
			ans=ans*(n-j+1);
			cnt=cnt*j;
			if(ans%cnt==0){
				ans=ans/cnt;
				cnt=1;
			}
		}
		sum+=(ans/cnt);
		ans=cnt=1;
	}
	sum%=998244353;
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
