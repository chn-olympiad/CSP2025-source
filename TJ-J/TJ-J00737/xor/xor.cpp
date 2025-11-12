#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,k;
int a[N];
int cnt;
struct Node{
	int l;
	int r;
};
Node res[N];
bool vis[N];
bool cmp(Node a,Node b){
	return (a.r-a.l+1)<(b.r-b.l+1);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int tot=0;
	for(int l=1;l<=n;++l){
		int num=0;
		for(int r=l;r<=n;++r){
			num^=a[r];
			if(num==k){
				Node a;
				a.l=l;
				a.r=r;
				res[++tot]=a;
				++cnt;
//				cout<<l<<" "<<r<<"\n";
				break;
			}
		}
	}
	sort(res+1,res+tot+1,cmp);
	for(int i=1;i<=tot;++i){
		for(int j=res[i].l;j<=res[i].r;++j){
			if(vis[j]){
				--cnt;
				break;
			}
			vis[j]=true;
		}
	}
	cout<<cnt;
	return 0;
}
