#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],K,ans,sum[1010],Xor[500010];
int flag[1010];
bool f,used[500010];
struct node{
	int l,r;
}b[1010];
void dfs(int x,int cnt){
//	cout<<x<<" "<<cnt<<endl;
	if(x>K){
		if(cnt<=ans)return;
		for(int i=1;i<=n;i++){
			sum[i]=0;
			sum[i]=sum[i-1]+flag[i];
			if(sum[i]>1)return;
		}
		ans=max(ans,cnt);
//		cout<<ans<<" ";
		//exit(0);
		return;
	}
	if(x>K)return;
	if(K-x+1+cnt<=ans)return;
	dfs(x+1,cnt);
	flag[b[x].l]++;
	flag[b[x].r+1]--;
	dfs(x+1,cnt+1);
	flag[b[x].l]--;
	flag[b[x].r+1]++;
}
/*
void On2(){
	int x[1010],y[1010];
	for(int i=1;i<=1010;i++)x[i]=y[i]=0;
	for(int i=1;i<=n;i++)x[i]=(x[i-1]^a[i]);
	for(int i=n;i>=1;i--)y[i]=(y[i+1]^a[i]);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if()
	}
}
*/
bool cmp(node aa,node bb){
	return aa.r<bb.r||aa.r==bb.r&&aa.l>bb.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)f=1;
	}
	if(n<=20000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n-i+1;j++){
				int num=0;
				for(int x=j;x<=j+i-1;x++)num^=a[x];
				if(num==k){
					b[++K].l=j;
					b[K].r=j+i-1;
				}
			}
		sort(b+1,b+1+K,cmp);
//		for(int i=1;i<=K;i++){
//			if(used[b[k].l]||used[b[k].r])continue;
//			for(int j=b[k].l;j<=b[k].r;j++)used[j]=1;
//			ans++;
//		}
//		for(int i=1;i<=K;i++)cout<<b[i].l<<" "<<b[i].r<<endl;
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	if(!f){
		cout<<n/2;
		return 0;
	}
	//if(n<=1000)On2();
	return 0;
}
/*
4 2
2 1 0 3


4 3
2 1 0 3

4 0
2 1 0 3


cout<<(25^25);
*/