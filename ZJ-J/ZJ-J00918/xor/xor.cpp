#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int l,r;
} ans[N];
bool f=1,g=1,fg=1;
int n,k,a[N],s[N],m,res,cnt1,cnt0,cntdb1;
set<int> vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) cnt0++;
		if(a[i]==1){
			cnt1++;
			if(fg&&a[i-1]==1) cntdb1++,fg=0;
			else if(a[i-1]==1) fg=1;
		}else f=0;
		if(a[i]!=1&&a[i]!=0) g=0;
		s[i]=(s[i-1]^a[i]);
	}
	if(f){
		if(k==1) printf("%d\n",n);
		if(k==0) printf("%d\n",n/2);
		return 0;
	}
	if(g){
		if(k==1) printf("%d\n",cnt1);
		if(k==0) printf("%d\n",cnt0+cntdb1);
		return 0;
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if((s[i-1]^s[j])==k){
				ans[++m].l=i;
				ans[m].r=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		bool f=1;
		for(int j=ans[i].l;j<=ans[i].r;j++){
			if(vis.count(j)){
				f=0;
				break;
			}
		}
		if(f){
			vis.insert(ans[i].l);vis.insert(ans[i].r);
			res++;
		}
	}
	printf("%d\n",res);
	
	return 0;
}

