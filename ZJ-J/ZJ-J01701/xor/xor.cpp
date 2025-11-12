#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int sum[N];
struct Node{
	int l;
	int r;
	int len;
}s[N];
bool cmp(Node a,Node b){
	return a.r<b.r;
}
int q[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int cnt=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if( (sum[r]^sum[l-1]) ==k){
				s[cnt].l=l;
				s[cnt].r=r;
				s[cnt].len=r-l+1;
				cnt++;
				break;
			}
		}
	}
	sort(s,s+cnt,cmp); 
	int mlen=0;
	for(int i=0;i<cnt;i++){
		int p=lower_bound(q,q+mlen,s[i].l-1)-q;
		if(p+1>mlen&&q[p]<s[i].l){
			q[p+1]=s[i].r;
			mlen=p+1;
			continue;
		}
		if(q[p+1]>s[i].r){
			q[p+1]=s[i].r;
		}
	}
	cout<<mlen;
	return 0;
}
