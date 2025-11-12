#include <bits/stdc++.h>
using namespace std;
struct S{
	int x,y,z;
}a[100010];
int t,n,m,ans,ans2;

bool cmp(S a,S b){
	if(a.x==b.x){
		return a.y>b.y;
	}
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int xx,yy,zz;
			cin>>xx>>yy>>zz;
			a[i].x=xx;
			a[i].y=yy;
			a[i].z=zz;
		}
		sort(a+1,a+n+1,cmp);
		/*for(int i=1;i<=n;i++){
			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
		}*/
		for(int i=1;i<=n/2;i++){
			ans+=a[i].x;
			//cout<<ans<<" ";
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=a[i].y;
			//cout<<ans<<" ";
		}
		cout<<ans<<endl;
		ans=0;
		memset(a,0,sizeof(a));
	}
	
	
	return 0;
}
