#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005][4];
int cnt[4];
int ans;
void dfs(int x,int sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			cnt[i]++;
			dfs(x+1,sum+a[x][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		//³õÊ¼»¯ 
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		cin>>n;
		int cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]==0) cnt2++;
			if(a[i][3]==0) cnt3++;
		}
		if(cnt2==cnt3&&cnt2==n){
			int t[10005];
			for(int i=1;i<=n;i++) t[i]=a[i][1];
			sort(t+1,t+1+n);
			for(int i=1;i<=n/2;i++) ans+=t[i];
			cout<<ans<<endl;
			continue; 
		}
		dfs(1,0);
		cout<<ans<<endl;
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
