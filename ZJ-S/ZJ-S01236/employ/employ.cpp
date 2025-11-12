#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[n];
	}
	int f=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') f=1;
	}
	if(!f){
		long long num=1;
		for(int i=1;i<=n;i++){
			num*=i;
		}
		cout<<num;
	}
	return 0;
}
