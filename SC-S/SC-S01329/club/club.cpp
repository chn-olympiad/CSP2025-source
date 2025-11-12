#include<bits/stdc++.h>
using namespace std;
struct fun{
int a,b,c,best,cha,best2;
}stu[1000000];
int n;
int t,ans=0;
int temp[4];
int club[4];
int club1[500000],club2[500000],club3[100000];
int t1,t2,t3,tc;
int book[1000000];
int cc[1000000];
int ccc;
//1就是a； 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;ccc=0;
		for(int i=1;i<=n;i++){
			club1[i]=0;club2[i]=0;club3[i]=0;
			book[i]=0;cc[i]=0;
		}
		t1=0;t2=0;t3=0;tc=0;
		for(int i=1;i<=3;i++){
			club[i]=0;
		}
		cin>>n;
		int  nn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>temp[j];
			}
			stu[i].a=temp[1];stu[i].b=temp[2];stu[i].c=temp[3];
			sort(temp+1,temp+4);
			stu[i].best=temp[3];
			stu[i].cha=stu[i].best-temp[2];
			for(int i=1;i<=3;i++){
				if(stu[i].best==stu[i].a&&book[i]==0){
					club[1]++;
					club1[++t1]=i;
					book[i]++;
				}
				if(stu[i].best==stu[i].b&&book[i]==0){
					club[2]++;
					club2[++t2]=i;
					book[i]++;
				}
				if(stu[i].best==stu[i].c&&book[i]==0){
					club[3]++;
					club3[++t3]=i;
					book[i]++;
				}
			}
		}
		for(int i=1;i<=3;i++){
			if(club[i]>nn){
				int tt=club[i]-nn;
					if(i==1){
						for(int m=1;m<=t1;m++){
							cc[m]=stu[club1[m]].cha;
						}
						sort(cc+1,cc+1+t1);
						for(int j=1;j<=tt;j++){
							ccc+=cc[j];
						}
					}
					if(i==2){
						for(int m=1;m<=t2;m++){
							cc[m]=stu[club2[m]].cha;
						}
						sort(cc+1,cc+1+t2);
						for(int j=1;j<=tt;j++){
							ccc+=cc[j];
						}
					}
					if(i==3){
						for(int m=1;m<=t3;m++){
							cc[m]=stu[club3[m]].cha;
						}
						sort(cc+1,cc+1+t3);
						for(int j=1;j<=tt;j++){
							ccc+=cc[j];
						}
					}
				break;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=stu[i].best;
		}
		cout<<ans-ccc;
		printf("\n");
	}
	return 0;
}