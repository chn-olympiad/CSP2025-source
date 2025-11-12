#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e5+100;
struct node{
	LL x,y,z;
}a[N];
LL T,n,maxs;
void dfs(LL k,LL s1,LL s2,LL s3,LL sum){
	if(s1>n/2) return;
	if(s2>n/2) return;
	if(s3>n/2) return;
	if(k==n+1) maxs=max(maxs,sum);
	else{
		dfs(k+1,s1+1,s2,s3,sum+a[k].x);
		dfs(k+1,s1,s2+1,s3,sum+a[k].y);
		dfs(k+1,s1,s2,s3+1,sum+a[k].z);
	}
}
bool cmp(node i,node j){return i.x>j.x;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		LL f1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y==0&&a[i].z==0) f1++;
		}
		if(f1==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) maxs+=a[i].x;
			cout<<maxs<<"\n";
		}else{
			maxs=-1e18;
			dfs(1,0,0,0,0);
			cout<<maxs<<"\n";
		}
	}
	return 0;
} 
