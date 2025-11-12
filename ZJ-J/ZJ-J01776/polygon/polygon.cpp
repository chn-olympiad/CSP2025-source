#include<bits/stdc++.h>
using namespace std;
int n, a[10000], book[10000];
stack<int> st;
stack<int> st1;
long long ans, sum;
const int m=998244353; 
bool check(){
	if(st.size()<3) return 0;
	int t=st.top();
	sum=0;
	st1.push(t);
	st.pop();
	int admn=t;
	while(!st.empty()){
		int t=st.top();
		st1.push(t);
		sum+=t;
		st.pop();
	}
	while(!st1.empty()){
		int t=st1.top();
		st.push(t);
		st1.pop();
	}
	if(sum>admn) return 1;
	else return 0;
}
void dp(int k){
	for(int i=k+1;i<=n;i++){
		st.push(a[i]);
		if(check()) ans=ans%m+1;
		dp(i);
		st.pop();
	}
	return;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	dp(0);
	cout << ans;
}