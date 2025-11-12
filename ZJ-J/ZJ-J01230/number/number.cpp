#include<bits/stdc++.h>
using namespace std;
#define int long long 
int ans[20];
int cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; 
	 
	int len=s.size();
	char k;
	while(cin>>k){
		int t=k-'0';
		if(t>=0 && t<=9)	ans[t]++;
	}
	for(int i=9;i>=0;i--){
		if(ans[i]){
			while(ans[i]){	
				cout<<i;
				ans[i]--;
			}
		}
	}
	
	
	return 0;
}
