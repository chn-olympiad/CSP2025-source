#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,yeno;
}lis[200005];
int n,k,tt,awa[200005],whe[50005],cnt,ans;
bool yeno[200005],f;
bool cmp(node x,node y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=50000;i++) whe[i]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&tt);
		awa[i]=awa[i-1]^tt;
		if(tt!=0&&tt!=1) f=0;
	}
	if(f==1){
		for(int i=1;i<=n;i++){
			int qwq=whe[awa[i]^k];
			if(qwq!=-1){
				cnt++;
				lis[cnt].l=qwq+1;
				lis[cnt].r=i;
			}
			whe[awa[i]]=i;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				int ttttt=awa[i]^awa[j-1];
				if(ttttt==k){
					cnt++;
					lis[cnt].l=j;
					lis[cnt].r=i;
					break;
				}
			}
		}
	}
	if(f==0){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=i;j++){
				if(lis[i].l<lis[j].l&&lis[i].r>lis[j].r){
					lis[i].yeno=1;
				}
				if(lis[i].l>lis[j].l&&lis[i].r<lis[j].r){
					lis[j].yeno=1;
				}
			}
		}
	}
	sort(lis+1,lis+1+cnt,cmp);
	int mar=-100;
	for(int i=1;i<=cnt;i++){
		if(lis[i].yeno==1) continue;
		if(lis[i].l>mar){
			ans++;
			mar=lis[i].r;
		}
	}
	cout<<ans;
	return 0;
}
//made by S_A_T_E_L_L_I_T_E(luogu_737070)
//maybe 65
//I love phigros
