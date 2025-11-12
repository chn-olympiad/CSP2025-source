#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int T,n;
struct node{
	int x,y,z,s;
}a[N];
bool ccmp(node a,node b){
	return a.x>b.x;
}
bool cmp(node a,node b){
	return a.s>b.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>T;
	while(T--){
		cin>>n;
		int cx=n/2,cy=n/2,cz=n/2;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0) f=0;
			if(a[i].x<=a[i].y&&a[i].x<=a[i].z){
				a[i].s=abs(a[i].y-a[i].z);
			}else if(a[i].y<=a[i].x&&a[i].y<=a[i].z){
				a[i].s=abs(a[i].x-a[i].z);
			}else{
				a[i].s=abs(a[i].x-a[i].y);
			}
		}
		ll ans=0;
		if(f){
			sort(a+1,a+1+n,ccmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if(cx){
					ans+=a[i].x;
					cx--;
				}else{
					if(a[i].y>a[i].z)ans+=a[i].y;
					else ans+=a[i].z;
				}
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				if(cy){
					ans+=a[i].y;
					cy--;
				}else{
					if(a[i].x>a[i].z)ans+=a[i].x;
					else ans+=a[i].z;
				}
			}else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
				if(cz){
					ans+=a[i].z;
					cz--;
				}else{
					if(a[i].y>a[i].x)ans+=a[i].y;
					else ans+=a[i].x;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
