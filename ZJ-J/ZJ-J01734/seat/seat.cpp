#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])cnt++;
	}printf("%d %d",cnt/n+1,cnt/n%2==0?cnt%n+1:n-cnt%n);
	return 0;
}
