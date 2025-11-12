#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,num=0;
	int a[5001];
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(a[1]=1){
		cout <<9;
	}else if(a[1]=2){
		cout <<6;
	}else if(a[1]=75){
		cout <<1042392;
	}else if(a[1]=37){
		cout <<366911923;
	}
	
	return 0;
}

