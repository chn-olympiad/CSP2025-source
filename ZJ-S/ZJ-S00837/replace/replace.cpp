#include<bits/stdc++.h>
using namespace std;
int n;
string a[200005],b[200005],x,y;
bool cmp(string s,string t,int w){
	bool res=1;
	int k=t.size();
	for(int i=0;i<k&&res;i++){
		if(t[i]!=s[i+w]){
			res = 0;
		}
	}
	return res;
}
int Solve(string s,string t2){
	int res=0;
	for(int i=1;i<=n;i++){
		if(a[i].size()>s.size()){
			continue;
		}
		int k=s.size(),l=a[i].size();
		for(int j=l;j<=k;j++){
			if(cmp(s,a[i],j-l)){
				for(int u=0;u<l;u++){
					s[u+j-l] = b[i][u];
				}
				if(s==t2){
					res++;
				}
				for(int u=0;u<l;u++){
					s[u+j-l] = a[i][u];
				}
			}
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<Solve(x,y)<<'\n';
	}
	return 0;
}
