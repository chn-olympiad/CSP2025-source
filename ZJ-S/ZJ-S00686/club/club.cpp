#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c;
	int m1,m2,m3;
	int v1,v2;
}a[100010];
struct node2{
	int val,x,u;
}v[300010];
int T,n,cnt;
int maxn,ans;
int ck[4];
int b2,b3;
int cmp(node2 x,node2 y){
	return x.val>y.val;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		cnt=0;
		map<int,int> mp;
		priority_queue<int,vector<int>,greater<int>>q1;
		priority_queue<int,vector<int>,greater<int>>q2;
		priority_queue<int,vector<int>,greater<int>>q3;
		ans=0;
		b2=0,b3=0;
		memset(v,0,sizeof(v));
		memset(ck,0,sizeof(ck));
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			v[++cnt].val=a[i].a;
			v[cnt].x=i;
			v[cnt].u=1;
			v[++cnt].val=a[i].b;
			v[cnt].x=i;
			v[cnt].u=2;
			v[++cnt].val=a[i].c;
			v[cnt].x=i;
			v[cnt].u=3;
			b2=a[i].b==0?0:1;
			b3=a[i].c==0?0:1;
			maxn = max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a==maxn){
				a[i].m1=1;
				maxn=max(a[i].b,a[i].c);
				if(a[i].b==maxn){
					a[i].m2=2;
					a[i].m3=3;
					a[i].v1=a[i].a-a[i].b;
					a[i].v2=a[i].b-a[i].c;
				}
				else{
					a[i].m2=3;
					a[i].m3=2;
					a[i].v1=a[i].a-a[i].b;
					a[i].v2=a[i].c-a[i].b; 
				}
			}
			else if(a[i].b==maxn){
				a[i].m1=2;
				maxn=max(a[i].a,a[i].c);
				if(a[i].a==maxn){
					a[i].m2=1;
					a[i].m3=3;
					a[i].v1=a[i].b-a[i].a;
					a[i].v2=a[i].a-a[i].c;
				}
				else{
					a[i].m2=3;
					a[i].m3=1; 
					a[i].v1=a[i].b-a[i].a;
					a[i].v2=a[i].c-a[i].a;
				}
			}
			else {
				a[i].m1=3;
				maxn=max(a[i].a,a[i].b);
				if(a[i].a==maxn){
					a[i].m2=1;
					a[i].m3=2;
					a[i].v1=a[i].c-a[i].a;
					a[i].v2=a[i].a-a[i].b;
				}
				else{
					a[i].m2=2;
					a[i].m3=1; 
					a[i].v1=a[i].c-a[i].b;
					a[i].v2=a[i].b-a[i].a;
				}
			}
		}
		if(b2==0&&b3==0){
			for(int i=1;i<=n;i++){
				ans+=a[i].a;
			}
			printf("%lld\n",ans);
			continue;
		}
		sort(v+1,v+cnt+1,cmp);
//		for(int i=1;i<=3*n;i++){
//			printf("%d ",v[i].val);
//		}
		for(int i=1;i<=cnt;i++){
			if(mp[v[i].x]==1){
				continue;
			}
			int fcw;
			if(ck[v[i].u]>=n/2){
				if(v[i].u==1){
					fcw=q1.top();
				}
				else if(v[i].u==2){
					fcw=q2.top();
				}
				else if(v[i].u==3){
					fcw=q3.top();
				}
				if(fcw<v[i].val){
					ans+=v[i].val-fcw;
					if(v[i].u==1){
						q1.pop();
						q1.push(a[v[i].x].v1);
					}
					else if(v[i].u==2){
						q2.pop();
						q2.push(a[v[i].x].v1);
					}
					else if(v[i].u==3){
						q3.pop();
						q3.push(a[v[i].x].v1);
					}
					mp[v[i].x]=1;
					ck[a[v[i].x].m2]++;
				}
				else{
					continue;
				}
			}
			else{
				ans+=v[i].val;
//				printf("%d*",v[i].val);
				mp[v[i].x]=1;
				ck[v[i].u]++;
				if(v[i].u==1){
					q1.push(a[v[i].x].v1);
				}
				else if(v[i].u==2){
					q2.push(a[v[i].x].v1);
				}
				else if(v[i].u==3){
					q3.push(a[v[i].x].v1);
				}
			}
		}
		printf("%lld\n",ans);
//		for(int i=1;i<=n;i++){
//			printf("%lld,%lld,%lld\n",a[i].m1,a[i].m2,a[i].m3);
//		}
		
	}
	return 0;
}
/* 3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/