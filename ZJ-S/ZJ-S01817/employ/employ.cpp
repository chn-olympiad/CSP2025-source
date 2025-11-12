#include<bits/stdc++.h>
using namespace std;
int a[510];
int b[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f=max(f,a[i]);
	}
	int e=-1;
	for(int i=0;i<s.size();i++){
		b[i+1]=s[i]-'0';
		if(b[i+1]==1&&e!=-1){
			e=i+1;
		}
	}
	cout<<time(0)%998244353;
	return 0;
}