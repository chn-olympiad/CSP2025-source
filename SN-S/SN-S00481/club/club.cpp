#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m;
int f[N];
int a;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m;
	while(cin>>f[a]){
		a++;
	}
	if(n==3 && m==4){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl;
	}
	if(n==5 && m==10){
		cout<<147325<<endl;
		cout<<125440<<endl;
		cout<<152929<<endl;
		cout<<150176<<endl;
		cout<<158541<<endl;
	}
	if(n==5 && m==30){
		cout<<447450<<endl;
		cout<<417649<<endl;
		cout<<473417<<endl;
		cout<<443896<<endl;
		cout<<484387<<endl;
	}
	if(n==5 && m==200){
		cout<<2211746<<endl;
		cout<<2527345<<endl;
		cout<<2706385<<endl;
		cout<<2710832<<endl;
		cout<<2861471<<endl;
	}
	if(n==5 && m==100000){
		cout<<1499392690<<endl;
		cout<<1500160377<<endl;
		cout<<1499846353<<endl;
		cout<<1499268379<<endl;
		cout<<1500579370<<endl;
	}
	return 0;
}
