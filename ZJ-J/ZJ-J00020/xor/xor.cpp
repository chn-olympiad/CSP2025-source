#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}ttm[500005];
int jian,n,k,a[500005][25],cha[500005],kwei[30],wang,sum[500005][25],xx,ying,cnt,yiden[500005];
bool f,kk;
bool cmp(node X,node Y){
	return (X.r-X.l)<(Y.r-Y.l);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<=19;i++){
		kwei[i+1]=(k>>i)&1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&xx);
		for(int j=1;j<=20;j++){
			a[i][j]=(xx>>(j-1))&1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++){
			sum[i][j]=sum[i-1][j]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			f=0;
			for(int p=1;p<=20;p++){
				ying=sum[i+j-1][p]-sum[i-1][p];
				if((ying%2)!=kwei[p]){
					f=1;
					break;
				}
			}
			if(f==0){
				ttm[++cnt].l=i;
				ttm[cnt].r=i+j-1;
				wang++;
			}
		}
	}
	sort(ttm+1,ttm+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		kk=0;
		for(int j=ttm[i].l;j<=ttm[i].r;j++){
			if(yiden[j]!=0){
				wang--;
				kk=1;
				break;
			}
		}
		if(kk==0)
			for(int j=ttm[i].l;j<=ttm[i].r;j++)
				yiden[j]++;
	}
	printf("%d",wang);
	return 0;
}
