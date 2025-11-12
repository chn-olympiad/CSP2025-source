#include<bits/stdc++.h>
using namespace std;
int n;
int a[10050];
stack<int>s;
int ans;
void dfs(int x){
	if(x>n){
		int mx=0;
		int sum=0;
		stack<int>s1;
		while(!s.empty()){
			s1.push(s.top());
			sum+=s.top();
			mx=max(s.top(),mx);
			s.pop();
		}while(!s1.empty()){
			s.push(s1.top());
			s1.pop();
		}
		if(sum>2*mx){
			ans++;
		}
		return;
	}dfs(x+1);
	s.push(a[x]);
	dfs(x+1);
	s.pop();
	return;
}
int main(){
	freopen("polygon.out","w",stdout);
	freopen("polygon.in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}