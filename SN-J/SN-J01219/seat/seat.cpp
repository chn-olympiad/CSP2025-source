#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,mn,ni,mi;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	x=a[1];
	sort(a+1,a+10001);
	for(int i=0;i<=10000;i++){
		if(a[i]==x)mn=10000-i+1;
	}
	if(mn%n==0){
		mi=mn/n;
		ni=n;
		printf("%d %d",mi,ni);
		return 0;
	}
	else mi=mn/n+1;
	if(mi%2==0)ni=n-mn%n+1;
	else ni=mn%n;
	printf("%d %d",mi,ni);
	return 0;
}
