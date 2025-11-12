#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],f[100005],mx1,mx2;
bool flag=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		flag=0;
		mx1=0;
		mx2=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>mx1){
				mx2=mx1;
				mx1=a[i][1];
			}
			if(a[i][2]!=0 || a[i][3]!=0)
				flag=1;
		}
		if(n==2){
			sort(a[1]+1,a[1]+3);
			sort(a[2]+1,a[2]+3);
			if(a[1][3]==a[2][3])
				printf("%d\n",max(a[1][3]+a[2][2],a[1][2]+a[2][3]));
			else
				printf("%d\n",a[1][3]+a[2][3]);
		}
		else if(!flag)
			printf("%d\n",mx1+mx2);
	}
	return 0;
}

