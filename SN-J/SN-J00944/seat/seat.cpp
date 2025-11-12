#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m;
bool vis[maxn][maxn];
int ans[maxn][maxn];
struct node{
	int idx;
	int score;
}a[maxn];
bool cmp(node a,node b){
	return a.score>b.score;
}
void solve1(int x,int num){
	int nx=n,ny=m;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			if(vis[j][i]==0){
				if(ny>i){
					ny=i;
					nx=j;
				}else if(ny==i&&nx>j){
					nx=j;
				}
			}
		}
	}
	for(int i=2;i<=m;i+=2){
		for(int j=n;j>=1;j--){
			if(vis[j][i]==0){
				if(ny>i){
					ny=i;
					nx=j;
				}
			}
		}
	}
	vis[nx][ny]=1;
	ans[nx][ny]=x;
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		int x;
		cin>>x;
		a[i].score=x;
	}
	int num1=a[1].score,num2=a[1].idx;
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		a[i].idx=i;
		if(a[i].score==num1)num2=a[i].idx;
	}
	if(num2<=n*(m-1)){
		for(int i=1;i<=num2;i++){
			solve1(a[i].score,num1);
		}
	}else{
		for(int i=1;i<=n*(m-1);i++){
			solve1(a[i].score,num1);
		}
		num2-=n*(m-1);
		if(m%2==1){
			cout<<m<<" "<<num2;
			return 0;
		}else{
			cout<<m<<" "<<n-num2+1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==num1)cout<<j<<" "<<i;
		}
	}
	return 0;
}
