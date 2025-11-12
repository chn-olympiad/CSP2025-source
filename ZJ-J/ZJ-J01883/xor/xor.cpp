#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7,M=300,inf=1e18,mod=1e9+7;
struct Node{
	int s,t;
	int v;
	int lo;
}seg[N];
bool cmp(Node x,Node y){
	return x.lo>y.lo;
}
int vis[N];
int n,k,a[N],xoreb[N],c,ch[N],b[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xoreb[i]=xoreb[i-1]^a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int len=r-l+1;
			int val=xoreb[r]^xoreb[l];
			if(val!=k)continue;
			seg[++c].v=val;
			seg[c].s=l;
			seg[c].t=r;
			seg[c].lo=len;
		}
	}
	sort(seg+1,seg+c+1,cmp);
	for(int i=1;i<=c;i++){
		ch[seg[i].s]++;
		ch[seg[i].t+1]--;
//		for(int j=seg[i].s;j<=seg[i].t;j++){
//			vis[j]++;
//		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+ch[i];
	}
	int ans=c;
	for(int i=1;i<=c;i++){
		bool flg=true;
		for(int j=1;j<=n;j++){
			if(b[j]>1){
				flg=false;
				if(seg[i].s<=j&&seg[i].t>=j){
					ans--;
					ch[seg[i].s]--;
					ch[seg[i].t+1]++;
					break;
				}
			}
		}
		if(flg){
			cout<<ans;
			break;
		}
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]+ch[i];
		}
	}
	return 0;
}
/*
4 2
2 1 0 3
*/
