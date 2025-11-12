#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1[200001],s2[200001],t1[200001],t2[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		cin>>t1[i]>>t2[i];
		for(int j=1;j<=n;j++){
			int f=t1[i].find(s1[j]);
			if(f!=-1){
				t1[i].erase(f,s1[j].size());
				t1[i].insert(f,s2[j]);
				if(t1[i]==t2[i]) cnt++;
				t1[i].erase(f,s2[j].size());
				t1[i].insert(f,s1[j]);
			}
		}
		cout<<cnt;
	}
	return 0;
}
