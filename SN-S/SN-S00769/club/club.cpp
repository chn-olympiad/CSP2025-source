#include<bits/stdc++.h>
using namespace std;
int n,t,p[100005];
int a[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int o=0;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			p[j]=max(a[j][1],max(a[j][2],a[j][3]));
		}
		for(int j=1;j<=n;j++){
			o+=p[j];
		}
		cout<<o<<endl;
	}
	return 0;
}
/*º«ÓêÔó*/ 
