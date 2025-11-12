#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n;
int a[5005];
long long ans[5005];
long long sum=0;
map<string,bool>v;
void dfs(int x,string s){
	if(x==n+1){
		if(!v[s]&&s.size()>=3){
			int cnt=0;
			v[s]=1;
			for(int i=0;i<s.size();i++){
				cnt+=a[s[i]-'0'];
			}
			if(cnt>a[s[s.size()-1]-'0']*2){
				sum++;
				sum%=M;
			}
		}
		return;
	}
	
	dfs(x+1,s+(char)(x+'0'));
	dfs(x+1,s);
}
void d(int x){
	for(int i=1;i<=x;i++){
		sum+=i;
		sum%=M;
	}
}
void dd(int x){
	for(int i=1;i<=n-x+1;i++){
		d(i);
		cout<<i<<'\n';
	}
}
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,"");
	cout<<sum<<'\n';
	return 0;
}