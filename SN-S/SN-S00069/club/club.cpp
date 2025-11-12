#include<bits/stdc++.h>
using namespace std;
int a[5],n;
long long max1=-1;
struct ab{
	int m,name;
} b1[100005][5];
bool cmp1(ab p,ab q){
	return p.m>q.m;
}void dfs(int x,long long sum){
	if(x>n){
		return;
	}if(a[b1[x][0].name]+1<=n/2){
		a[b1[x][0].name]++;
		dfs(x+1,sum+b1[x][0].m);
		a[b1[x][0].name]--;
	}if(a[b1[x][1].name]+1<=n/2){
		a[b1[x][1].name]++;
		dfs(x+1,sum+b1[x][1].m);
		a[b1[x][1].name]--;
	}if(a[b1[x][2].name]+1<=n/2){
		a[b1[x][2].name]++;
		dfs(x+1,sum+b1[x][2].m);
		a[b1[x][2].name]--;
	}max1=max(max1,sum);
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		ab b[5]={};
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>b[0].m>>b[1].m>>b[2].m;
			b[0].name=0;
			b[1].name=1;
			b[2].name=2;
			b1[j][0]=b[0];
			b1[j][1]=b[1];
			b1[j][2]=b[2];
		}dfs(0,0);
		cout<<max1<<endl;
		max1=-1;
		for(int j=0;j<5;j++){
			a[j]=0;
		}
	}return 0;
}
