#include <bits/stdc++.h>
#define N 100010
using namespace std;
int T,n;
struct coord{
	int a;
	int b;
	int c;
	int cha;	
}x[N];
int ans;
int ch1,ch2;
int maxx;
int zui[5];
int cmp(coord q,coord p){
	return q.cha<p.cha;
}
int shu;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			maxx=max(x[i].a,max(x[i].b,x[i].c));
			ans+=maxx;
			if(maxx==x[i].a){
				zui[1]++;
				shu=1;
			}else if(maxx==x[i].b){
				zui[2]++;
				shu=2;
			}else{
				zui[3]++;
				shu=3;
			}
			if(shu==1){
				ch1=abs(x[i].a-x[i].b);
				ch2=abs(x[i].a-x[i].c);
			}
			if(shu==2){
				ch1=abs(x[i].b-x[i].c);
				ch2=abs(x[i].b-x[i].a);
			}
			if(shu==3){
				ch1=abs(x[i].c-x[i].b);
				ch2=abs(x[i].c-x[i].a);
			}
			x[i].cha=min(ch1,ch2);
			
		}
		sort(x+1,x+1+n,cmp);
		if(zui[1]>n/2||zui[2]>n/2||zui[3]>n/2){
			maxx=max(zui[1],max(zui[2],zui[3]));
			for(int i=1;i<=maxx-n/2;i++){
				ans-=x[i].cha;
			}
		}
		cout<<ans<<endl;
	}
}
