#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,ans,a[500005],sum[500005];
struct node{
	int l,r;
}b[1000005];
vector<int> v[1100000];
bool cmp(node x,node y){
	if(x.r==y.r){
		return x.l<y.l;
	}
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]^a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((sum[j]^sum[i-1])==k){
					b[++cnt]={i,j};
				}
			}
		}
		sort(b+1,b+cnt+1,cmp);
		int rrr=0;
		for(int i=1;i<=cnt;i++){
			if(b[i].l>rrr){
				ans++;
				rrr=b[i].r;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		v[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			b[++cnt]={i,i};
			continue;
		}
		int x=k^sum[i-1];
		if(v[x].empty()) continue;
		int len=v[x].size(),l=0,r=len-1;
		while(l<r){
			int mid=(l+r)/2;
			if(v[x][mid]>i) r=mid;
			else l=mid+1;
		}
		if(v[x][l]<=i) continue;
		b[++cnt]={i,v[x][l]};
////		cout<<i<<" "<<x<<endl;
//		int len=v[x].size();
//		for(int j=0;j<len;j++){
////			cout<<v[x][j]<<" ";
//			if(v[x][j]>i){
//				b[i]={i,v[x][j]};
//				break;
//			}
//		}
////		cout<<endl;
	}
	sort(b+1,b+cnt+1,cmp);
	int rrr=0;
	for(int i=1;i<=cnt;i++){
//		cout<<b[i].l<<" "<<b[i].r<<endl;
		if(b[i].l>rrr){
			ans++;
			rrr=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}