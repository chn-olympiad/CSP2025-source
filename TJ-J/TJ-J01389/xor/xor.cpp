#include <bits/stdc++.h> 

using namespace std;
int a[500005];
struct node{
	int l;
	int r;
}px[500005];
bool cmp(node pp,node pp1){
	if(pp.l==pp1.l)return pp.r<pp1.r;
	return pp.l<pp1.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=int(a[i]^a[i-1]);//异或前缀和 ，拿不满但能拿部分 
	}
	int p=1;
	for(int le=1;le<=n;le++){
		for(int ri=le;ri<=n;ri++){
			if(int(a[ri]^a[le-1])==k){
				px[p].l=le;
				px[p].r=ri;
				p++;
			}
		}
	}
	sort(px+1,px+p,cmp);
	int ne=0;
	int cnt=0;
	for(int i=1;i<p;i++){
		if(px[i].l>ne){
			cnt++;
			ne=px[i].r;
		}
	}
	cout<<cnt;
	return 0;
}
