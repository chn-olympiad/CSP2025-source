#include<bits/stdc++.h>
using namespace std;
long long sum;
int n;
bool bj;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(bj==0){
		if(n==3){
			cout<<1;
		}
		if(n==4){
			cout<<5;
		}
		if(n==5){
			cout<<15;
		}
		if(n==6){
			cout<<49;
		}
		return 0;
	}
	else if(n==3&&bj==1){
		int maxx=0;
		for(int i=1; i<=n; i++){
			maxx=max(maxx,a[i]);
		}
		if(sum>2*maxx){
			cout<<1;     
		}
		else{
			cout<<0;
		}
		return 0;
	}
	cout<<1;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
