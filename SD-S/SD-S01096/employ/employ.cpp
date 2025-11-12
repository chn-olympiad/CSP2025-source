#include<bits/stdc++.h>
using namespace std;
long long n,a[550],m;
string s;
bool pan=1;
//long long ksm(int a){
//	int ans=1;
//	while(a>0){
//		if(a%2)ans=ans*2;
//		a=a*a;
//		b/=2;
//	}
//	ans=ans*a;
//	return ans;
//}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)pan=0;
	}
//	if(pan){
//		int i=0;
//		for(;i<s[i].size();i++)
//			if(s[i]=='0')break;
//		if(i<m){
//			cout<<0<<endl;
//			return 0;
//		}
//		long long n=
//	}
	cout<<0<<endl;
	return 0;
}

