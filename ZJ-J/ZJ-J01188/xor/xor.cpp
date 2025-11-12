#include<bits/stdc++.h>
using namespace std;
int n,k,t,ans,l;
int a[5000050],s[5000050];
struct nd{
	int l,r;
}f[5000050];
bool cmp(nd x,nd y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		if(a[i]==k){
			f[++l].l=i;
			f[l].r=i;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((s[i-1]^s[j])==k){
				f[++l].l=i;
				f[l].r=j;
			}
		}
	}
	sort(f+1,f+l+1,cmp);
	for(int i=1;i<=l;i++){
		if(f[i].l>t){
			ans++;
			t=f[i].r;
		}
	}
	printf("%d\n",ans);
	return 0;
}
