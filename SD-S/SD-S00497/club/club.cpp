#include<bits/stdc++.h>
#define int long long
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define forrr(i,a,b) for(int i=a;i>=n;i--)
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
using namespace std;
//int a[100010][5];
struct node {
	int a,b,c;
} a[100010];
int n;
int sum[5];
int fl=0;
int ans=0;
bool cmp1(node a,node b){
	return a.a>b.a;
}
bool cmp2(node a,node b){
	return a.a+b.b>a.b+b.a;
}
void dfs(int i,int res) {
	forr(j,1,3) {
		if(sum[j]>n/2) return;
	}
	if(i==n+1) {
		ans=max(ans,res);
		fl=1;
	}
	sum[1]++;
	dfs(i+1,res+a[i].a);
	sum[1]--;
	sum[2]++;
	dfs(i+1,res+a[i].b);
	sum[2]--;
	sum[3]++;
	dfs(i+1,res+a[i].c);
	sum[3]--;
	return;
}
signed main() {

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//Ren5Jie4Di4Ling5%
	int t;
	cin>>t;
	int fl1=1,fl2=1;;
	while(t--) {
		ans=0;
		fl=0;
		forr(i,1,3) sum[i]=0;
		cin>>n;
		forr(i,1,n) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0) fl1=0;
			if(a[i].c!=0) fl2=0;
		}
		if(fl1){
			sort(a+1,a+1+n,cmp1);
			forr(i,1,n/2){
				ans+=a[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(fl2){
			sort(a+1,a+1+n,cmp2);
			forr(i,1,n/2){
				ans+=a[i].a;
			}
			forr(i,n/2+1,n){
				ans+=a[i].b;
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	/*
	3
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
	return 0;
}




