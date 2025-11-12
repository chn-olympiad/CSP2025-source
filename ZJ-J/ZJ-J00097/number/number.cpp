#include<bits/stdc++.h>
using namespace std;
string a;
int v,t[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;a=" "+a;
	int n=a.size();
	for(int i=1;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9')t[++v]=a[i]-'0';
	}stable_sort(t+1,t+v+1,greater<int>());
	for(int i=1;i<=v;i++)cout<<t[i];
	return 0;
}
