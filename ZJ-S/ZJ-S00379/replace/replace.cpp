#include<bits/stdc++.h>
using namespace std;
const int N=5000100;
long long ans;
vector<string>s1;
vector<string>s2;
//int ds[N];
signed main(){
	freopen("replace1.in","r",stdin);
	freopen("replace1.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
//		ds[i]=s1[i].size()-s2[i].size();
	}
//	cout<<-345;
	for(int j=1;j<=q;j++){
		ans=0;
		string t1;
		string t2;
		cin>>t1>>t2;
//		dss=t1.size()-t2.size();
		int ml=min(t1.size(),t2.size());
		int st=ml,ed=0;
		for(int i=0;i<=min(t1.size(),t2.size());i++){
			if(t1[i]!=t2[i]){
				st=i;
				break;
			}
		}
		for(int i=max(t1.size(),t2.size());i>=0;i--){
			if(t1[i]!=t2[i]){
				ed=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(t1.substr(st,ed-st+1).find(s1[i])!=-1)ans++;
		}
		cout<<ans;
	}
//	cout<<-11;
	return 0;
}

