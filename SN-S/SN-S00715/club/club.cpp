#include<bits/stdc++.h>
using namespace std;
struct node{
	int q,w,e,max1;
}a[100005];
int maxn,n;
void dfs(int tp,int sum,int q1,int w1,int e1){
	if(tp>=n){
		return ;
	}
	maxn=max(sum,maxn);
	if(q1*2<n){
		dfs(tp+1,sum+a[tp+1].q,q1+1,w1,e1);
	}
	if(w1*2<n){
		dfs(tp+1,sum+a[tp+1].w,q1,w1+1,e1);
	}
	if(e1*2<n){
		dfs(tp+1,sum+a[tp+1].e,q1,w1,e1+1);
	}
}
void dfs2(int tp,int sum,int q1,int w1){
	if(tp>=n){
		return;
	}
	maxn=max(sum,maxn);
	if(q1*2<n){
		dfs2(tp+1,sum+a[tp+1].q,q1+1,w1);
	}
	if(w1*2<n){
		dfs2(tp+1,sum+a[tp+1].w,q1,w1+1);
	}
}
int cmp(node x,node y){
	return x.q>y.q;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=30){
			for(int i=0;i<n;i++){
				cin>>a[i].q>>a[i].w>>a[i].e;
			}
				maxn=-1;
				dfs(0,a[0].q,1,0,0);
				dfs(0,a[0].e,0,0,1);
				dfs(0,a[0].w,0,1,0);
				cout<<maxn<<endl;
		}else if(n>=30&&n<=200){
			for(int i=0;i<n;i++){
				cin>>a[i].q>>a[i].w>>a[i].e;
			}
			maxn=-1;
			dfs2(0,a[0].q,1,0);
			dfs2(0,a[0].w,0,1);
			cout<<maxn<<endl;
		}else{
			for(int i=0;i<n;i++){
				cin>>a[i].q>>a[i].w>>a[i].e;
			}
			int sum=0;
				sort(a,a+n,cmp);
				for(int i=0;i*2<n;i++){
					sum+=a[i].q;
			}
		}
	}
	return 0;
} 
