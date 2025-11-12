#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10,P=998244353;
vector<int>s1,s2,s3;
bool cmp(int a,int b){
	return a>b;
}
void slove(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a>b&&a>c) s1.push_back(a-max(b,c));
		if(b>a&&b>c) s2.push_back(b-max(a,c));
		if(c>a&&c>b) s3.push_back(c-max(a,b));
		ans+=max(a,max(b,c));
	}
	if(s1.size()>n/2){
		sort(s1.begin(),s1.end(),cmp);
		while(s1.size()>n/2){
			ans-=s1.back();
			s1.pop_back();
		}
	}
	if(s2.size()>n/2){
		sort(s2.begin(),s2.end(),cmp);
		while(s2.size()>n/2){
			ans-=s2.back();
			s2.pop_back();
		}
	}
	if(s3.size()>n/2){
		sort(s3.begin(),s3.end(),cmp);
		while(s3.size()>n/2){
			ans-=s3.back();
			s3.pop_back();
		}
	}
	cout<<ans<<endl;
	s1.clear();
	s2.clear();
	s3.clear();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) slove();
	return 0;
}
//CSP-S2025 rp++
//14:45 xie wan bing tiao wan
//15:00 xie wan dui pai
