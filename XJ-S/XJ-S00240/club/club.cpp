#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int T,n,g,c,d,e,f[100010]={0},qi,qj,pi,pj,l,p,yy,jj,an;
long long ans=0;
struct s{
	int bb[4];
	int b[4];
}a[100010];
void oo(int x){
	if(x==1)c+=1;
	if(x==2)d+=1;
	if(x==3)e+=1;
}
bool oh(int x){
	int cc=c,dd=d,ee=e;
	if(x==1)cc+=1;
	if(x==2)dd+=1;
	if(x==3)ee+=1;
	if(cc<=n/2 && dd<=n/2 && ee<=n/2){
		return true;
	}else{
		return false;
	}
}
void op(int x,int y,int z){
	int m=a[y].bb[z];
	int mm=a[x].bb[z],ll=0,pp=0;
	for(int k=1;k<=3;k++){
		if(k==z)continue;
		if(ll<=a[y].bb[k] && oh(k)){
			pp=k;
			ll=a[y].bb[k];
		}
	}
	qi=z;
	qj=pp;
	yy=m-ll;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		ans=0,g=0,c=0,d=0,e=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].bb[1]>>a[i].bb[2]>>a[i].bb[3];
			if(a[i].bb[1]>=a[i].bb[2] && a[i].bb[1]>=a[i].bb[3]){
				a[i].b[1]=1;
				if(a[i].bb[2]>=a[i].bb[3]){
					a[i].b[2]=2;
					a[i].b[3]=3;
				}else{
					a[i].b[2]=3;
					a[i].b[3]=2;
				}
			}
			if(a[i].bb[2]>=a[i].bb[1] && a[i].bb[2]>=a[i].bb[3]){
				a[i].b[1]=2;
				if(a[i].bb[1]>=a[i].bb[3]){
					a[i].b[2]=1;
					a[i].b[3]=3;
				}else{
					a[i].b[2]=3;
					a[i].b[3]=1;
				}
			}
			if(a[i].bb[3]>=a[i].bb[1] && a[i].bb[3]>=a[i].bb[2]){
				a[i].b[1]=3;
				if(a[i].bb[2]>=a[i].bb[1]){
					a[i].b[2]=2;
					a[i].b[3]=1;
				}else{
					a[i].b[2]=1;
					a[i].b[3]=2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			g=a[i].b[1];
			if(oh(g)){
				f[i]=g;
				oo(g);
			}else{
				an=0,pi=0,pj=0;
				for(int k=1;k<=3;k++){
					if(k==g)continue;
					if(l<a[i].bb[k] && oh(k)){
						l=a[i].bb[k];
						p=k;
					}
				}
				an=a[i].bb[g]-l;
				pi=p;
				pj=g;
				for(int j=1;j<i;j++){
					if(jj==0)jj=j;
					if(f[j]==g){
						op(i,j,g);
						if(yy>an){
							an=yy;
							pi=g;
							jj=j; 
							pj=qj;
						}
					}
				}
				f[jj]=pj;
				f[i]=pi;
				if(pj!=g)oo(pj);
				else oo(pi);
			}
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].bb[f[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
