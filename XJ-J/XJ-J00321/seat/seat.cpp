#include<bits/stdc++.h>
using namespace std;
int n,m,d[100][100],a[110],cnt=0,an,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	an=n*m;
	for(int i=1;i<=an;i++){
		scanf("%d",&a[i]);
		a[i]*=-1;
	}
	r=-a[1];
	sort(a+1,a+an+1);
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++)
				d[j][i]=-a[++cnt];
		if(i%2==0)
			for(int j=n;j>=1;j--)
				d[j][i]=-a[++cnt];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(d[i][j]==r)
				printf("%d %d",j,i);
	return 0;
}
//AC!!!
