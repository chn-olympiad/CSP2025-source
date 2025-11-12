#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
struct myd{
    int bi;
    int a;
    int b;
    int c;
}w[100005];
struct mabi{
    int co;
    int aq;
};
mabi q[10005],r[10005],e[10005];
bool Amp(myd x,myd y){
    return x.a>y.a;
}
bool Bmp(myd x,myd y){
    return x.b>y.b;
}
bool Cmp(myd x,myd y){
    return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int maxn;
    while(t--){
    	ans=0;
        cin>>n;
        maxn=n/2;
        for(int i=0;i<n;i++){
            cin>>w[i].a>>w[i].b>>w[i].c;
            w[i].bi=i;
        }
        for(int i=0;i<n;i++){
           sort(w,w+n,Amp);
           for(int i=0;i<n;i++){
                q[i].co=w[i].bi;
                q[i].aq=w[i].a;
           }
           sort(w,w+n,Bmp);
           for(int i=0;i<n;i++){
                e[i].co=w[i].bi;
                e[i].aq=w[i].b;
           }
           sort(w,w+n,Cmp);
           for(int i=0;i<n;i++){
                r[i].co=w[i].bi;
                r[i].aq=w[i].c;
           }
        }
        for(int i=0;i<n/2;i++){
            if(q[i].co!=e[i].co&&q[i].co!=r[i].co&&e[i].co!=r[i].co){
            	ans=ans+q[i].aq+e[i].aq+r[i].aq;
			}
			else if(q[i].co==e[i].co){
				ans+=max(q[i].aq,e[i].aq);
				if(q[i].aq>e[i].aq){
					for(int j=0;j<n;j++){
					e[i].aq=e[i+1].aq;
					}
				}
				else{
					for(int j=0;j<n;j++){
					q[j].aq=q[j+1].aq;
					}
				}
			}
			else if(q[i].co==r[i].co){
				ans+=max(q[i].aq,r[i].aq);
				if(q[i].aq>r[i].aq){
					for(int j=0;j<n;j++){
					r[j].aq=r[j+1].aq;
					}
				}
				else{
					for(int j=0;j<n;j++){
					q[j].aq=q[j+1].aq;
					}
				}
			}
			else if(r[i].co==e[i].co){
				ans+=max(r[i].aq,e[i].aq);
				if(r[i].aq>e[i].aq){
					for(int j=0;j<n;j++){
					e[j].aq=e[j+1].aq;
					}
				}
				else{
					for(int j=0;j<n;j++){
					r[j].aq=r[j+1].aq;
					}
				}
			}
        }
		cout<<ans;
    }
    return 0;
}
