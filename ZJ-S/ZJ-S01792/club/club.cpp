#include<bits/stdc++.h>
using namespace std;
int a[100010][3],maxx=0,n;
void dfs(int cnt[3],int sum[3],int now){
	if(now==n){
		if(cnt[0]>n/2||cnt[1]>n/2||cnt[2]>n/2) return ;
		maxx=max(maxx,sum[0]+sum[1]+sum[2]);
		return ;
	}
	for(int i=0;i<3;i++){
		cnt[i]++;
		sum[i]+=a[now][i];
		dfs(cnt,sum,now+1);
		cnt[i]--;
		sum[i]-=a[now][i];
	}
}
bool cmp(pair<int,int> x,pair<int,int> y){
	return max(x.first,x.second)>max(y.first,y.second);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		maxx=0;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		int temp1[3]={0,0,0},temp2[3]={0,0,0};
		dfs(temp1,temp2,0);
		cout<<maxx<<endl;
	}
	return 0;
}
