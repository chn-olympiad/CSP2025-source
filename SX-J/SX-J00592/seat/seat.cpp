#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int id=1;
	for(int i=1;i<=n*m;i++) if(a[i]>a[1]) id++;
	int ans1=(id-1)/n+1;
	id=(id-1)%n+1;
	int ans2=0;
	if(ans1%2) ans2=id;
	else ans2=n-id+1;
	printf("%d %d\n",ans1,ans2);
	return 0;
}
