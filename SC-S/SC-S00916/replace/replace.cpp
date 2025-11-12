#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[1003][2];
bool p(int l,string s1,string s2,int u){
	for(int i=0;i<-1;i++)
		if(a[u][0][i+l]!=s1[i]||a[u][1][i+l]!=s2[i])
			return false;
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1];
	for(int i=0;i<q;i++){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<=n-a[i][0].size();j++)
				if(p(j,s1,s2,i))
					ans++;
		cout<<ans;
		continue;
	}
	return 0;
}