#include<iostream>
#include<algorithm>
using namespace std;
int a[121],n,m,ooo,sum;
int dx[]={1,-1,0},dy[]={0,0,1};
bool flag[11][11];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int y){
	if(a[sum]==ooo){
		cout<<y+1<<" "<<x+1;
		return;
	}
	for(int i=0;i<3;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&!flag[nx][ny]){
			flag[nx][ny]=1;
			sum++;
			dfs(nx,ny);
			flag[nx][ny]=0;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	ooo=a[0];
	sort(a,a+(n*m),cmp);
	flag[0][0]=1;
	dfs(0,0);
	return 0;
} 
