#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
	int a,b,c;
};
int t,n,mmax;
node a[maxn];
void dfs(int now,int t1,int t2,int t3,int cnt){
	if(t1>n/2 || t2>n/2 || t3>n/2){
		return;
	}
	if(now==n+1){
		mmax=max(mmax,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			dfs(now+1,t1+1,t2,t3,cnt+a[now].a);
		}
		else if(i==2){
			dfs(now+1,t1,t2+1,t3,cnt+a[now].b);
		}
		else if(i==3){
			dfs(now+1,t1,t2,t3+1,cnt+a[now].c);
		}
	}
}
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		cin >>n;
		int s1=0,s2=0,s3=0,ans=0;
		bool tmp1=true,tmp2=true;
		for(int i=1;i<=n;i++){
			cin >>a[i].a >>a[i].b >>a[i].c;
			if(a[i].b){
				tmp1=false;
			}
			if(a[i].c){
				tmp2=false;
			}
			if(a[i].a>=a[i].b && a[i].a>=a[i].c){
				s1++;
				ans+=a[i].a;
			} 
			else if(a[i].b>=a[i].a && a[i].b>=a[i].c){
				s2++;
				ans+=a[i].b;
			} 
			else if(a[i].c>=a[i].a && a[i].c>=a[i].b){
				s3++;
				ans+=a[i].c;
			} 
		}
		if(tmp1 && tmp2){
			sort(a+1,a+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].a;
			}
			cout <<sum;
			continue;
		}
		if(s1<=n/2 && s2<=n/2 && s3<=n/2){
			cout <<ans <<endl;
		}
		else{
			mmax=0;
			dfs(1,0,0,0,0);
			cout <<mmax <<endl;
		}
	}
	return 0;
} 