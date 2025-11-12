#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct clubmember{
	int x,y,z,c;
}a[N],u[N],v[N],w[N];
int n,t,unt,vnt,wnt,ans;
bool cmp1(clubmember e,clubmember r){
	return e.c>r.c;
}
bool cmp2(clubmember e,clubmember r){
	return e.c>r.c;
}
bool cmp3(clubmember e,clubmember r){
	return e.c>r.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;unt=0;vnt=0;wnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=a[i].y && a[i].x>=a[i].z){
				unt++;
				u[unt]=a[i];
				u[unt].c=a[i].x-max(a[i].y,a[i].z);
			}else if(a[i].y>=a[i].x && a[i].y>=a[i].x){
				vnt++;
				v[vnt]=a[i];
				v[vnt].c=a[i].y-max(a[i].x,a[i].z);
			}else if(a[i].z>=a[i].x && a[i].z>=a[i].y){
				wnt++;
				w[wnt]=a[i];
				w[wnt].c=a[i].z-max(a[i].y,a[i].x);
			}
		}
		for(int i=1;i<=unt;i++){
			ans+=u[i].x;
		}
		for(int i=1;i<=vnt;i++){
			ans+=v[i].y;
		}
		for(int i=1;i<=wnt;i++){
			ans+=w[i].z;
		}
		sort(u+1,u+1+unt,cmp1);
		sort(v+1,v+1+vnt,cmp2);
		sort(w+1,w+1+wnt,cmp3);
		if(unt>(n/2)){
			for(int i=unt;i>n/2;i--){
				ans-=u[i].c;
			}
		}else if(vnt>(n/2)){
			for(int i=vnt;i>n/2;i--){
				ans-=v[i].c;
			}
		}else if(wnt>(n/2)){
			for(int i=wnt;i>n/2;i--){
				ans-=w[i].c;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

