#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e5+5;

int n,a[N],b[N],c[N];
vector<int>va,vb,vc;
int cnta,cntb,cntc,ans;

void solve(){
	cin>>n;
	cnta=cntb=cntc=ans=0;
	va.clear();vb.clear();vc.clear();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>=b[i]&&a[i]>=c[i])
			cnta++,ans+=a[i],
			va.push_back(min(a[i]-b[i],a[i]-c[i]));
		else if(b[i]>=a[i]&&b[i]>=c[i])
			cntb++,ans+=b[i],
			vb.push_back(min(b[i]-a[i],b[i]-c[i]));
		else 
			cntc++,ans+=c[i],
			vc.push_back(min(c[i]-a[i],c[i]-b[i]));
	}
	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());
	sort(vc.begin(),vc.end());
	for(int i=0;i<cnta-n/2;i++)ans-=va[i];
	for(int i=0;i<cntb-n/2;i++)ans-=vb[i];
	for(int i=0;i<cntc-n/2;i++)ans-=vc[i];
	cout<<ans<<"\n";
	return;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}