#include<bits/stdc++.h>
int n,k;
int a[500050];
int s[1005][1005];
struct nodex{
	int l,r;
	bool f;
}tx[1000010];
struct node{
	int l,r;
}t[1000010];
bool cmp(node x,node y){
	return x.l<y.l;
}
int cntx,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool fa=1,fb=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) fa=0;
		if(a[i]>1) fb=0;
	}
	if(fa==1){
		printf("%d",n/2);
		return 0;
	}
	if(fb==1){	
		int cnt1=0,cnt0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
			if(a[i]==0) cnt0++;
		}
		if(k==1){
			printf("%d",cnt1);
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1) cnt0++,i++;
			}
			printf("%d",cnt0);
		}
		return 0;
	}
	if(n<=1000){
		for(int i=1;i<=n;i++){
			s[i][i]=a[i];
			for(int j=i+1;j<=n;j++){
				s[i][j]=s[i][j-1]^a[j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(s[i][j]==k){
					tx[++cntx].l=i;
					tx[cntx].r=j;
					tx[cntx].f=1;
				}
			}
		}
		for(int i=1;i<=cntx;i++){
			for(int j=1;j<=cntx;j++){
				if(tx[i].l<=tx[j].l&&tx[i].r>=tx[j].r&&i!=j){
					tx[i].f=0;
				}
			}
		}
		for(int i=1;i<=cntx;i++){
			if(tx[i].f==1){
				t[++cnt].l=tx[i].l;
				t[cnt].r=tx[i].r;
			}
		}
		std::sort(t+1,t+1+cnt,cmp);
		int lr=0,ans=0;
		for(int i=1;i<=cnt;i++){
			if(t[i].l>lr) ans++,lr=t[i].r;
		}
		std::cout<<ans;
	}
	return 0;
}

