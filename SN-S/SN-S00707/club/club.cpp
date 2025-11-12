#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
int t,n;
struct node {
	int data,id;
};
bool cmp(node a,node b) {
	if(a.data==b.data)return a.id<b.id;
	return a.data>b.data;
}
int cnt1=0,cnt2=0;
int calc(vector< vector<node> > a) {
	int ans=0;
	int tmp[3]= {0,0,0};
	for(int j=0; j<n; ++j) {
		ans+=a[j][0].data;
		tmp[a[j][0].id]++;
		if(tmp[a[j][0].id]>n/2) {
			tmp[a[j][0].id]--;
			ans-=a[j][0].data;
			a[j][0].data=0;
			sort(a[j].begin(),a[j].end(),cmp);
			ans+=a[j][0].data;
			tmp[a[j][0].id]++;
		}
	}
	return ans;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		vector< vector<node> > a(n,vector<node>(3));
		for(int i=0; i<n; ++i) {
			for(int j=0; j<3; ++j) {
				cin>>a[i][j].data;
				a[i][j].id=j;
			}
			sort(a[i].begin(),a[i].end(),cmp);
		}
		cout<<calc(a)<<'\n';
	}
	return 0;
}
