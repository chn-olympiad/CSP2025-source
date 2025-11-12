#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define l first
#define r second
using namespace std;
const int N=5e5+5,M=2e6+5;
int a[N],pre[N],suf[N];
vector<PII> v;
vector<int> tong[M];
bool cmp(PII a,PII b){
	if(a.r!=b.r) return a.r<b.r;
	return a.l>b.l;
}
bool cheak(int i,int x,int mid){
	if(i+1<=tong[x][mid]-1) return 1;
	return 0;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	pre[0]=0;
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
	suf[n+1]=0;
	tong[0].push_back(n+1);
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]^a[i];
		tong[suf[i]].push_back(i);
	}
	int sum=pre[n];
	int cnt=0;
	for(int i=0;i<=n;i++){
		int x=sum^pre[i]^k;
		int l=0,r=tong[x].size()-1;
		while(l<r){
			int mid=(l+r+1)/2;
			if(cheak(i,x,mid)) l=mid;
			else r=mid-1;
		}
		if(l<=r&&cheak(i,x,l)){
			cnt++;
			v.push_back({i+1,tong[x][l]-1});
		}
	}
	sort(v.begin(),v.end(),cmp);
	int lst=0,ans=0;
	for(int i=0;i<cnt;i++){
		if(v[i].l>lst){
			ans++;
			lst=v[i].r;
		}
	}
	cout<<ans;
	return 0;
}
