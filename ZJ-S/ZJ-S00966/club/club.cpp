#include<bits/stdc++.h>
using namespace std;
const int S=100010;
int a[S][3],d[S][2],e[S],p[3];
long long ans;
int check(int x,int y,int z){
	if(x==max(x,max(y,z))) return 0;
	if(y>=z) return 1;
	return 2;
}
int check2(int x,int y,int z,int id){
	if(id==0){
		if(y>z) return 1;
		return 2;
	}
	if(id==1){
		if(x>z) return 0;
		return 2;
	}
	if(id==2){
		if(y>x) return 1;
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,n,h;cin>>T;
	while(T--){
		p[0]=0;p[1]=0;p[2]=0;ans=0;
		cin>>n;h=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			d[i][0]=check(a[i][0],a[i][1],a[i][2]);
			d[i][1]=check2(a[i][0],a[i][1],a[i][2],d[i][0]);
			p[d[i][0]]++;
			ans+=a[i][d[i][0]];
			e[i]=a[i][d[i][0]]-a[i][d[i][1]];
		}
		if(p[0]>h){
			for(int i=1;i<=n;i++){
				if(d[i][0]!=0) e[i]=INT_MAX;;
			}
			sort(e+1,e+n+1);
			for(int i=1;i<=p[0]-h;i++){
				ans-=e[i];
			}
		}
		if(p[1]>h){
			for(int i=1;i<=n;i++){
				if(d[i][0]!=1) e[i]=INT_MAX;;
			}
			sort(e+1,e+n+1);
			for(int i=1;i<=p[1]-h;i++){
				ans-=e[i];
			}
		}
		if(p[2]>h){
			for(int i=1;i<=n;i++){
				if(d[i][0]!=2) e[i]=INT_MAX;
			}
			sort(e+1,e+n+1);
			for(int i=1;i<=p[2]-h;i++){
				ans-=e[i];
			}
		}
		cout<<ans<<"\n";  
	} 
	return 0;
} 
