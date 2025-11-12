#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,to;
int f[N];
struct T{
	int x,y,z;
}a[N];

bool cmp(T l,T r){
//	if(l.c==r.c){
		if(l.x==r.x){
			if(l.y==r.y) return l.z>r.z;
			return l.y>r.y;
		}
		return l.x>r.x;
//	}
//	return l.c>r.c;
}

bool cmp2(T l,T r){
	return l.y-l.x>r.y-r.x;
}

void dfs(int x){
	if(x>n){
		int s1=0,s2=0,s3=0,ans=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1) ans+=a[i].x,s1++;
			else if(f[i]==2) ans+=a[i].y,s2++;
			else ans+=a[i].z,s3++;
//			printf("%d ",f[i]);
			
		}
//		printf("*\n");
		if(s1>n/2||s2>n/2||s3>n/2) return;
		to=max(to,ans);
		return;
	}
	for(int i=1;i<=3;i++){
//		if(f[x]) continue;
		f[x]=i;
//		printf("%d %d\n",i,x);
		dfs(x+1);
//		printf(".");
		f[x]=0;
	}
//	f[x]=1;
//	dfs(x+1);
//	f[x]=2;
//	dfs(x+1);
//	f[x]=3;
//	dfs(x+1);
//	f[x]=0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int A=1,B=1;
		for(int i=1;i<=n;i++){
			f[i]=0;
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].y||a[i].z) A=0;
			if(a[i].z) B=0;
		}
		sort(a+1,a+1+n,cmp);
		if(A){
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			printf("%d\n",ans);
			continue;
		}if(B){
			int ans=0;
			for(int i=1;i<=n;i++) ans+=a[i].x;
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n/2;i++) ans=ans-a[i].x+a[i].y;
			printf("%d\n",ans);
			continue;
		}
		to=0;
		dfs(1);printf("%d\n",to);
	}
	return 0;
}
