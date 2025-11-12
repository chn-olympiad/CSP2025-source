#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int anss=0;
struct node{
	int x;
	int y;
	int z;
}a[100005];
int f[1005][5];
int mx(int a,int b,int c){
	if(a>b&&a>c) return 1;
	if(b>a&&b>c) return 2;
	if(c>a&&c>a) return 3;
	return 1;
}
int solve1(){
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[i].x;
	}
	return ans;
}
bool cmp2(node a,node b){
	return abs(a.x-a.y)>abs(b.x-b.y);
}
int solve2(){
	int ans=0;
	int aa=0,bb=0;
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;++i){
		if(a[i].x>a[i].y){
			if(aa<n/2){
				ans+=a[i].x;
				aa++;
			}else{
				ans+=a[i].y;
				bb++;
			}
		}
	}
	return ans;
}
void dfs(int sum,int x,int y,int z){
	if(x+y+z==n){
		//cout<<x<<" "<<y<<" "<<z<<endl;
		anss=max(anss,sum);
		return ;
	}
	int i=x+y+z+1;
	if(x<n/2)
		dfs(sum+a[i].x,x+1,y,z);
	if(y<n/2)
		dfs(sum+a[i].y,x,y+1,z);
	if(z<n/2)
		dfs(sum+a[i].z,x,y,z+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool flag1=true;
		bool flag2=true;
		for(int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0)
				flag1=false;
			if(a[i].z!=0)
				flag1=false,flag2=false;
		}
		if(flag1){
			cout<<solve1()<<endl;
			continue;
		}
		if(flag2){
			cout<<solve2()<<endl;
			continue;
		}
		if(n<=10){
			dfs(0,0,0,0);
			cout<<anss<<endl;
		}
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

