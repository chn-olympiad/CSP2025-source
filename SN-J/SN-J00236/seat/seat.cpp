#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
long long n,m,a[maxn][maxn],r,cnt=1,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
			if (i==1&&j==1){
				r=a[i][j];
			}
			else if (r<a[i][j])cnt++;
		}
//	cout<<cnt; 
	long long ans1=cnt/m,ans2,cntn;
	if (cnt%m)ans1+=1,cntn=cnt%n;
	else cntn=n;
	if (ans1%2==1)ans2=cntn;
	else ans2=n-cntn+1;
	printf("%lld %lld",ans1,ans2);
	return 0;
}
