#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{int l,r;}a[500005];
bool cmp(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	else return x.l>y.l;
}
int n,k,sum[500005],len;
map<int,vector<int> >mp;
map<int,bool>v;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;scanf("%lld",&x);
		sum[i]=sum[i-1]^x;
		mp[sum[i]].push_back(i);
		v[sum[i]]=1;
	}
	mp[0].push_back(0);
	v[0]=1;
	for(int i=1;i<=n;i++){
		if(v[k^sum[i]]==0)continue;
		vector<int>t=mp[k^sum[i]];
		int maxx=-1;
		for(int j=0;j<t.size();j++){
			if(t[j]<i)maxx=max(t[j],maxx);
		}
		if(maxx!=-1){
			a[++len].l=maxx+1;
			a[len].r=i;
		}
	}
	sort(a+1,a+len+1,cmp);
	int last=0,ans=0;
	for(int i=1;i<=len;i++){
		//cout<<a[i].l<<" "<<a[i].r<<endl;
		if(a[i].l>last){
			last=a[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
