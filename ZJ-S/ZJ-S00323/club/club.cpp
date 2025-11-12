#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;
typedef long long ll;
struct node{
	int sum,n;
	friend operator<(node a,node b){
		return a.sum>b.sum;
	}
};
priority_queue<node>q1,q2,q3;
const int MAXN=100005;
int t,n,a[MAXN][3],sum[MAXN][3],s1,s2,s3;
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=s1=s2=s3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		}for(int i=1;i<=n;i++){
			int o=0;
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])o=0;
			if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])o=1;
			if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])o=2;
			switch(o){
			case 0:
				if(s1<n/2){q1.push({a[i][0],i});s1++;ans+=a[i][0];}
				else{
					node p=q1.top();q1.pop();
					if(a[i][0]>p.sum){
						if(a[p.n][1]>a[p.n][2]&&s2<n/2){s2++;q2.push({a[p.n][1],i});ans=ans-p.sum+a[i][0]+a[p.n][1];}
						else{s3++;q3.push({a[p.n][2],i});ans=ans-p.sum+a[i][0]+a[p.n][2];}
						q1.push({a[i][0],i});
					}else{
						if(a[i][1]>a[i][2]&&s2<n/2){s2++;q2.push({a[i][1],i});}
						else{s3++;q3.push({a[i][2],i});}
					}
				}break;
			case 1:
				if(s2<n/2){q2.push({a[i][1],i});s2++;ans+=a[i][1];}
				else{
					node p=q2.top();q2.pop();
					if(a[i][1]>p.sum){
						if(a[p.n][0]>a[p.n][2]&&s1<n/2){s1++;q1.push({a[p.n][0],i});ans=ans-p.sum+a[i][1]+a[p.n][0];}
						else{s3++;q3.push({a[p.n][2],i});ans=ans-p.sum+a[i][1]+a[p.n][2];}
						q1.push({a[i][1],i});
					}else{
						if(a[i][0]>a[i][2]&&s2<n/2){s1++;q1.push({a[i][0],i});}
						else{s3++;q3.push({a[i][2],i});}
					}
				}break;
			case 2:
				if(s3<n/2){q3.push({a[i][2],i});s3++;ans+=a[i][2];}
				else{
					node p=q3.top();q3.pop();
					if(a[i][2]>p.sum){
						if(a[p.n][1]>a[p.n][0]&&s2<n/2){s2++;q2.push({a[p.n][1],i});ans=ans-p.sum+a[i][3]+a[p.n][0];}
						else{s1++;q1.push({a[p.n][0],i});ans=ans-p.sum+a[i][3]+a[p.n][1];}
						q1.push({a[i][0],i});
					}else{
						if(a[i][1]>a[i][0]&&s2<n/2){s2++;q2.push({a[i][1],i});}
						else{s1++;q1.push({a[i][0],i});}
					}
				}break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}