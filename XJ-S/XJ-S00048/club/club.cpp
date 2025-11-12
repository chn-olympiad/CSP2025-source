#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
struct aaa{
	long long x,y,z;
}a[N];
bool cmp(aaa x,aaa y){
	if(x.x==y.x){
		if(x.y==y.y){
			return x.z>y.z;
		}else{
			return x.y>y.y;
		}
	}else return x.x>y.x;
}
void aaa(){
	long long n,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+n+1,cmp);
	int b[5],awa=n/2;
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++){
		long long cnt=max({a[i].x,a[i].y,a[i].z});
		if(cnt==a[i].x){
			if(b[1]+1<=awa){
				ans+=a[i].x;
				b[1]+=1;
			}else{
				if(a[i].y>=a[i].z){
					if(b[2]+1<=awa){
						ans+=a[i].y;
						b[2]+=1;
					}else{
						if(b[3]+1<=awa){
							ans+=a[i].z;
							b[3]+=1;
						}
					}
				}
			}
		}else if(cnt==a[i].y){
			if(b[2]+1<=awa){
				ans+=a[i].y;
				b[2]+=1;
			}else{
				if(a[i].x>=a[i].z){
					if(b[1]+1<=awa){
						ans+=a[i].x;
						b[1]+=1;
					}else{
						if(b[3]+1<=awa){
							ans+=a[i].z;
							b[3]+=1;
						}
					}
				}
			}
		}else if(cnt==a[i].z){
			if(b[3]+1<=awa){
				ans+=a[i].z;
				b[3]+=1;
			}else{
				if(a[i].x>=a[i].y){
					if(b[1]+1<=awa){
						ans+=a[i].x;
						b[1]+=1;
					}else{
						if(b[2]+1<=awa){
							ans+=a[i].y;
							b[2]+=1;
						}
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		aaa();
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
