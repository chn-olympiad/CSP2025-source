//惠子轩  SN-S00287  西安铁一中滨河高级中学 
#include <bits/stdc++.h>
using namespace std;
struct node{
	int aa;
	int bb;
	int cc;
};

int b[7];
int main(){
	freopen("club","r",stdin);
	freopen("club","w",stdout);	
int maxx=-1;
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		node a[100010];
		for(int j=1; j<=n; j++){
			cin>>a[j].aa>>a[j].bb>>a[j].cc;
		}	
	 b[1]=a[1].aa+a[2].bb;
	 b[2]=a[1].aa+a[2].cc;
	 b[3]=a[1].bb+a[2].aa;
	 b[4]=a[1].bb+a[2].cc;
	 b[5]=a[1].cc+a[2].aa;
	 b[6]=a[1].cc+a[2].aa;

	for(int z=1;z<=6;z++){
		if(maxx<=b[z])maxx=b[z];
	}
		
		
		
	}
	
	cout<<maxx;
	
	
return 0;	
}
