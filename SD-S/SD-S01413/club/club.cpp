#include <bits/stdc++.h>
#define int long long
using namespace std;
struct ayu{
	int a1,a2,a3;
}a[100020];
int x[100020],y[100020],z[100020];
bool cmpx(int i,int j){
	return a[i].a1-max(a[i].a2,a[i].a3)>a[j].a1-max(a[j].a2,a[j].a3);
}
bool cmpy(int i,int j){
	return a[i].a2-max(a[i].a1,a[i].a3)>a[j].a2-max(a[j].a1,a[j].a3);
}
bool cmpz(int i,int j){
	return a[i].a3-max(a[i].a2,a[i].a1)>a[j].a3-max(a[j].a2,a[j].a1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		int ans=0;
		x[0]=y[0]=z[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			ans+=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].a1>a[i].a2 && a[i].a1>a[i].a3) x[++x[0]]=i;
			else if(a[i].a2>a[i].a1 && a[i].a2>a[i].a3) y[++y[0]]=i;
			else if(a[i].a3>a[i].a1 && a[i].a3>a[i].a2) z[++z[0]]=i;
		}
		if(x[0]<=n/2 && y[0]<=n/2 && z[0]<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		if(x[0]>n/2){
			sort(x+1,x+1+x[0],cmpx);
			for(int i=n/2+1;i<=x[0];i++) ans-=a[x[i]].a1-max(a[x[i]].a2,a[x[i]].a3);
		}else if(y[0]>n/2){
			sort(y+1,y+1+y[0],cmpy);
			for(int i=n/2+1;i<=y[0];i++) ans-=a[y[i]].a2-max(a[y[i]].a1,a[y[i]].a3);
		}else if(z[0]>n/2){
			sort(z+1,z+1+z[0],cmpz);
			for(int i=n/2+1;i<=z[0];i++) ans-=a[z[i]].a3-max(a[z[i]].a2,a[z[i]].a1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
