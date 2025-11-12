#include <bits/stdc++.h>
using namespace std;
int f[100005][3],t,n,a[3],con=-100000;
struct node{
	int d0,d1,d2;
	long long p;
}d[100005][3];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int x=0;x<t;x++){
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				cin>>f[i][j];
		for(int i=1;i<=n;i++){
				
		}
		cout<<max(d[n][0].p,max(d[n][1].p,d[n][2].p))<<endl;
	}
}
