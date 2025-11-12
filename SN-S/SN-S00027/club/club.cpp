//SN-S00027  何泓毅  西安铁一中国际合作学校 
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int sns,n;
struct node{
	int a,b,c,maxn,midn,minn,wmax,wmid,wmin;
}oyy[N];

bool cmp(node x,node y){
	if(x.maxn==y.maxn && x.midn==y.midn)
		return x.minn>y.minn;
	if(x.maxn==y.maxn)
		return x.midn>y.midn;
	else
		return x.maxn>y.maxn;
}

void dfs(int k,int ta,int tb,int tc,int sum){
	if(n+1==k){
		sns=max(sns,sum);
		return;
	}
	if(ta<=n/2-1){
		sum+=oyy[k].a;
		dfs(k+1,ta+1,tb,tc,sum);
		sum-=oyy[k].a;
	}
	if(tb<=n/2-1){
		sum+=oyy[k].b;
		dfs(k+1,ta,tb+1,tc,sum);
		sum-=oyy[k].b;
	}
	if(tc<=n/2-1){
		sum+=oyy[k].c;
		dfs(k+1,ta,tb,tc+1,sum);
		sum-=oyy[k].c;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,k,T,ta,tb,tc,wmax,ans;
	cin>>T;
	while(T--){
		ta=tb=tc=ans=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>oyy[i].a>>oyy[i].b>>oyy[i].c;
			if(oyy[i].a==oyy[i].b && oyy[i].a==oyy[i].c){
				oyy[i].maxn=oyy[i].midn=oyy[i].minn=oyy[i].a;
				oyy[i].wmax=1,oyy[i].wmid=2,oyy[i].wmin=3;
				continue;
			}
				
			if(oyy[i].a==oyy[i].b){
				if(oyy[i].c>oyy[i].a){
					oyy[i].maxn=oyy[i].c,oyy[i].wmax=3;
					oyy[i].midn=oyy[i].minn=oyy[i].a,oyy[i].wmid=1,oyy[i].wmin=2;
				}
				if(oyy[i].c<oyy[i].a){
					oyy[i].maxn=oyy[i].midn=oyy[i].a,oyy[i].wmax=1,oyy[i].wmid=2;
					oyy[i].minn=oyy[i].c,oyy[i].wmin=3;
				}
				continue;
			}
			if(oyy[i].a==oyy[i].c){
				if(oyy[i].b>oyy[i].a){
					oyy[i].maxn=oyy[i].b,oyy[i].wmax=2;
					oyy[i].midn=oyy[i].minn=oyy[i].a,oyy[i].wmid=1,oyy[i].wmin=3;
				}
				if(oyy[i].b<oyy[i].a){
					oyy[i].maxn=oyy[i].midn=oyy[i].a,oyy[i].wmax=1,oyy[i].wmid=3;
					oyy[i].minn=oyy[i].b,oyy[i].wmin=2;
				}
				continue;
			}
			if(oyy[i].b==oyy[i].c){
				if(oyy[i].a>oyy[i].b){
					oyy[i].maxn=oyy[i].a,oyy[i].wmax=1;
					oyy[i].midn=oyy[i].minn=oyy[i].b,oyy[i].wmid=2,oyy[i].wmin=3;
				}
				if(oyy[i].a<oyy[i].b){
					oyy[i].maxn=oyy[i].midn=oyy[i].b,oyy[i].wmax=2,oyy[i].wmid=3;
					oyy[i].minn=oyy[i].a,oyy[i].wmin=1;
				}
				continue;
			}
			
			if(oyy[i].a>oyy[i].b && oyy[i].a>oyy[i].c)
				oyy[i].maxn=oyy[i].a,oyy[i].wmax=1;
			if(oyy[i].b>oyy[i].a && oyy[i].b>oyy[i].c)
				oyy[i].maxn=oyy[i].b,oyy[i].wmax=2;
			if(oyy[i].c>oyy[i].a && oyy[i].c>oyy[i].b)
				oyy[i].maxn=oyy[i].c,oyy[i].wmax=3;
				
			if(oyy[i].b>oyy[i].a && oyy[i].c>oyy[i].a)
				oyy[i].minn=oyy[i].a,oyy[i].wmin=1;
			if(oyy[i].a>oyy[i].b && oyy[i].c>oyy[i].b)
				oyy[i].minn=oyy[i].b,oyy[i].wmin=2;
			if(oyy[i].b>oyy[i].c && oyy[i].a>oyy[i].c)
				oyy[i].minn=oyy[i].c,oyy[i].wmin=3;
			
			if(oyy[i].wmax!=1 && oyy[i].wmin!=1)
				oyy[i].midn=oyy[i].a,oyy[i].wmid=1;
			if(oyy[i].wmax!=2 && oyy[i].wmin!=2)
				oyy[i].midn=oyy[i].b,oyy[i].wmid=2;
			if(oyy[i].wmax!=3 && oyy[i].wmin!=3)
				oyy[i].midn=oyy[i].c,oyy[i].wmid=3;
		}
//		if(n<=200){
//			sns=0;
//			dfs(1,0,0,0,0);
//			cout<<sns<<endl;
//			continue;
//		}
		sort(oyy+1,oyy+n+1,cmp);
		for(i=1;i<=n;i++){
			if(oyy[i].wmax==1){
				if(ta<=n/2-1)
					ta++,ans+=oyy[i].a;
				else{
					if(oyy[i].wmid==2){
						if(tb<=n/2-1)
							tb++,ans+=oyy[i].b;
						else
							tc++,ans+=oyy[i].c;
					}else{
						if(tc<=n/2-1)
							tc++,ans+=oyy[i].c;
						else
							tb++,ans+=oyy[i].b;
					}
				}
			}else if(oyy[i].wmax==2){
				if(tb<=n/2-1)
					tb++,ans+=oyy[i].b;
				else{
					if(oyy[i].wmid==1){
						if(ta<=n/2-1)
							ta++,ans+=oyy[i].a;
						else
							tc++,ans+=oyy[i].c;
					}else{
						if(tc<=n/2-1)
							tc++,ans+=oyy[i].c;
						else
							ta++,ans+=oyy[i].a;
					}
				}
			}else{
				if(tc<=n/2-1)
					tc++,ans+=oyy[i].c;
				else{
					if(oyy[i].wmid==1){
						if(ta<=n/2-1)
							ta++,ans+=oyy[i].a;
						else
							tb++,ans+=oyy[i].b;
					}else{
						if(tb<=n/2-1)
							tb++,ans+=oyy[i].b;
						else
							ta++,ans+=oyy[i].a;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
