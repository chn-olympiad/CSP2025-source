#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
long long n,k;
long long a[maxn];
int tmp[260][260];
int ans[maxn];
int jiyi[maxn];
int dfs(int i,int num){
	if(i>n) return num;
	if(jiyi[i]!=0) return num+jiyi[i];
	int tmp = i,x=0;
	if(ans[i]!=0){
		x=dfs(ans[i]+1,num+1);
		
	}
	x=max(x,dfs(i+1,num));
	jiyi[i]=max(x,num)-num;
	return max(x,num);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%ld %ld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
	}
	long long x;
	for(int i=1;i<=n;i++){
		x=a[i];
		ans[i]=0;
		if(k==x){
			ans[i]=i;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			x=x^a[j];
			if(x==k){
				ans[i]=j;
				break;
			}
		}
	}
	int cmp=0;
	//for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		if(ans[i]!=0){
			int q=ans[i]+1,ans1=1;
			ans1=dfs(q,ans1);
			cmp=max(cmp,ans1);
		}
	}
	printf("%d",cmp);
	return 0;
}


