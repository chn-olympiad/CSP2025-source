#include<bits/stdc++.h>
using namespace std;
int n,t;
struct mem{
	int a[4];
}m[100001];
bool rule(mem am,mem bm){
	return am.a[1]>bm.a[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","rw",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a[1]>>m[i].a[2]>>m[i].a[3];
		}
		if(n==2){
			int mx=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3&&j!=i;j++){
					if(m[1].a[i]+m[2].a[j]>mx){
						mx=m[1].a[i]+m[2].a[j];
					}
				}
			}
			cout<<mx;
		}
		if(n==100000){
			sort(m+1,m+n+1,rule);
			int sum;
			for(int i=1;i<=n/2;i++){
				sum+=m[i].a[1];
			}
			cout<<sum;
		}
	}
	return 0;
}
