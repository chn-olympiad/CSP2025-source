#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
int numa,numb,numc;
struct bm{
	int num;
	int s;
};
bm booka[N];
bm bookb[N];
bm bookc[N];
int cmp(bm a,bm b){
	return a.s<b.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		numa=0;
		numb=0;
		numc=0;
		memset(booka,0,sizeof(booka));
		memset(bookb,0,sizeof(bookb));
		memset(bookc,0,sizeof(bookc));
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int i=1;i<=n;i++){
			if(a[i]==max(a[i],max(b[i],c[i]))){
				numa++;
				booka[i].num=i;
				booka[i].s=a[i];
				ans+=a[i];
			}
			else if(b[i]==max(a[i],max(b[i],c[i]))){
				numb++;
				bookb[i].num=i;
				bookb[i].s=b[i];
				ans+=b[i];
			}
			else if(c[i]==max(a[i],max(b[i],c[i]))){
				numc++;
				bookc[i].num=i;
				bookc[i].s=c[i];
				ans+=c[i];
			}
		}
		if(numa>n/2){
			sort(booka+1,booka+numa+1,cmp);
			int k=1;
			while(numa>n/2){
				int id=booka[k].num;
				if(b[id]>=c[id] and numb<n/2){
					ans=ans-a[id]+b[id];
					numb++;
				}
				else if(b[id]<c[id] and numc<n/2){
					ans=ans-a[id]+c[id];
					numc++;
				}
				else if(numb>=n/2){
					ans=ans-a[id]+c[id];
					numc++;
				}
				else if(numc>=n/2){
					ans=ans-a[id]+b[id];
					numb++;
				}
				k++;
				numa--;
			}
		}
		if(numb>n/2){
			sort(bookb+1,bookb+numb+1,cmp);
			int k=1;
			while(numb>n/2){
				int id=bookb[k].num;
				if(a[id]>=c[id] and numa<n/2){
					ans=ans-b[id]+a[id];
					numa++;
				}
				else if(a[id]<c[id] and numc<n/2){
					ans=ans-b[id]+c[id];
					numc++;
				}
				else if(numa>=n/2){
					ans=ans-b[id]+c[id];
					numc++;
				}
				else if(numc>=n/2){
					ans=ans-b[id]+a[id];
					numa++;
				}
				k++;
				numb--;
			}
		}
		if(numc>n/2){
			sort(bookc+1,bookc+numc+1,cmp);
			int k=1;
			while(numc>n/2){
				int id=bookc[k].num;
				if(b[id]>=a[id] and numb<n/2){
					ans=ans-c[id]+b[id];
					numb++;
				}
				else if(b[id]<a[id] and numa<n/2){
					ans=ans-c[id]+a[id];
					numa++;
				}
				else if(numb>=n/2){
					ans=ans-c[id]+a[id];
					numa++;
				}
				else if(numa>=n/2){
					ans=ans-c[id]+b[id];
					numb++;
				}
				k++;
				numc--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
