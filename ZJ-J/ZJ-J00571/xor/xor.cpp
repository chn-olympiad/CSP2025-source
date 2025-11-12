#include<bits/stdc++.h>
using namespace std;
const int N=1004;
int n,k,a[N],sum[N];
struct Node{
	int l,r;
	bool operator<(const Node&b)const{
		return r<b.l;
	}
};
Node vec[N*N];int len;
int And(Node a,Node b){
	if(a.l<=b.l&&a.r>=b.l) return 0;
	if(b.l<=a.l&&b.r>=a.l) return 0;
	return 1;
}
bool cmp(Node a,Node b){
	return a.l==b.l?a.r<b.r:a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i],sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k) len++,vec[len]={i,j};
		}
	}
	if(len==0){cout<<0;return 0;}
	sort(vec+1,vec+1+len,cmp);
	int ans=1,p=0,Min=INT_MAX;
	for(int i=1;i<=len;i++){
		if(vec[i].r<Min) Min=vec[i].r,p=i;
	}
	Node res=*upper_bound(vec+1,vec+1+len,vec[p]);
	while(res.l&&res.r){
		ans++;
		res=*upper_bound(vec+1,vec+1+len,res);
	}
	cout<<ans;
	return 0;
}