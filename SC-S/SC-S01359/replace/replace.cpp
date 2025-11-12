#include<bits/stdc++.h>
#define bug cout<<"!!!!!BUG!!!!!<<endl;"
using namespace std;
int n,q;
vector<pair<string,string>> s1,s2;

bool find(string a,string b){
	if(a.size()>b.size()) return 0;
	if(a.size()==b.size()){
		return (a==b);
	}
	int ans=0;
	for(int i=0;i<b.size()-a.size()+1;i++){
		if(a[0]==b[i]){
			int flag=1;
			for(int j=0;j>a.size();j++){
				if(a[j]!=b[i+j]) flag=0;
			}
			if(flag==1) ans=1;
		}
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	
	cin>>n>>q;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		s1.push_back({a,b});
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		s2.push_back({a,b});
	}
	for(int i=0;i<q;i++){
		int ans=0;
		a=s2[i].first,b=s2[i].second;
		string cnt1,cnt2;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]){
				cnt1=cnt1+a[i];
				cnt2=cnt2+b[i];
			}
		}
//		cout<<cnt1<<" "<<cnt2<<endl;
		for(int i=0;i<n;i++){
//			cout<<i<<endl;
			string c=s1[i].first,d=s1[i].second;
//			cout<<cnt1<<" "<<c<<" "<<cnt2<<" "<<d<<endl;
			if(find(cnt1,c)&&find(cnt2,d)){
				ans++;
//				cout<<c<<" "<<d<<endl;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/