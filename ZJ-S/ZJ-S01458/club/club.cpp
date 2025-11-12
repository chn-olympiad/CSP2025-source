#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005];
int n,m,ans,half;
int maxx;
int cnt1,cnt2,cnt3;
void dfs(int x){
	if(x==m+1) {
		if(ans>=maxx){
			maxx=ans;
		}
	}
	if(cnt1<half){
		ans+=a1[x];
		cnt1++;
		dfs(x+1);
		ans-=a1[x];
		cnt1--;
	}
	if(cnt2<half){
		ans+=a2[x];
		cnt2++;
		dfs(x+1);
		ans-=a2[x];
		cnt2--;
	}
	if(cnt3<half){
		ans+=a3[x];
		cnt3++;
		dfs(x+1);
		ans-=a3[x];
		cnt3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		ans=0;
		cnt1=0,cnt2=0,cnt3=0;
		maxx=0;
		cin>>m;
		half=m/2;
		for (int i=1;i<=m;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		dfs(1);
		cout<<maxx<<'\n';
	}
	return 0;
}
