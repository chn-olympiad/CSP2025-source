#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
	int x,y,z;
} a[100010];
node b[1000010];
//cmp
int n;
bool cmp1(node x,node y){
	return x.x>y.x;
}
int sum=INT_MIN; 
void dfs(int x,int s,int d,int b,int c){
	if(x>n){
		sum=max(sum,s);
		return ;
	}
	if(d+1<=n/2) dfs(x+1,s+a[x].x,d+1,b,c);
	if(b+1<=n/2) dfs(x+1,s+a[x].y,d,b+1,c);
	if(c+1<=n/2) dfs(x+1,s+a[x].z,d,b,c+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		//Çå¿Õ 
		cin>>n;
		for(int j=1;j<=n;j++){
			a[j].x=0,a[j].y=0,a[j].z=0;
			b[j].x=0,b[j].y=0;
		} 
		int f1=1,f2=1;
		for(int j=1;j<=n;j++){
			cin>>a[j].x>>a[j].y>>a[j].z;
			if(a[j].y!=0){
				f1=0;
			}
			if(a[j].z!=0){
				f2=0;
			}
		}
		if(f1==1&&f2==1){
			sort(a+1,a+n+1,cmp1);
			int ans=0;
			for(int j=1;j<=n/2;j++){
				ans+=a[j].x;
			}
			cout<<ans<<endl;
		}else if(f1==0&&f2==1){
			for(int j=1;j<=n;j++){
				b[j].x=a[j].x-a[j].y;
				b[j].y=j;
			}
			sort(b+1,b+n+1,cmp1);
			int ans=0;
			for(int j=1;j<=n/2;j++){
				ans+=a[b[j].y].x;
			}
			for(int j=n/2+1;j<=n;j++){
				ans+=a[b[j].y].y;
			}
			cout<<ans<<endl;
		}else{
			sum=INT_MIN;
			dfs(1,0,0,0,0);
			cout<<sum<<endl;
		}
	} 
	return 0;
} 
