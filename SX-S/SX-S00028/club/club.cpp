#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,l1,l2,l3,x[100005],y[100005],z[100005];
struct node{
	int mx,mc,id;
}a[100005],k[100005];
bool cmp(node x,node y){
	return x.mc<y.mc;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--){
		cin>>n;
		l1=l2=l3=0;
		for (int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			a[i].mx=max({x[i],y[i],z[i]});
   			if (a[i].mx==x[i])a[i].mc=a[i].mx-max(y[i],z[i]),l1++;
   			else if (a[i].mx==y[i])a[i].mc=a[i].mx-max(x[i],z[i]),l2++;
   			else if (a[i].mx==z[i])a[i].mc=a[i].mx-max(y[i],x[i]),l3++;
   			a[i].id=i;
		}
		int o=0,len=0;
		if (l1>n/2)o=1;
		if (l2>n/2)o=2;
		if (l3>n/2)o=3;
		if (o){
			for (int i=1;i<=n;i++){
//				cout<<a[i].mx<<' '<<o<<'\n';
				if (a[i].mx==x[i]&&o==1)k[++len]=a[i];
				if (a[i].mx==y[i]&&o==2)k[++len]=a[i];
				if (a[i].mx==z[i]&&o==3)k[++len]=a[i];
			}
			sort(k+1,k+1+len,cmp);
//			cout<<len<<'\n';
			for (int i=1;i<=len-n/2;i++){
//				cout<<k[i].id<<'\n';
				a[k[i].id].mx-=a[k[i].id].mc;
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			ans+=a[i].mx;
		}
		cout<<ans<<'\n';
	}
	return 0;
}