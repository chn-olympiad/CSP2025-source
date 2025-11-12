#include<bits/stdc++.h>
using namespace std;
int temp[7][4]={{0,0,0,0},
			  {0,1,2,3},
			  {0,1,3,2},
			  {0,2,1,3},
			  {0,2,3,1},
			  {0,3,1,2},
			  {0,3,2,1}};int i;
const int N=1e5+10;
struct r{
	int d[4];
}a[N];
bool cmp(r a,r b){
	if(a.d[temp[i][1]]==b.d[temp[i][1]]){
		if(a.d[temp[i][2]]==b.d[temp[i][2]]){
			return a.d[temp[i][3]]>b.d[temp[i][3]];
		}
		return a.d[temp[i][2]]>b.d[temp[i][2]];
	}
	return a.d[temp[i][1]]>b.d[temp[i][1]];
}
int t,n;
void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i].d[j]);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		init();
		int maxn=-1;
		for(i=1;i<=6;i++){
			sort(a+1,a+n+1,cmp);
			int sum=0,sum2=0;
			int nn=n/2;
			int wz=1;
			for(int j=1 ;j<=3;j++){
				sum2=0;
				while(a[wz].d[temp[i][j]]>a[wz].d[temp[i][(j-1)%3+1]]&&a[wz].d[temp[i][j]]>a[wz].d[temp[i][(j-2)%3+2]]&&sum2<=nn&&wz<=n){
					sum+=a[wz].d[temp[i][j]];
					sum2++;
					wz++;
				}
			}
			maxn=max(maxn,sum);
		}
		printf("%d",maxn);
	}
	return 0;
} 
