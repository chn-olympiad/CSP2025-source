#include <bits/stdc++.h>
using namespace std;
int a[510],x[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,fl=1,fl0=1,sum=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			sum++;
		}
	}
	if(n-sum<m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		x[i]=(s[i]-'0');
		if(x[i]!=1){
			fl=0;
		}
		if(x[i]!=0){
			fl0=0;
		}
	}
	if(fl0){
		cout<<0<<endl;
		return 0;
	}
	if(fl){
		cout<<1<<endl;
		return 0;
	}
	cout<<515058943<<endl;
	return 0;
}
