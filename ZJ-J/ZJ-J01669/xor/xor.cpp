#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5500;
int a[N];
int maxn;
struct node{
	int l,r;
	friend bool operator < (node x,node y){
		return x.r<y.l;
	}
}b[N];
int cnt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int sum=a[i];
		if(sum==k){
			cnt++;
			b[cnt].l=i;
			b[cnt].r=i;
		}
		for(int j=i+1;j<=n;j++){
			sum=sum^a[j];
			if(sum==k){
				cnt++;
				b[cnt].l=i;
				b[cnt].r=j;
			}
		}
	}
	/*for(int i=1;i<=cnt;i++){
		cout<<b[i].l<<" "<<b[i].r<<"\n";
	}*/
	for(int i=1;i<=cnt;i++){
		int ans=1;
		int x=b[i].r;
		for(int j=i+1;j<=cnt;j++){
			if(x<b[j].l){
			  ans++;
			  x=b[j].r;
			}
		}
		if(ans!=0)
		  maxn=max(maxn,ans);
	}
	cout<<maxn<<"\n";
	return 0;
}
/*

*/
