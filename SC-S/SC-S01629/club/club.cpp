#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,t;
int res,num;
int cnt1,cnt2,cnt3;
struct node{
	int x1,x2,x3;
}a[N];
inline int dfs(int i,int sum){
	if(i==n+1)  return sum;
	int p=0;
	if(cnt1<num){
		cnt1++;
		p=max(p,dfs(i+1,sum+a[i].x1));
		cnt1--;
	}
	if(cnt2<num){
		cnt2++;
		p=max(p,dfs(i+1,sum+a[i].x2));
		cnt2--;
	}
	if(cnt3<num){
		cnt3++;
		p=max(p,dfs(i+1,sum+a[i].x3));
		cnt3--;
	}
	return p;
}

inline bool cmp1(node x,node y){  return x.x1>y.x1;  }
inline void sub12(){
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=num;i++)  res+=a[i].x1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n; res=0;
		num=n/2;
		cnt1=cnt2=cnt3=0;
		bool f2=0,f3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
			if(a[i].x2)  f2=1;
			if(a[i].x3)  f3=1;
		}
		if(!f2&&!f3)  sub12();
		else res=dfs(1,0);
		cout<<res<<'\n';
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/