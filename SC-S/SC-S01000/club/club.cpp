#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int p;
	cin>>p; 
	int n;
	cin>>n;
	while(p--){
	int num=0;
	for(int i=1; i<=n; i++){
		int a,b,c;
		cin>>a>>b>>c;
		max(a,b,c);
		num+=max(a,b,c);
	}
	cout<<num;

	}
	
	return 0;
} 