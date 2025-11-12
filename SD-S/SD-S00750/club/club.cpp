#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int ans=-1;
int a[N][5];
bool t1=1;//ÌØÊâA
void dfs(int pos,int sum,int x,int y,int z){
	if (pos>n){
		if (x<=n/2 && y<=n/2 && z<=n/2)
			ans=max(ans,sum);
		return;
	}
	if (x+1<=n/2) dfs(pos+1,sum+a[pos][1],x+1,y,z);
	if (y+1<=n/2) dfs(pos+1,sum+a[pos][2],x,y+1,z);
	if (z+1<=n/2) dfs(pos+1,sum+a[pos][3],x,y,z+1);
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		t1=1;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if (a[i][2]!=0 || a[i][3]!=0) t1=0;
		}
		if (t1){
			int h[N];
			int sum=0;
			for (int i=1;i<=n;i++){
				h[i]=a[i][1];
			}
			sort(h+1,h+1+n,cmp);
			for (int i=1;i<=n/2;i++){
				sum+=h[i];
			}
			cout<<sum<<endl;
		}else{
			ans=-1;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		}
	}
	return 0;
}
