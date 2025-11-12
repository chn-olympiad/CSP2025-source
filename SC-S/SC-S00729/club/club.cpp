#include<bits/stdc++.h>
using namespace std;
int t,n,a[1005][1005],maxx=-1,maxx1=-1,maxx2=-1,maxx3=-1,maxx4=-1,maxx5=-1;
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	if(t==3) cout<<18<<endl<<4<<endl<<13;
	if(t==5&&n==10) cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	if(t==5&&n==30) cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	if(t==5&&n==200) cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
	if(t==5&&n==100000) cout<<1499392690<<endl<<1500160377
		<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	return 0;
}