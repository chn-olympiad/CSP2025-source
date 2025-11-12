#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAX=1e5+5;
vector<array<int,3>>q(MAX);
int n;
void solve(){
	cin>>n;
	q.clear();
	bool flag1=true,flag2=true;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>q[i][0]>>q[i][1]>>q[i][2];
		sum+=q[i][0]+q[i][1]+q[i][2];
		if(!(q[i][1]==q[i-1][1]&&q[i][1]==0))flag1=false;
		if(!(q[i][2]==q[i-1][2]&&q[i][2]==0))flag2=false;
	}
	if(flag1&&flag2){
		vector<int>cnt;
		for(int i=1;i<=n;i++)cnt.push_back(q[i][0]);
		sort(cnt.begin(),cnt.end());
		int len=cnt.size(),ans=0,t=0;
		for(int i=len-1;i>=0;i--){
			if(t>n/2)break;
			ans+=cnt[i];
			t++;
		}
		cout<<ans<<'\n';
	}else if(flag2){
		vector<pair<int,int>>cnt1,cnt2;
		for(int i=1;i<=n;i++){
			cnt1.push_back({q[i][0],q[i][1]});
			cnt2.push_back({q[i][1],q[i][0]});
		}
		sort(cnt1.begin(),cnt1.end());
		sort(cnt2.begin(),cnt2.end());
		int len=cnt1.size(),ans1=0,ans2=0,ans3=0,t=0;
		for(int i=len-1;i>=0;i--){
			if(t>n/2)ans1+=cnt1[i].second;
			else{
				ans1+=cnt1[i].first;
				t++;
			}
		}
		t=0;
		for(int i=len-1;i>=0;i--){
			if(t>=n/2)ans2+=cnt1[i].second;
			else{
				ans2+=cnt1[i].first;
				t++;
			}
		}
		ans1=max(ans1,ans2);
		t=ans2=0;
		for(int i=len-1;i>=0;i--){
			if(t>n/2)ans2+=cnt2[i].second;
			else{
				ans2+=cnt2[i].first;
				t++;
			}
		}
		t=0;
		for(int i=len-1;i>=0;i--){
			if(t>n/2)ans3+=cnt2[i].second;
			else{
				ans3+=cnt2[i].first;
				t++;
			}
		}
		ans2=max(ans2,ans3);
		cout<<max(ans1,ans2)<<'\n';
	}else if(n==2){
		int ans=0;
		for(int i=0;i<3;i++)for(int j=i+1;j<3;j++)
			ans=max(ans,q[1][i]+q[2][j]);
		cout<<ans<<'\n';
	}else{
		cout<<(int)sum/3<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}