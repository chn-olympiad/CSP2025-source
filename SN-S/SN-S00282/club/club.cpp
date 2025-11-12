#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005],a1[100005],b1[100005],c1[100005],a2,b2,c2;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		ans=0,a2=0,b2=0,c2=0;
		for(int i=1;i<=n;i++) a1[i]=0,b1[i]=0,c1[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]) ans+=a[i],a1[i]++,a2++;
			else if(b[i]>=a[i]&&b[i]>=c[i]) ans+=b[i],b1[i]++,b2++;
			else ans+=c[i],c1[i]++,c2++;
		}
		if(a2>n/2){
			a2-=n/2;
			vector<int> v;
			for(int i=1;i<=n;i++){
				if(a1[i]){
					v.push_back(a[i]-max(b[i],c[i]));
				}
			}
			sort(v.begin(),v.end());
			for(int i=0;i<a2;i++) ans-=v[i];
		}
		if(b2>n/2){
			b2-=n/2;
			vector<int> v;
			for(int i=1;i<=n;i++){
				if(b1[i]){
					v.push_back(b[i]-max(a[i],c[i]));
				}
			}
			sort(v.begin(),v.end());
			for(int i=0;i<b2;i++) ans-=v[i];
		}
		if(c2>n/2){
			c2-=n/2;
			vector<int> v;
			for(int i=1;i<=n;i++){
				if(c1[i]){
					v.push_back(c[i]-max(b[i],a[i]));
				}
			}
			sort(v.begin(),v.end());
			for(int i=0;i<c2;i++) ans-=v[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
