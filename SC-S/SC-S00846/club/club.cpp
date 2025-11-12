#include<bits/stdc++.h>
using namespace std;
int a[101010],b[101010],c[101010],d[101010];
int f1[101010],f2[101010],f3[101010];
vector<int> tmp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin>>n;
		tmp.clear();
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++){
			int maxn=max({a[i],b[i],c[i]});
			int minn=min({a[i],b[i],c[i]});
			int mid=a[i]+b[i]+c[i]-maxn-minn;
			d[i]=maxn-mid;
			if(maxn==a[i]) f1[++cnt1]=i;
			if(maxn==b[i]) f2[++cnt2]=i;
			if(maxn==c[i]) f3[++cnt3]=i;
			ans+=maxn;
		}
		if(cnt1>n/2){
			int s=cnt1-n/2;
			for(int i=1;i<=cnt1;i++) tmp.push_back(d[f1[i]]);
			sort(tmp.begin(),tmp.end());
			for(int i=0;i<s;i++) ans-=tmp[i];
		}
		else if(cnt2>n/2){
			int s=cnt2-n/2;
			for(int i=1;i<=cnt2;i++) tmp.push_back(d[f2[i]]);
			sort(tmp.begin(),tmp.end());
			for(int i=0;i<s;i++) ans-=tmp[i];
		}
		else if(cnt3>n/2){
			int s=cnt3-n/2;
			for(int i=1;i<=cnt3;i++) tmp.push_back(d[f3[i]]);
			sort(tmp.begin(),tmp.end());
			for(int i=0;i<s;i++) ans-=tmp[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}