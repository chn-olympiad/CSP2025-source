#include<bits/stdc++.h>
using namespace std;
struct f{
	int x,y,z,d,dd,r,ca;
}a[110000];
int w[11000];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		int n,f=0,g=0,h=0;
		cin>>n;
		int s=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				f++;a[i].d=1;a[i].dd=a[i].x;a[i].r=max(a[i].y,a[i].z);
			}
			else if(a[i].y>a[i].x&&a[i].y>a[i].z){
				g++;a[i].d=2;a[i].dd=a[i].y;a[i].r=max(a[i].x,a[i].z);
			}
			else if(a[i].z>a[i].x&&a[i].z>a[i].y){
				h++;a[i].d=3;a[i].dd=a[i].z;a[i].r=max(a[i].x,a[i].y);
			}
			else if(a[i].x>a[i].z&&a[i].x==a[i].y){
				a[i].dd=a[i].x;
			}
			else if(a[i].x>a[i].y&&a[i].x==a[i].z){
				a[i].dd=a[i].x;
			}
			else if(a[i].y>a[i].x&&a[i].z==a[i].y){
				a[i].dd=a[i].y;
			}
			else if(a[i].x=a[i].z&&a[i].x==a[i].y){
				a[i].dd=a[i].x;
			}
		}
		for(int i=1;i<=n;i++){
				ans+=a[i].dd;
		}
		int v=0,c=0;
		if(f>s)v=1,c=f-s;
		else if(g>s)v=2,c=g-s;
		else if(h>s)v=3,c=h-s;
		
		else{
			cout<<ans<<endl;
			continue;
		}
			int j=0;
		for(int i=1;i<=n;i++){
		
			if(a[i].d==v){
				j++;
				w[j]=a[i].dd-a[i].r;
			}
		}
		sort(w+1,w+1+j);
		for(int i=1;i<=c;i++){
			ans-=w[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

