#include<bits/stdc++.h>
using namespace std;
int t,n,ans,js1,js2,js3;
const int maxn=1e5+5;
struct node{
	int a,b,c,maxx;
}ac[maxn];
bool cmp(node a,node b){
	return a.maxx>b.maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>ac[i].a>>ac[i].b>>ac[i].c;
			ac[i].maxx=max(max(ac[i].a,ac[i].b),max(ac[i].c,ac[i].b));
		}
		sort(ac+1,ac+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(ac[i].a>=ac[i].b&&ac[i].a>=ac[i].c){
				if(js1>=n/2){
					int f=0;
					for(int j=1;j<i;j++){
						if(ac[j].a-max(ac[j].b,ac[j].c)<ac[j].a-ac[i].a){
							f=1;
							ans-=ac[j].a;
							ans+=max(ac[j].b,ac[j].c)+ac[i].a;
							break;
						}
					}
					if(!f){
						if(ac[i].b>=ac[i].c&&js2<n/2){
							js2++;
							ans+=ac[i].b;
						}else{
							js3++;
							ans+=ac[i].c;
						}
					}
				}else{
					ans+=ac[i].a; 
					js1++;
				}
			}else if(ac[i].b>=ac[i].a&&ac[i].b>=ac[i].c){
				if(js2>=n/2){
					int f=0;
					for(int j=1;j<i;j++){
						if(ac[j].b-max(ac[j].a,ac[j].c)<ac[j].b-ac[i].b){
							f=1;
							ans-=ac[j].b;
							ans+=max(ac[j].a,ac[j].c)+ac[i].b;
							break;
						}
					}
					if(!f){
						if(ac[i].c>=ac[i].a&&js1<n/2){
							js3++;
							ans+=ac[i].c;
						}else{
							js1++;
							ans+=ac[i].a;
						}
					}
				}else{
					ans+=ac[i].b; 
					js2++;
				}
			}else{
				if(js3>=n/2){
					int f=0;
					for(int j=1;j<i;j++){
						if(ac[j].c-max(ac[j].a,ac[j].b)<ac[j].c-ac[i].c){
							f=1;
							ans-=ac[j].c;
							ans+=max(ac[j].b,ac[j].a)+ac[i].c;
							break;
						}
					}
					if(!f){
						if(ac[i].a>=ac[i].b&&js1<n/2){
							js1++;
							ans+=ac[i].a;
						}else{
							js2++;
							ans+=ac[i].b;
						}
					}
				}else{
					ans+=ac[i].c; 
					js3++;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			ac[i].a=0,ac[i].b=0,ac[i].c=0,ac[i].maxx=0;
		}
		js1=0,js2=0,js3=0,ans=0;
	}
	return 0;
}
