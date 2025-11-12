#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
int a[500050]={};
bool sy[500050]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n,k;
	int c;
	bool y;
	int ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sy[i]=false;
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			sy[i]=true;
			ans++;
			
			continue;
		}
		c=a[i];
		y=false;
		int j=i-1;
		for(;j>=0 && sy[j]==false;j--){
			c^=a[j];
			if(c==k){
				y=true;
				break;
			}
		}
		if(y==true){
			for(int z=j+1;z<=i;z++) sy[i]=true;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
