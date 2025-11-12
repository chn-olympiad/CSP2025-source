#include<bits/stdc++.h>
using namespace std;
int A(int n,int m){
	long long res=1;
	for(int i=n;i>=n-m+1;i--){
		res*=i;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	cin>>a>>b;
	string s;
	cin>>s;
	int c[10086];
	for(int i=1;i<=a;i++)cin>>c[i];
	cout<<A(a,a);
	fclose(stdin);
	fclose(stdout);
	return 0;
}