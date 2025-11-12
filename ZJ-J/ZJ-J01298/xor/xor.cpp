#include <bits/stdc++.h>
using namespace std;

int a[1000005];
struct node{
	int l,r;
}anss[100005];
bool cmp(node a,node b){
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int maxx=0;
	int minn=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	if(maxx==minn&&maxx==1&&k==0){
		cout<<n/2<<endl;
		return 0;
	}
	else if(maxx==minn&&maxx==1&&k==1){
		cout<<n<<endl;
		return 0;
	}
	if(maxx==1&&minn==0){
		if(k==1){
			int sum0=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
					if(sum0==1) sum0=0;
				}
				if(a[i]==0){
					sum0++;
					if(sum0==2){
						ans++;
						sum0=0;
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
		if(k==0){
			int sum1=0;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					if(sum1==1) sum1=0;
				}
				if(a[i]==1){
					sum1++;
					if(sum1==2){
						ans++;
						sum1=0;
					}
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	int cc=1;
	for(int i=1;i<=n;i++){
		int hh=a[i];
		if(hh==k){
			anss[cc].l=i;
			anss[cc].r=i;
			cc++;		
		}
		for(int j=i+1;j<=n;j++){
			hh^=a[j];
			if(hh==k){
				anss[cc].l=i;
				anss[cc].r=j;
				cc++;		
			}
		}
	}
	sort(anss+1,anss+cc,cmp);
	cout<<cc/2<<endl;
	return 0;
}
