#include <bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
int d[10005][10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){ 
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++){
				d[i][j]=0;
			}
		}
		int cntn=0;
		for(int i=1;i<=n;i++){
			cntn+=max(max(a[i],b[i]),c[i]);
		}
		cout<<cntn<<endl;
	}
	return 0;
}
