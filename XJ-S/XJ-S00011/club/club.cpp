#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
const int N=1e5+10;
int n,max_n,sum_1,sum_2,sum_3;
bool sum_1b,sum_2b,sum_3b;

struct my{
	int c1,c2,c3,zui;
	bool nf;
}arr[N];

int tx(){
	int ji=0,max_c1,max_c2,max_c3,x=n;
	for(int i=1;i<=n;i++){
		if(arr[i].nf==true){
			ji+=ji+=arr[i].zui;
			arr[i].nf=false;
		}
	}
	
	return ji;
}

int main(){
	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		max_n=0;
		for(int i=1;i<=n;i++){
			cin>>arr[i].c1>>arr[i].c2>>arr[i].c3;
			arr[i].zui=max(arr[i].c1,max(arr[i].c2,arr[i].c3));
			arr[i].nf=true;
		}    
		cout<<tx()<<'\n';
	}
	return 0;
}
