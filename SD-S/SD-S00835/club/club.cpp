#include<iostream>
#include<algorithm>
using namespace std;
int t,n,cnt;
struct node{
	long long _a,_b,_c;
}a[100005];
bool cmp(node x,node y){
	return x._a>y._a;
}
long long ans,s1,s2,s3;
void dfs(int i,long long sum){
	if(cnt>2e7) return;
	if(i==n+1){
		ans=max(ans,sum);
		return;
	}
	cnt++;
	if(s1<n/2){
		s1++;
		dfs(i+1,sum+a[i]._a);
		s1--;
	}
	if(s2<n/2){
		s2++;
		dfs(i+1,sum+a[i]._b);
		s2--;
	}
	if(s3<n/2){
		s3++;
		dfs(i+1,sum+a[i]._c);
		s3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]._a>>a[i]._b>>a[i]._c;
		cnt=0;
		if(n<=30){
			dfs(1,0);
			cout<<ans<<endl;
		}else{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i]._a;
			}
			cout<<ans<<endl;
		}
		ans=0; 
	}
	return 0;
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
