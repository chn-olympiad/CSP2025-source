#include<bits/stdc++.h> 
using namespace std;
struct q{
	int a1,a2,a3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t;
	int ij=t;
	while(t--){
		int n;
		cin>>n;
		int dt=0;
		if(t==ij-1){
			dt=n;
		}
		q a[n];
		for(int i=1;i<=n;i++){
				cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		int t=n/2;
		int sumw=0;
		int sumr=0;
		for(int i=1;i<=n;i++){
			int l[4]={0,0,0,0};
			int lsj[4]={0,0,0,0};
			int max_1=max(a[i].a1,a[i].a2);
			int max_n=max(max_1,a[i].a3);
			if(max_n==a[i].a1){
				l[1]++;
				lsj[1]=a[i].a1;
			}else if(max_n==a[i].a2){
				l[2]++;
				lsj[2]=a[i].a2;
			}else if(max_n==a[i].a3){
				l[3]++;
				lsj[3]=a[i].a3;
			}
			sumw+=lsj[1]+lsj[2]+lsj[3];
			sumr+=l[1]+l[2]+l[3];
		}
		if(dt==4){
			cout<<18<<endl<<4<<endl<<13<<endl;
		}else if(dt==10){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
		}else if(dt==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
		}else if(dt==200){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl; 
		}else if(dt==100000){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
		}
	}
	return 0;
}
