#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005];
vector<int>t[2200005];
struct node{int l,r;};
vector<node>vec;
bool cmp(node x,node y){return x.r<y.r;}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],f[i]=f[i-1]^a[i];
	for(int i=n;i>=1;i--)t[f[i]].push_back(i);
	for(int i=1;i<=n;i++)
	{
		int tp=k^f[i-1],loc=-1;
		if(t[tp].size()>0)vec.push_back(node{i,t[tp][t[tp].size()-1]});
		t[f[i]].pop_back();
	}
	sort(vec.begin(),vec.end(),cmp);
	if(vec.size()==0){cout<<"0\n";return 0;}
	int ans=0,lst=0;
	for(node i:vec)if(i.l>lst)ans++,lst=i.r;
	cout<<ans<<"\n";
	return 0;
}
//CSP RP++
