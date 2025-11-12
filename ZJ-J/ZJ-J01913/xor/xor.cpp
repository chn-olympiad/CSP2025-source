#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,k,a[MAXN],p[MAXN],ans=0;
struct node{
	long long l,r;
}seg[MAXN];
bool flag[MAXN];
bool cmp(node a,node b){
	if((a.r-a.l)!=(b.r-b.l)){
		return (a.r-a.l)<(b.r-b.l);
	}
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]^a[i];
	}
	int x=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((p[j]^p[i-1])==k){
				seg[i].l=i;
				seg[i].r=j;
				break;
			}
		}
		if(seg[i].l==0){	
			seg[i].r=1e9;
			x++;
		}
	}
	sort(seg+1,seg+n+1,cmp);
	for(int i=1;i<=n-x;i++){
		bool ok=1;
		for(int j=seg[i].l;j<=seg[i].r;j++){
			if(flag[j]){
				ok=0;
				break;
			}
		}
		if(ok){
			//cout<<seg[i].l<<" "<<seg[i].r<<endl;
			ans++;
			for(int j=seg[i].l;j<=seg[i].r;j++){
				flag[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
2 1 0 3
*/