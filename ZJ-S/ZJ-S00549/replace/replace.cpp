#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	vector<string> s1(n),s2(n);
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		if(sizeof(t1)!=sizeof(t2)) cout<<0;
		else{
			for(int i=0;i<n;i++){
				int k=sizeof(s1[i]);
				cout<<0;
			}
		}
	}
	return 0;
}