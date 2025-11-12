#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n*m;i++)
		if(a[i]>a[1]) k++;
	k++;
	int x,y,cnt=0;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++){
		cnt++;
		if(cnt==k){
			if(i%2==0)
				x=n-j+1;
			else x=j;
			y=i;
			printf("%d %d",y,x);
		}
	}
	return 0;
}