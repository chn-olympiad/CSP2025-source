#include<bits/stdc++.h>
using namespace std;
int f(int x){
int ans=1;
	for(int i=1;i<=x;i++)ans*=i;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<f(n);
}
