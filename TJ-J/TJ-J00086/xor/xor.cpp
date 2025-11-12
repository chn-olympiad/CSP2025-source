#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPJ std
LANH AK CSPJ;
typedef long long ll;
int n,k;
int a[500009],dp[500009];
struct nodess{
	multiset<int>s;
}fdp[1050009];
struct node{
	int l,r;
}b[500009];
int m;
bool cmp(node x,node y){
	return x.r<y.r; 
} 
int curr;
int res;
int main(){
	curr=-1;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	fdp[0].s.insert(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i]=dp[i-1]^a[i];
		if(!fdp[dp[i]^k].s.empty()){
			auto tmp=fdp[dp[i]^k].s.end();
			tmp--;
			b[++m]={*tmp+1,i};
		}
		fdp[dp[i]].s.insert(i);
	}
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(curr>=b[i].l)continue;
		curr=b[i].r;
		res++;
	}
	printf("%d",res);
	return 0;
}

