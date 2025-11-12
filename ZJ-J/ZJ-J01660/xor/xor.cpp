#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],pre[500005],bj[500005];
long long ans,cnt;
struct Node{
	int l;
	int r;
	int L;
}num[500005];
bool cmp(Node x,Node y){
	if(x.L!=y.L)return x.L<y.L;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==1)pre[i]=a[i];
		else pre[i]=(pre[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(((pre[j]^pre[i-1])==k&&i!=j)||(i==j&&a[j]==k)){
				num[++cnt].l=i,num[cnt].r=j;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		num[i].L=num[i].r-num[i].l;
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int flag=0;
		for(int j=num[i].l;j<=num[i].r;j++){if(bj[j]==1){flag=1;break;}}
		if(flag==1)continue;
		ans++;
		for(int j=num[i].l;j<=num[i].r;j++){bj[j]++;}
	}
	cout<<ans;
	return 0;
}
