#include<bits/stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
int main(){
	int t;
	cin>>t;
	while(t--){
		int a[100500]={};
		int b[100500]={};
		int c[100500]={};
		int d=0;
		int n;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d=d+max(a[i],max(b[i],c[i]));
		}
		cout<<d<<endl;	
	}
	
	return 0;
freout("club.out","w",stdout);
} 