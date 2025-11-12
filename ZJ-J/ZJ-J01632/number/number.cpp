#include<bits/stdc++.h>
//#define int long long 
using namespace std;
string q;
int n,t[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>q;
	n=q.length();
	for(int i=0;i<n;i++){
		if('0'<=q[i]&&q[i]<='9'){
			t[q[i]-'0']++;
			
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++)cout<<i;
	}
	return 0;
}
//operator
//priority_queue<int> q;
