#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005],b[100005],c[100005],d[100005];
int ans;
void solve() {
	cin>>n;
	ans=0;
	int u,v,w;
	u=v=w=0;
	for(int i=1; i<=n; i++) {
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]>=b[i]&&a[i]>=c[i]){
			d[i]=1;
			u++;
			ans+=a[i];
		}
		else if(b[i]>a[i]&&b[i]>=c[i]){
			d[i]=2;
			v++;
			ans+=b[i];
		}
		else d[i]=3,ans+=c[i],w++;
	}
	vector<int>vec;
	int need=0;
	if(u>n/2){
		for(int i=1;i<=n;i++){
			if(d[i]==1){
				vec.push_back(min(a[i]-b[i],a[i]-c[i]));
			}
		}
		need=u-n/2;
	}
	if(v>n/2){
		for(int j=1;j<=n;j++){
			if(d[j]==2){
				vec.push_back(min(b[j]-a[j],b[j]-c[j]));
			}
		}
		need=v-n/2;
	}
	if(w>n/2){
		for(int j=1;j<=n;j++){
			if(d[j]==3){
				vec.push_back(min(c[j]-a[j],c[j]-b[j]));
			}
		}
		need=w-n/2;
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<need;i++){
		ans-=vec[i];
	}
	cout<<ans<<endl;
	return ;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}
