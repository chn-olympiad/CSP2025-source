#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			ans=i;
			break;
		}
	}
	printf("%d ",(ans-1)/n+1);
	ans%=2*n;
	if(!ans)ans=2*n;
	if(ans<=n)printf("%d",ans);
	else printf("%d",2*n-ans+1);
	return 0;
}
