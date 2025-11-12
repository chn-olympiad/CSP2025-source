#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
const int N=1e5+5;
int n,a[N][5];
int boom;
int cha(int x){
	int chax=1e9;
	for(int i=1;i<=3;i++){
		if(i==boom)	continue;
		chax=min(chax,a[x][boom]-a[x][i]);
	}
	return chax;
}
bool cmp(int x,int y){
	return cha(x)>cha(y);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i][1]>>a[i][2]>>a[i][3];
	int sum=0;
	vector<int>cnt[5];
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])	sum+=a[i][1],cnt[1].push_back(i);
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])	sum+=a[i][2],cnt[2].push_back(i);
		else	sum+=a[i][3],cnt[3].push_back(i);
	}
	if(cnt[1].size()>n/2)	boom=1;
	else if(cnt[2].size()>n/2)	boom=2;
	else if(cnt[3].size()>n/2)	boom=3;
	else{
		cout<<sum<<"\n";
		return;
	} 
	sort(cnt[boom].begin(),cnt[boom].end(),cmp);
	while(cnt[boom].size()>n/2){
		sum-=cha(cnt[boom].back());
		cnt[boom].pop_back();
	}
	cout<<sum<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)	solve();
	return 0;
}
