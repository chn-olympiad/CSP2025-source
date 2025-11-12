//王若航 SN-S00522 陕西省丹凤中学
#include<bits/stdc++.h>
using namespace std;
int b[100005];
int a[5][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int n,j,i,t,k=0;
	cin>>n>>t;
	for(i=1;i<99*n;i++)
		{
			cin>>a[i];
		if(a[i]>=a[i+1]){k=k+a[i];}
		else{k=k+a[i+1];}
	}
}
	  cout<<k<<endl;
	

	return 0;
}
