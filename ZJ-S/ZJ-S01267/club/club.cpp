#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int b[N][5];
int n,t,c[5][N],d[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&b[i][1],&b[i][2],&b[i][3]);
		int c1=0,c2=0,c3=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			int a1=b[i][1],a2=b[i][2],a3=b[i][3];
			if(a1>=a2&&a1>=a3)c[1][++c1]=i,sum+=a1;
			else if(a2>=a1&&a2>=a3)c[2][++c2]=i,sum+=a2;
			else c[3][++c3]=i,sum+=a3;
		}
		int k=0,p=0,q=0,l=0;
		if(c1<=n/2){
			if(c2<=n/2){
				if(c3<=n/2){
					k=0;
				}else k=3,p=1,q=2,l=c3;
			}else k=2,p=1,q=3,l=c2;
		}else k=1,p=2,q=3,l=c1;
		if(k==0){
			printf("%lld\n",sum);
			continue;
		}
		for(int i=1;i<=l;i++){
			int h=c[k][i];
			d[i]=b[h][k]-max(b[h][p],b[h][q]);
			
		}
		sort(d+1,d+l+1);
		for(int i=1;i<=l-(n/2);i++)sum-=d[i];
		printf("%lld\n",sum);
	}
}
