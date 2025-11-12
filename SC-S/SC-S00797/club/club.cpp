#include<bits/stdc++.h>
using namespace std;
int mxn(int i1,int i2,int i3){
	if(i1>i2&&i1>i3) return 1;
	if(i2>i1&&i2>i3) return 2;
	return 3;
}
int mnn(int i1,int i2,int i3){
	if(i1<i2&&i1<i3) return 1;
	if(i2<i1&&i2<i3) return 2;
	return 3;
}
struct mem{
	int i[3];
	int maxn=mxn(i[1],i[2],i[3]),minn=mnn(i[1],i[2],i[3]),midn=6-maxn-minn; //maxn:最满意的部门,c:差 
	int c=maxn-minn;
	bool operator <(const mem &x){
		return c>x.c;
	}
};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int o[3];
		int n2=n/2;
		long long ans=0;
		vector<mem> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i].i[1]>>a[i].i[2]>>a[i].i[3];
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			cout<<a[i].i[1]<<a[i].i[2]<<a[i].i[3];
		}
		for(int i=0;i<n;i++){
			int mx=a[i].maxn,md=a[i].midn,mn=a[i].minn;
			if(o[mx]<n2){
				o[mx]++,ans+=a[i].i[mx];
			}
			else if(o[md]<n2){
				o[md]++,ans+=a[i].i[md];
			}
			else{
				o[mn]++,ans+=a[i].i[mn];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}