#include<bits/stdc++.h>

using namespace std;
int n,m;
string s;
int a[505];
int ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			ans++;
		}
	}
	int num=n-ans;
	if(num>=m){
		int jishu=1;
		for(int i=1;i<=num;i++){
			jishu*=i;
		}
		cout<<jishu<<'\n';
	}
	else{
		cout<<0<<'\n';
	}
	
	return 0;
} 
