#include<iostream>
#include<algorithm>
#include<vector>

struct vv{
	long long x;
	long long y;
}f[500005]={0};

using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int gg=0;
	int n,k;
	cin>>n>>k;
	int a[500005]={0};
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int temp=a[i];
		if(temp==k){
			f[gg].x=i;
			f[gg].y=i;
			gg++;
			continue;
		}
		for(int j=i+1;j<=n;++j){
			temp^=a[j];
			if(temp==k){
				f[gg].x=i;
				f[gg].y=j;
				gg++;
				break;
			}
		}
	}
//	sort(f,f+n,sover1);
//	sort(f,f+n,sover2);
	int temp=0;
	for(int i=0;i<gg;++i){
		if(f[i].x>temp){
			ans++;
			temp=f[i].y;
		}
	}
	cout<<ans;
	return 0;
}
