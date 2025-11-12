#include <bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
int num[5001];
bool d(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1,d);
	if (n<3){
		cout<<0;
	}
	else if(n=3){
		if(num[1]+num[2]+num[3]>num[1]*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
