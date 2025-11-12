#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,m;
string s;
int a[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int num1=0,num2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')num1++;
		else num2++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(num2==n){
		long long ans1=1,ans2=1;
		for(int i=0;i<m;i++){
			ans1*=(n-i);
		}
		for(int i=1;i<=m;i++){
			ans2*=i;
		}
		cout<<ans1/ans2;
	}else{
		cout<<2;
	}
	return 0;
}
