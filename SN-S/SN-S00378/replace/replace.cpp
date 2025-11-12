#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<string,string> a[200005];
pair<int,int> ss1[200005],ss2[200005],sss1[200005],sss2[200005],pw131[200005]={{1,1}};
const int mod1=1e9+7,mod2=998244353;
pair<int,int> hashh(pair<int,int> p[],int l,int r){
	return {((p[r].first-p[l-1].first*pw131[r-l+1].first%mod1)%mod1+mod1)%mod1,((p[r].second-p[l-1].second*pw131[r-l+1].second%mod2)%mod2+mod2)%mod2};
}
int n,q;
void solve1(void){
	for(int i=1;i<=200000;i++) (pw131[i].first=pw131[i-1].first*131)%=mod1,(pw131[i].second=pw131[i-1].second*131)%=mod2;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].first.size();j++){
			(ss1[i].first=ss1[i].first*131+a[i].first[j])%=mod1;
			(ss1[i].second=ss1[i].second*131+a[i].first[j])%=mod2;
			(ss2[i].first=ss2[i].first*131+a[i].second[j])%=mod1;
			(ss2[i].second=ss2[i].second*131+a[i].second[j])%=mod2;
		}
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		s1=' '+s1,s2=' '+s2;
		for(int j=1;j<s1.size();j++){
			(sss1[j].first=sss1[j-1].first*131+s1[j])%=mod1;
			(sss1[j].second=sss1[j-1].second*131+s1[j])%=mod2;
			(sss2[j].first=sss2[j-1].first*131+s2[j])%=mod1;
			(sss2[j].second=sss2[j-1].second*131+s2[j])%=mod2;
		}
		int num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<s1.size();j++){
				if(sss1[j-1]==sss2[j-1]&&hashh(sss1,j+a[i].first.size(),s1.size()-1)==hashh(sss2,j+a[i].first.size(),s1.size()-1)&&hashh(sss1,j,j+a[i].first.size()-1)==ss1[i]&&hashh(sss2,j,j+a[i].first.size()-1)==ss2[i]){
					num++;
				}
			}
		}
		cout<<num<<'\n';
	}
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	solve1();
	return 0;
}
