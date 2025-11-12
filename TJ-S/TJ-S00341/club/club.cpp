#include <bits/stdc++.h>
using namespace std;
int v[10];
struct node {
	int f,s,t,m1,jc,c1,c2,c3,m2;
};
node a[110000];
bool cmp(node a,node b){
	return a.jc>b.jc;
}
bool cmp2(node a,node b){
	return a.c2>b.c2;
}
bool cmp3(node a,node b){
	return a.c3>b.c3;
}
bool cmp4(node a,node b){
	return a.c1>b.c1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=105000;++i){
			a[i].f=0;
			a[i].s=0;
			a[i].t=0;
			a[i].c1=0;
			a[i].c2=0;
			a[i].m1=0;
			a[i].c3=0;
			a[i].jc=0;
			a[i].m2=0;
		}
		memset(v,0,sizeof v);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].f,&a[i].s,&a[i].t);
			a[i].c1=abs(a[i].f-a[i].s);
			a[i].c2=abs(a[i].s-a[i].t);
			a[i].c3=abs(a[i].t-a[i].f);
			if(a[i].f>a[i].s){
				if(a[i].s>a[i].t){
					a[i].m1=1;
					a[i].m2=2;
					a[i].jc=a[i].f-a[i].s;
				}else{
					if(a[i].f>a[i].t){
						a[i].m1=1;
						a[i].m2=3;
						a[i].jc=a[i].f-a[i].t;
					}else{
						a[i].m1=3;
						a[i].m2=1;
						a[i].jc=a[i].t-a[i].f;
					}
				}
			}else {
				if(a[i].s<a[i].t){
					a[i].m1=3;
					a[i].m2=2;
					a[i].jc=a[i].t-a[i].s;
				}else{
					if(a[i].f<a[i].t){
						a[i].m1=2;
						a[i].m2=3;
						a[i].jc=a[i].s-a[i].t;
					}else{
						a[i].m1=2;
						a[i].m2=1;
						a[i].jc=a[i].s-a[i].f;
					}
				}
			}
		}
		sort(a+1,a+n+1,cmp);

		int tmp=1;
		long long ans=0;
		while(tmp<=n){
			if(v[1]==n/2 or v[2]==n/2 or v[3]==n/2)break;
			v[a[tmp].m1]++;
			//printf("%d %d\n",tmp,a[tmp].m1);
			if(a[tmp].m1==1)ans+=a[tmp].f;
			if(a[tmp].m1==2)ans+=a[tmp].s;
			if(a[tmp].m1==3)ans+=a[tmp].t;
			tmp++;
		}
		if(tmp>n){
			printf("%lld\n",ans);
			continue;
		}
		
		//1
		if(v[1]==n/2){
			sort(a+tmp,a+n+1,cmp2);

			int k=tmp;
			while(k<=n){
				if(v[2]==n/2 or v[3]==n/2)break;
				if(a[k].t>a[k].s){
					v[3]++;
					ans+=a[k].t;
				}else{
					v[2]++;
					ans+=a[k].s;
				}
				k++;
			}
			if(k>n){
				printf("%lld\n",ans);
				continue;
			}
			if(v[3]==n/2){
				for(int i=k;i<=n;++i){
					ans+=a[i].s;
				}
			}else{
				for(int i=k;i<=n;++i){
					ans+=a[i].t;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		
		//2
		
		if(v[2]==n/2){
			sort(a+tmp,a+n+1,cmp3);

			int k=tmp;
			while(k<=n){
				if(v[1]==n/2 or v[3]==n/2)break;
				if(a[k].t>a[k].f){
					v[3]++;
					ans+=a[k].t;
				}else{
					v[1]++;
					ans+=a[k].f;
				}
				k++;
			}
			if(k>n){
				printf("%lld\n",ans);
				continue;
			}
			if(v[3]==n/2){
				for(int i=k;i<=n;++i){
					ans+=a[i].f;
				}
			}else{
				for(int i=k;i<=n;++i){
					ans+=a[i].t;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		
		//3
		
		
		if(v[3]==n/2){
			sort(a+tmp,a+n+1,cmp4);

			int k=tmp;
			while(k<=n){
				if(v[2]==n/2 or v[1]==n/2)break;
				if(a[k].f>a[k].s){
					v[1]++;
					ans+=a[k].f;
				}else{
					v[2]++;
					ans+=a[k].s;
				}
				k++;
			}
			if(k>n){
				printf("%lld\n",ans);
				continue;
			}
			if(v[1]==n/2){
				for(int i=k;i<=n;++i){
					ans+=a[i].s;
				}
			}else{
				for(int i=k;i<=n;++i){
					ans+=a[i].f;
				}
			}
			printf("%lld\n",ans);
			continue;
		}
	}
	return 0;
}

