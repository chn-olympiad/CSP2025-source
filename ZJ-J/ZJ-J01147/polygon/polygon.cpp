#include<bits/stdc++.h>
using namespace std;
int n,nums[99999],cnt=0,a,b;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		a+=m;
		b=max(b,m);
	}
	if(a>b*2){
		cnt=1;
	}
	cout<<cnt;
	return 0;
} 
