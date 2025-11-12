#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	string x,y;
}s[100005],t[100005];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].y;
	}
	if(q<=1e4){
	while(q--){
		string t,k;int cnt=0;
		cin>>t>>k;
		if(t.size()!=k.size()){
			cout<<0<<endl;
			continue;
		}
		for(int p=1;p<=n;p++){
		for(int i=0;i<t.size();i++){
			int j=i+s[p].x.size()-1;
			if(j>=t.size())break;
			if(t.substr(i,s[p].x.size())!=s[p].x)continue;
			if(k.substr(i,s[p].x.size())!=s[p].y)continue;
			if(t.substr(0,i)+s[p].y+t.substr(j+1,k.size()-j+1)!=k)continue;
			cnt++;
		}			
		}
		cout<<cnt<<endl;
	}
	return 0;
	}
	while(q--){
		cout<<"0\n";
	}
	return 0;
}

