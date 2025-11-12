#include<bits/stdc++.h>
using namespace std;
const int N=2e5; 
long long n,t,js[7],sds,pks;
int vis[N],vis2[N];
struct Node{
	int ad,sd,pk,zui,sec,thir,zuih,sech,thirh;
}a[N];//ad=1,sd=2,pk=3
bool cmp(Node a,Node b){
	return a.zui>b.zui;
}
void paixu(int x){
	if(a[x].ad>=a[x].sd&&a[x].ad>=a[x].pk){
		a[x].zui=a[x].ad;a[x].zuih=1;
		if(a[x].sd>=a[x].pk){
			a[x].sec=a[x].sd;a[x].sech=2;
			a[x].thir=a[x].pk;a[x].thirh=3;
			return;
		}else{
			a[x].sec=a[x].pk;a[x].sech=3;
			a[x].thir=a[x].sd;a[x].thirh=2;
			return;
		}
	}//ad最大 
	if(a[x].sd>=a[x].ad&&a[x].sd>=a[x].pk){
		a[x].zui=a[x].sd;a[x].zuih=2;
		if(a[x].ad>=a[x].pk){
			a[x].sec=a[x].ad;a[x].sech=1;
			a[x].thir=a[x].pk;a[x].thirh=3;
			return;
		}else{
			a[x].sec=a[x].pk;a[x].sech=3;
			a[x].thir=a[x].ad;a[x].thirh=1;
			return;
		}
	}//sd最大 
	if(a[x].pk>=a[x].sd&&a[x].pk>=a[x].ad){
		a[x].zui=a[x].pk;a[x].zuih=3;
		if(a[x].sd>=a[x].ad){
			a[x].sec=a[x].sd;a[x].sech=2;
			a[x].thir=a[x].ad;a[x].thirh=1;
			return;
		}else{
			a[x].sec=a[x].ad;a[x].sech=1;
			a[x].thir=a[x].sd;a[x].thirh=2;
			return;
		}
	}//pk最大 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long q=n/2,ans=0,sds=0,pks=0;
		memset(a,0,sizeof(a));memset(js,0,sizeof(js));memset(vis,0,sizeof(vis));memset(vis2,0,sizeof(vis2));
		for(int i=1;i<=n;i++){
			cin>>a[i].ad>>a[i].sd>>a[i].pk;
			if(a[i].sd==0)sds++;
			if(a[i].pk==0)pks++;
			a[i].zui=max(a[i].ad,max(a[i].sd,a[i].pk));
			paixu(i);
		}
		sort(a+1,a+1+n,cmp);
		if(sds==n&&pks==n){
			for(int i=1;i<=n;i++){
				if(i<=q)ans+=a[i].zui;
			}
			cout<<ans<<endl;
			continue;
		}else{
			for(int i=1;i<=n;i++){
				if(js[a[i].zuih]+1<=q){
					if(js[a[i].zuih]+1==q){
						for(int j=i+1;j<=n;j++){
							if(a[j].zuih==a[i].zuih){
								if(a[i].sec+a[j].zui>a[i].zui+a[j].sec){
									ans+=a[i].sec;
									js[a[i].sech]++;
									vis[i]=1;
									break;
								} 
							}
						}
						if(vis[i]==1)continue;
					}
					ans+=a[i].zui;
					js[a[i].zuih]++;
					continue;
				}
				if(js[a[i].sech]+1<=q){
					if(js[a[i].sech]+1==q){
						for(int j=i+1;j<=n;j++){
							if(a[i].sech==a[j].zuih){
								if(a[i].thir+a[j].zui>a[i].sec+a[j].sec){
									ans+=a[i].thir;
									js[a[i].thir]++;
									vis2[i]=1;
									break;
								} 
							}
						}
						
						if(vis2[i]==1)continue;
					}
					ans+=a[i].sec;
					js[a[i].sech]++;
					continue;
				}
				ans+=a[i].thir;
				js[a[i].thirh]++;
			}
			cout<<ans<<endl;
		}
	}	
	return 0;
} 
