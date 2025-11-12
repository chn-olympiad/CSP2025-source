#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
void dfs(int i,string a,string b,string c,string d,int p,int k){
	if(i==a.size()){
		ans++;
		return;
	}
	if(p==c.size()){
		p=0;
		k=1;
	}
	if(a[i]!=b[i] or p>0){
		if(a[i]==c[p] and b[i]==d[p] and k==0){
			dfs(i+1,a,b,c,d,p+1,k);
		}
		else{
			return;
		}
	}
	else{
		if(a[i]==c[p] and b[i]==d[p] and k==0){
			dfs(i+1,a,b,c,d,p+1,k);
		}
		dfs(i+1,a,b,c,d,p,k);
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<string>a,b;
	for(int i=0;i<n;i++){
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;
		a.push_back(s1);
		b.push_back(s2);
	}
	for(int i=0;i<m;i++){
		string s1;
		string s2;
		cin>>s1;
		cin>>s2;
		int an=0;
		for(int j=0;j<n;j++){
			int f=1;
			int p=0;
			int k=0;
			for(int ii=0;ii<s1.size();ii++){
				ans=0;
				dfs(0,s1,s2,a[j],b[j],0,0);
			}
			an+=ans;
		}
		cout<<an<<endl;
	}
	return 0;
}
