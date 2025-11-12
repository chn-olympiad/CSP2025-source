#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][4];
long long ans;
int popu[4];
struct member{
	int id;
	int num;
	short like;
	short hate;
	short soso;
}myc[100005];

void myinit(){
	memset(a,0,sizeof(a));
	ans=0;
	memset(popu,0,sizeof(popu));
}

bool operator< (member A,member B){
	return A.num>B.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	for (int i=0;i<t;i++){
		myinit();
		scanf("%d",&n);
		for (int j=1;j<=n;j++){
			scanf("%d %d %d",&a[j][1],&a[j][2],&a[j][3]);
			int Min=min(a[j][1],a[j][2]);
			Min=min(Min,a[j][3]);
			a[j][1]=a[j][1]-Min;
			a[j][2]=a[j][2]-Min;
			a[j][3]=a[j][3]-Min;
			ans+=Min;
			myc[j].id=j;
			if (a[j][1]==0){
				myc[j].hate=1;
				if (a[j][2]>a[j][3]){
					myc[j].soso=3;
					myc[j].like=2;
				}else{
					myc[j].soso=2;
					myc[j].like=3;
				}
			}
			else if (a[j][2]==0){
				myc[j].hate=2;
				if (a[j][1]>a[j][3]){
					myc[j].soso=3;
					myc[j].like=1;
				}else{
					myc[j].soso=1;
					myc[j].like=3;
				}
			}else{
				myc[j].hate=3;
				if (a[j][1]>a[j][2]){
					myc[j].soso=2;
					myc[j].like=1;
				}else{
					myc[j].soso=1;
					myc[j].like=2;
				}
				
			}
			myc[j].num=abs(a[j][myc[j].like]-a[j][myc[j].soso]);
		}
		sort(myc+1,myc+1+n);
		for (int j=1;j<=n;j++){
			if (popu[myc[j].like]+1>n/2){
				popu[myc[j].soso]+=1;
				ans+=a[myc[j].id][myc[j].soso];
			}else{
				popu[myc[j].like]+=1;
				ans+=a[myc[j].id][myc[j].like];
			}
		}
		
		printf("%lld\n",ans);
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
