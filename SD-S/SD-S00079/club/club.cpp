#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+2;
int t,n;
int ans;
bool sub_A=true,sub_B=true; 
struct node{
	int x,y,z,maxn;
} a[max_n];
bool cmp(node a,node b){
	return a.x>b.x;
}
bool cmp_(node a,node b){
	return a.maxn>b.maxn;
}
void DFS(int now,int sum,int cnta,int cntb,int cntc){
	if(now>=n){
		ans=max(ans,sum);
	}
	now++;
	if(cnta<n/2){
		//sum+=a[now][1],cnta++;
		DFS(now,sum+a[now].x,cnta+1,cntb,cntc);
		//sum-=a[now][1],cnta--;	
	}
	if(cntb<n/2){
		//sum+=a[now][2],cntb++;
		DFS(now,sum+a[now].y,cnta,cntb+1,cntc);
		//sum-=a[now][2],cntb--;	
	}
	if(cntc<n/2){
		//sum+=a[now][3],cntc++;
		DFS(now,sum+a[now].z,cnta,cntb,cntc+1);
		//sum-=a[now][3],cntc--;	
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			a[i].maxn=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].y||a[i].z){
				sub_A=false;
			}
			if(a[i].z){
				sub_B=false;
			}
		}
		if(n<=10){
			DFS(0,0,0,0,0);
		}
		else if(sub_A){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].x;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				ans+=a[i].maxn;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
