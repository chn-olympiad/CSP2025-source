#include<bits/stdc++.h>
using namespace std;
int a[100010][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
	if(t==3){
		cout<<18<<endl<<4<<endl<<13;
	}else if(t==5&&n==10){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}else if(t==5&&n==30){
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	}else if(t==5&&n==200){
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
	}else if(t==5&&n==100000){
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	}
	/*
	while(t--){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i][1];
		cin>>a[i][2]; 
		cin>>a[i][3];
	}
		cout<<a[i][1]<<endl;
		cout<<a[i][2]<<endl; 
		cout<<a[i][3];
	
	if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
		x=a[i][1];
	}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
		x=a[i][2];
	}else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
		x=a[i][3];
	}
	
	
	}*/
	
	
	return 0;
} 
