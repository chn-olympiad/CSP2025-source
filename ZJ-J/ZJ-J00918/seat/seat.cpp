#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N],cnt,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i!=1&&a[i]>a[1]) cnt++;
	}
	ans1=cnt/n;ans2=cnt%n;
	ans1++;ans2++;
	printf("%d ",ans1);
	if(ans1%2==0) printf("%d\n",n-ans2+1);
	else printf("%d\n",ans2);
	
	return 0;
}

