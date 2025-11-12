#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005],mx[500005],n,k;
vector<int> vec[1050000];
struct node{
	int l,r;
}a2[1000005];
bool cmp(node a1,node a2){
	return a1.r<a2.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vec[0].push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];sum[i]=sum[i-1]^a[i];
		vec[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int j=sum[i]^k;
		if(vec[j].size()==0) continue;
		int it=lower_bound(vec[j].begin(),vec[j].end(),i)-vec[j].begin();it--;
		if(it==-1) continue;
		mx[i]=vec[j][it]+1;
	}
	int len=0;
	for(int i=1;i<=n;i++) if(mx[i]!=0) a2[++len]=node{mx[i],i};
	sort(a2+1,a2+1+len,cmp);
	int ans=0,maxr=0;
	for(int i=1;i<=n;i++){
		if(a2[i].l>maxr){
			ans++;maxr=a2[i].r;
		}
	}
	cout<<ans;
	return 0;
}
