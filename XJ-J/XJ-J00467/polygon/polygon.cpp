#include<bits/stdc++.h> 
using namespace std;
int n;
int num[500000];
int ans;
int maxn=-10;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		ans=ans+num[i];
		maxn=max(num[i],maxn);
	}
	if(ans<=maxn*2){
		cout<<0;
	}else{
		cout<<1; 
	}
	
	
	 
}
