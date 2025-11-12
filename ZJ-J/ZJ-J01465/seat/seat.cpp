#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int t=n*m;
	for(int i=1;i<=t;i++) scanf("%d",&a[i]);
	int s=a[1];
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--){
		if(a[i]==s){
			int id=t-i;
			int x=id/n+1;
			if(x&1) printf("%d %d\n",x,id%n+1);
			else printf("%d %d\n",x,n-id%n);
			return 0;
		}
	}
	return 0;
}