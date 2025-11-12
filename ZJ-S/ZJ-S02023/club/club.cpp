#include<bits/stdc++.h>
using namespace std;
int n,T,t1,t2,t3;
long long ans,px[100001],id=1;
struct node{
	int a,b,c,p,t;
}d[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		id=1;
		t1=t2=t3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			d[i].t=1;
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].a<d[i].b){
				swap(d[i].a,d[i].b);
				d[i].t=2;
			} 
			if(d[i].b<d[i].c) swap(d[i].b,d[i].c);
			if(d[i].a<d[i].b){
				swap(d[i].a,d[i].b);
				d[i].t=3;
			} 
			ans+=d[i].a;d[i].p=d[i].a-d[i].b;
			if(d[i].t==1)t1++;
			if(d[i].t==2)t2++;
			if(d[i].t==3)t3++;
		}
		if(t1<=n/2&&t2<=n/2&&t3<=n/2) cout<<ans<<endl;
		else{
			if(t1>n/2){
				for(int i=1;i<=n;i++){
					if(d[i].t==1){
						px[id]=d[i].p;
						id++;
					} 
				}
				sort(px+1,px+id);
				for(int i=1;i<=t1-n/2;i++){
					ans-=px[i];
				}
				cout<<ans<<endl;
			}
			if(t2>n/2){
				for(int i=1;i<=n;i++){
					if(d[i].t==2){
						px[id]=d[i].p;
						id++;
					} 
				}
				sort(px+1,px+id);
				for(int i=1;i<=t2-n/2;i++){
					ans-=px[i];
				}
				cout<<ans<<endl;
			}
			if(t3>n/2){
				for(int i=1;i<=n;i++){
					if(d[i].t==3){
						px[id]=d[i].p;
						id++;
					} 
				}
				sort(px+1,px+id);
				for(int i=1;i<=t3-n/2;i++){
					ans-=px[i];
				}
				cout<<ans<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
