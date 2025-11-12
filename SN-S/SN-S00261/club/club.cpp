#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int f,s,t;
}a[100010];
bool cmp(node a,node b){
	return a.f>b.f;	
}
bool check(int i,int j,int k,int l){
	if(i==j&&j==k){
		return false;
	}
	if(i==k&&k==l){
		return false;
	}
	if(i==j&&j==l){
		return false;
	}
	if(j==k&&k==l){
		return false;
	}
	return true;
}
int T,n;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					int tans=0;
					if(i!=j){
						if(i==1){
							tans+=a[1].f;
						}
						if(i==2){
							tans+=a[1].s;
						}
						if(i==3){
							tans+=a[1].t;
						}
						if(j==1){
							tans+=a[2].f;
						}
						if(j==2){
							tans+=a[2].s;
						}
						if(j==3){
							tans+=a[2].t;
						}
					}
					ans=max(ans,tans);
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==4){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							int tans=0;
							if(check(i,j,k,l)){
								if(i==1){
									tans+=a[1].f;
								}
								if(i==2){
									tans+=a[1].s;
								}
								if(i==3){
									tans+=a[1].t;
								}
								if(j==1){
									tans+=a[2].f;
								}
								if(j==2){
									tans+=a[2].s;
								}
								if(j==3){
									tans+=a[2].t;
								}
								if(k==1){
									tans+=a[3].f;
								}
								if(k==2){
									tans+=a[3].s;
								}
								if(k==3){
									tans+=a[3].t;
								}
								if(l==1){
									tans+=a[4].f;
								}
								if(l==2){
									tans+=a[4].s;
								}
								if(l==3){
									tans+=a[4].t;
								}
							}
							ans=max(ans,tans);
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].f;
		}		
		cout<<ans<<endl;
	}	
	return 0;
} 
