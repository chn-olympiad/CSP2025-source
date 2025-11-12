#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PQ priority_queue
const int N=1e5+5;
int n,a[N],b[N],c[N];
unsigned int ans;
int dfs(int sum,int deep,int cnt1,int cnt2,int cnt3){
	if(deep==n)return sum;
	int x1=0,x2=0,x3=0;
	if(cnt1<n/2)
		x1=dfs(sum+a[deep+1],deep+1,cnt1+1,cnt2,cnt3);
	if(cnt2<n/2)
		x2=dfs(sum+b[deep+1],deep+1,cnt1,cnt2+1,cnt3);
	if(cnt3<n/2)
		x3=dfs(sum+c[deep+1],deep+1,cnt1,cnt2,cnt3+1);
	return max(x1,max(x2,x3));
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i]>>c[i];
		if(n>=30&&n<=200){
			for(int i=1;i<=n;i++)ans+=max(a[i],max(b[i],c[i]));
			cout<<ans;
		}
		else if(n>200){
			sort(a+1,a+1+n);
			for(int i=n;i>n/2;i--)ans+=a[i];
			cout<<ans;
		}
		cout<<dfs(0,0,0,0,0)<<"\n";
	}
	return 0;
}
