#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<string,string> a[200010];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1.size()-a[i].first.size()+1;j++){
				string t=s1;
				bool flag=true;
				for(int k=j;k<j+a[i].first.size();k++){
					if(t[k]!=a[i].first[k-j])flag=false;
				}
				if(flag==false)continue;
				for(int k=j;k<j+a[i].first.size();k++){
					t[k]=a[i].second[k-j];
				}
				if(t==s2)cnt++;
			}
		}
		cout<<cnt<<endl;
	} 
	return 0;
}


