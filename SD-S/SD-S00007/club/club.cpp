#include<bits/stdc++.h>
using namespace std;
struct people{
	int ga,gb,gc;
	int best;
	int bestnum;
	int nextnum;
	int diss;
}a[100021];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int ui=0;ui<t;ui++){
		scanf("%d",&n);
		int sum[5]={0};
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].ga,&a[i].gb,&a[i].gc);
			a[i].bestnum=max(max(a[i].ga,a[i].gb),a[i].gc);
			a[i].nextnum=min(max(a[i].ga,a[i].gb),min(max(a[i].ga,a[i].gc),max(a[i].gc,a[i].gb)));
			a[i].diss=a[i].bestnum-a[i].nextnum;
			if(a[i].bestnum==a[i].ga){
				a[i].best=1;
			}
			if(a[i].bestnum==a[i].gb){
				a[i].best=2;
			}
			if(a[i].bestnum==a[i].gc){
				a[i].best=3;
			}
			sum[a[i].best]++;
		}
		int more=-1;
		int asn=0;
		for(int i=1;i<=n;i++){
			asn+=a[i].bestnum;
		}
		if(sum[1]>n/2){
			more=1;
		}
		if(sum[2]>n/2){
			more=2;
		}
		if(sum[3]>n/2){
			more=3;
		}
		if(more==-1){
			printf("%d\n",asn);
			continue;
		}
		int di[100023];
		int g=0;
		for(int i=1;i<=n;i++){
			if(a[i].best==more){
				di[g]=a[i].diss;
				g++;
			}
		}
		sort(di,di+g);
		for(int i=0;i<sum[more]-n/2;i++){
			asn-=di[i];
		}
		printf("%d\n",asn);
	}
	return 0;
}
