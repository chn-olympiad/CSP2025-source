#include<bits/stdc++.h>
using namespace std;
struct node{
	int xx,yy,zz,maxxx,f;
}a[100000];
long long n,t,x,y,z,q,ans;
bool cmpx(node aa,node bb){
	return aa.xx>bb.xx;
}
bool cmpy(node aa,node bb){
	return aa.yy>bb.yy;
}
bool cmpz(node aa,node bb){
	return aa.zz>bb.zz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		q=n/2;
		ans=0;
		x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].xx>>a[i].yy>>a[i].zz;
			a[i].maxxx=max(a[i].xx,a[i].yy);
			a[i].maxxx=max(a[i].maxxx,a[i].zz);
		}
		sort(a+1,a+1+n,cmpx);
		for(int i=1;i<=n;i++){
			if(x<q&&a[i].maxxx==a[i].xx&&a[i].f==0){
				x++;
				a[i].f==0;
				ans+=a[i].xx;				
			}
		}
		sort(a+1,a+1+n,cmpy);
		for(int i=1;i<=n;i++){
			if(y<q&&a[i].maxxx==a[i].yy&&a[i].f==0){
				y++;
				a[i].f==0;
				ans+=a[i].yy;				
			}
		}
		sort(a+1,a+1+n,cmpz);
		for(int i=1;i<=n;i++){
			if(z<q&&a[i].maxxx==a[i].zz&&a[i].f==0){
				z++;
				a[i].f==0;
				ans+=a[i].zz;			
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
