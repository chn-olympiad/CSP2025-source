#include <bits/stdc++.h>
using namespace std;

int n,m,R;
int a[115];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[(j-1)*n+i]);
			
	R=a[1];
	sort(a+1,a+n*m,greater<int>());
	
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[(j-1)*n+i]==R){
				if(j%2==1)printf("%d %d\n",j,i);
				else printf("%d %d\n",j,n-i+1);
				return 0;
			}
}
