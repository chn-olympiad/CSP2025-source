#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
struct node{
	int a,b,c;
	int M1,M2,j1,j2,j3;
}n[N];

bool cmp(node a, node b){
	return a.M1-a.M2 > b.M1-b.M2;
}
int t,m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> m;
		int m1=m/2;
		int ca=0,cb=0,cc=0;
		long long ans=0;
		for(int i=1;i<=m;i++){
			cin >> n[i].a >> n[i].b >> n[i].c;
			n[i].M1=max(n[i].a,max(n[i].b,n[i].c));
			if(n[i].a>=n[i].b&&n[i].b>=n[i].c){
				n[i].M2=n[i].b;
				n[i].j1=1,n[i].j2=2,n[i].j3=3;
			} 
			if(n[i].c>=n[i].b&&n[i].b>=n[i].a){
				n[i].M2=n[i].b;
				n[i].j1=3,n[i].j2=2,n[i].j3=1;
			} 
			if(n[i].b>=n[i].a&&n[i].a>=n[i].c){
				n[i].M2=n[i].a;
				n[i].j1=2,n[i].j2=1,n[i].j3=3;
			} 
			if(n[i].c>=n[i].a&&n[i].a>=n[i].b){
				n[i].M2=n[i].a;
				n[i].j1=3,n[i].j2=1,n[i].j3=2;
			} 
			if(n[i].a>=n[i].c&&n[i].c>=n[i].b){
				n[i].M2=n[i].c;
				n[i].j1=1,n[i].j2=3,n[i].j3=2;
			}
			if(n[i].b>=n[i].c&&n[i].c>=n[i].a){
				n[i].M2=n[i].a;
				n[i].j1=2,n[i].j2=3,n[i].j3=1;
			}
		}
		sort(n+1,n+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(n[i].j1==1){
				if(ca<m1){
					ans+=n[i].a;
					ca++;
					
				}else{
					if(n[i].j2==2){
						ans+=n[i].b;
						cb++;
					
					}else{
						ans+=n[i].c;
						cc++;
						
					}
				}
			}
			if(n[i].j1==2){
				if(cb<m1){
					ans+=n[i].b;
					cb++;
					
				}else{
					if(n[i].j2==1){
						ans+=n[i].a;
						ca++;
						
					}else{
						ans+=n[i].c;
						cc++;
						
					}
				}
			}
			if(n[i].j1==3){
				if(cc<m1){
					ans+=n[i].c;
					cc++;
					
				}else{
					if(n[i].j2==1){
						ans+=n[i].a;
						ca++;
						
					}else{
						ans+=n[i].b;
						cb++;
					
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
