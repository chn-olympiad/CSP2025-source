#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,c[4];
long long ans;
struct Node{
	int o[4],mx,id,m;
}a[N],b[N];
bool cmp(Node a,Node b){
	return a.mx-a.m<b.mx-b.m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ok=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=3;i++) c[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].o[1]>>a[i].o[2]>>a[i].o[3];
			a[i].mx=0;a[i].m=0;
			for(int j=1;j<=3;j++) if(a[i].o[j]>=a[i].mx) a[i].mx=a[i].o[j],a[i].id=j;
			for(int j=1;j<=3;j++) if(a[i].o[j]>=a[i].m && j!=a[i].id) a[i].m=a[i].o[j];
			c[a[i].id]++;
			ans+=1ll*a[i].mx;
			//cout<<a[i].mx<<" "<<a[i].m<<"\n";
		}
		for(int j=1;j<=3;j++){
			if(c[j]>n/2) ok=j;
		}
		if(!ok) cout<<ans<<"\n";
		else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i].id==ok) b[++cnt]=a[i];
			}
			sort(b+1,b+cnt+1,cmp);//cout<<a[1].mx<<"**";
			int i=1;
			while(c[ok]>n/2){//cout<<ans<<"&&";
				ans=ans-1ll*(b[i].mx-b[i].m);
				c[ok]--;
				i++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}