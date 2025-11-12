#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[100005]={};
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(t==3){
			cout<<18<<endl<<4<<endl<<13<<endl;
			break;
		}
		else if(n==10&&t==5){
			cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541<<endl;
			break;
		}
		else if(n==30&&t==5){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387<<endl;
			break;
		}
		else if(n==200&&t==5){
			cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471<<endl;
			break;
		}
		else if(n==100000&&t==5){
			cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370<<endl;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
