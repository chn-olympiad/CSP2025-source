
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int zu[4];
struct  am{
	int a;
	int c;
	int b;
	
}xr[100001];
int hk[100010];
int hpv[100100];
int main(){
		freopen("club.in","r",stdin);
		freopen("club.in","w",stdout);
	
	int t;
	cin>>t;
	int n;
for(int p=0;p<t;p++){
	int ans=0;
	zu[1]=0;zu[2]=0;zu[3]=0;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>xr[i].a>>xr[i].b>>xr[i].c;
	for(int i=0;i<n;i++){
	if(xr[i].a>=xr[i].b&&xr[i].a>=xr[i].c){
		ans+=xr[i].a;
		zu[1]++;
	}
	else if(xr[i].b>=xr[i].a&&xr[i].b>=xr[i].c){
		ans+=xr[i].b;
		zu[2]++;
	}else{
		ans+=xr[i].c;
		zu[3]++;
	}
	}
	
 if(zu[1]>n/2){

for(int i=0;i<zu[3]-(n/2);i++){
int h=1e9+1;int hp;int tot=0;
	for(int j=0;j<n;j++){	
		h=min(h,xr[j].a);
		}
	ans-=h;h=1e9+1;
		for(int j=0;j<n;j++){
			if(h==xr[j].a) {
			hpv[tot]=j;
			tot++;			
			}
		}
		for(tot;tot>=0;tot--){
	h =	min(max(xr[hpv[tot]].c,xr[hpv[tot]].b),h);	
	if(h=max(xr[hpv[tot]].c,xr[hpv[tot]].b)){
		hp=hpv[tot];
	}
	
		}
			
			ans+=max(xr[hp].b,xr[hp].c);
}
				}
if(zu[2]>n/2){

for(int i=0;i<zu[2]-(n/2);i++){
int h=1e9+1;int hp;int tot=0;
	for(int j=0;j<n;j++){	
		h=min(h,xr[j].b);
		}
	ans-=h;h=1e9+1;
		for(int j=0;j<n;j++){
			if(h==xr[j].b) {
			hpv[tot]=j;
			tot++;			
			}
		}
		for(tot;tot>=0;tot--){
	h =	min(max(xr[hpv[tot]].a,xr[hpv[tot]].c),h);	
	if(h=max(xr[hpv[tot]].a,xr[hpv[tot]].c)){
		hp=hpv[tot];
	}
		}
			
			ans+=max(xr[hp].c,xr[hp].a);
}
				}
if(zu[3]>n/2){

for(int i=0;i<zu[3]-(n/2);i++){
int h=1e9+1;int hp;int tot=0;
	for(int j=0;j<n;j++){	
		h=min(h,xr[j].c);
		}
	ans-=h;h=1e9+1;
		for(int j=0;j<n;j++){
			if(h==xr[j].c) {
			hpv[tot]=j;
			tot++;			
			}
		}
		for(tot;tot>=0;tot--){
	h =	min(max(xr[hpv[tot]].a,xr[hpv[tot]].b),h);	
	if(h=max(xr[hpv[tot]].a,xr[hpv[tot]].b)){
		hp=hpv[tot];
	}
		}
			
			ans+=max(xr[hp].b,xr[hp].a);
}
				}
				cout<<ans;
}
		return 0;
} 