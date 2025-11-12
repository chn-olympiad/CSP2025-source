#include<iostream>
using namespace std;
int t,n,a[100005][5];
int ans;
long long time;
void dfs(int num,int score,int x,int y,int z){
	time++;
	if(time>18000000)return;
	if(num>n){
		if(score>ans)ans=score;
		return;
	}
	if(x<n/2)dfs(num+1,score+a[num][1],x+1,y,z);
	if(y<n/2)dfs(num+1,score+a[num][2],x,y+1,z);
	if(z<n/2)dfs(num+1,score+a[num][3],x,y,z+1);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		time=0;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
