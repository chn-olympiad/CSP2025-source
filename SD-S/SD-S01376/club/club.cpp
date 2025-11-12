#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int maxn=1e5+10;
int t,n,a[maxn][4],x[maxn],y[maxn],z[maxn],cntx,cnty,cntz,sum;
int mid(int a,int b,int c){
	return a+b+c-max(max(a,b),c)-min(min(a,b),c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
			
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				x[++cntx]=a[i][1]-mid(a[i][1],a[i][2],a[i][3]);
				sum+=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				y[++cnty]=a[i][2]-mid(a[i][1],a[i][2],a[i][3]);
				sum+=a[i][2];
			}
			else{
				z[++cntz]=a[i][3]-mid(a[i][1],a[i][2],a[i][3]);
				sum+=a[i][3];
			}
		}
		if(cntx>(n>>1)){
			int k=cntx-(n>>1);
			sort(x+1,x+1+cntx);
			for(int i=1;i<=k;i++)sum-=x[i];
		}
		else if(cnty>(n>>1)){
			int k=cnty-(n>>1);
			sort(y+1,y+1+cnty);
			for(int i=1;i<=k;i++)sum-=y[i];
		}
		else if(cntz>(n>>1)){
			int k=cntz-(n>>1);
			sort(z+1,z+1+cntz);
			for(int i=1;i<=k;i++)sum-=z[i];
		}
		printf("%d\n",sum);
		cntx=cnty=cntz=sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
