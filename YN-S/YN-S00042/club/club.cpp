#include<queue>
#include<vector>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,ans,cnt[5];
struct node{
	int a,b,c;
	bool operator<(const node&o)const{
		return max(a,max(b,c))-min(a,min(b,c))>
			max(o.a,max(o.b,o.c))-min(o.a,min(o.b,o.c));
	}
}a[100010];
priority_queue<int,vector<int>,greater<int>>q[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--){cin>>n;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int t,fi,se,a1=a[i].a,b=a[i].b,c=a[i].c;
			if(a1>=b&&a1>=c)t=1,fi=a1,se=max(b,c);
			else if(b>=a1&&b>=c)t=2,fi=b,se=max(a1,c);
			else t=3,fi=c,se=max(a1,b);
			cnt[t]++;ans+=fi;
			q[t].push(fi-se);
			if(cnt[t]>n/2)ans-=q[t].top(),q[t].pop();
		}cout<<ans<<endl;cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<4;i++)while(q[i].size())q[i].pop();
	}return 0;
}
//2 4 0
//2 3 0
//0 2 0
//0 2 1