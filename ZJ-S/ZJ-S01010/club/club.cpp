#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N],ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		vector<int> va,vb,vc;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			int m=max({a[i],b[i],c[i]});
			ans+=m;
			if(m==a[i]){
				va.push_back(min(m-b[i],m-c[i]));
			}else if(m==b[i]){
				vb.push_back(min(m-a[i],m-c[i]));
			}else{
				vc.push_back(min(m-a[i],m-b[i]));
			}
		}
		if((int)va.size()>n/2){
			sort(va.begin(),va.end());
			for(int i=0;i<(int)va.size()-n/2;++i) ans-=va[i];
		}else if((int)vb.size()>n/2){
			sort(vb.begin(),vb.end());
			for(int i=0;i<(int)vb.size()-n/2;++i) ans-=vb[i];
		}else if((int)vc.size()>n/2){
			sort(vc.begin(),vc.end());
			for(int i=0;i<(int)vc.size()-n/2;++i) ans-=vc[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
