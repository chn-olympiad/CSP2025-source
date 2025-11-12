#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
struct r{
	int x,y,z;
	int q,p,t;
}f[114514];
ll T,n,mx,ans;
int la,a[114514],lb,b[114514],lc,c[114514];
bool cmp(int x,int y){return f[x].q>f[y].q;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		mx=n/2,ans=la=lb=lc=0;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			int q=max(max(x,y),z),p=min(min(x,y),z);
			f[i].x=x,f[i].y=y,f[i].z=z;
			f[i].q=q-((x+y+z)-q-p);
			f[i].p=((x+y+z)-q-p)-p;
			f[i].t=0;
			if(q==x) a[++la]=i;
			if(q==y) b[++lb]=i;
			if(q==z) c[++lc]=i;
		}
		while(la>mx or lb>mx or lc>mx){
			if(la>mx){
				sort(a+1,a+la+1,cmp);
				while(la>mx){
					int i=a[la];
					if(f[i].t==2) continue;
					else if(f[i].t==1){
						f[i].t++;
						int x=f[i].x,y=f[i].y,z=f[i].z;
						if(min(min(x,y),z)==y) b[++lb]=i;
						else c[++lc]=i;
					}
					else{
						f[i].t++;
						if(f[i].y>f[i].z) b[++lb]=i;
						else c[++lc]=i;
						f[i].q=f[i].p;
					}
					la--;
				}
			}
			if(lb>mx){
				sort(b+1,b+lb+1,cmp);
				while(lb>mx){
					int i=b[lb];
					if(f[i].t==2) continue;
					else if(f[i].t==1){
						f[i].t++;
						int x=f[i].x,y=f[i].y,z=f[i].z;
						if(min(min(x,y),z)==x) a[++la]=i;
						else c[++lc]=i;
					}
					else{
						f[i].t++;
						if(f[i].x>f[i].z) a[++la]=i;
						else c[++lc]=i;
						f[i].q=f[i].p;
					}
					lb--;
				}
			}
			if(lc>mx){
				sort(c+1,c+lc+1,cmp);
				while(lc>mx){
					int i=c[lc];
					if(f[i].t==2) continue;
					else if(f[i].t==1){
						f[i].t++;
						int x=f[i].x,y=f[i].y,z=f[i].z;
						if(min(min(x,y),z)==y) b[++lb]=i;
						else a[++la]=i;
					}
					else{
						f[i].t++;
						if(f[i].x>f[i].y) a[++la]=i;
						else b[++lb]=i;
						f[i].q=f[i].p;
					}
					lc--;
				}
			}
		}
		for(int i=1;i<=la;i++) ans+=f[a[i]].x;
		for(int i=1;i<=lb;i++) ans+=f[b[i]].y;
		for(int i=1;i<=lc;i++) ans+=f[c[i]].z;
		cout<<ans<<endl;
	}
	return 0;
}
