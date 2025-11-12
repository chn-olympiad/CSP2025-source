#include<bits/stdc++.h>
using namespace std;
int n;
struct nn{
    int x;
    int y;
    int z;
    int xx;
}a[100005];
bool cmp(nn x,nn y){
	return x.xx<y.xx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int nn=n/2;
		long long ans=0;
		int l=0,ll=0,lll=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y and a[i].x>=a[i].z){
				l++;
				a[i].xx=a[i].x-max(a[i].y,a[i].z);
				ans+=a[i].x;
			}
			else if(a[i].y>=a[i].x and a[i].y>=a[i].z){
				ll++;
				a[i].xx=a[i].y-max(a[i].x,a[i].z);
				ans+=a[i].y;
			}
			else if(a[i].z>=a[i].x and a[i].z>=a[i].y){
				lll++;
				a[i].xx=a[i].z-max(a[i].x,a[i].y);
				ans+=a[i].z;
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y and a[i].x>=a[i].z and l>nn){
				l--;
				ans-=a[i].xx;
				if(a[i].y>=a[i].z and ll<nn){
					ll++;
				}
				else if(a[i].y<a[i].z and lll>=nn){
					ll++;
				}
				else lll++;
			}
			else if(a[i].y>=a[i].x and a[i].y>=a[i].z and ll>nn){
				ll--;
				ans-=a[i].xx;
				if(a[i].x>=a[i].z and l<nn){
					l++;
				}
				else if(a[i].z>a[i].x and lll>=nn){
					l++;
				}
				else lll++;
			}
			else if(a[i].z>=a[i].x and a[i].z>=a[i].y and lll>nn){
				lll--;
				ans-=a[i].xx;
				if(a[i].x>=a[i].y and l<nn){
					l++;
				}
				else if(a[i].y>a[i].x and ll>=nn){
					l++;
				}
				else ll++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
