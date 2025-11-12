#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int s[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i = 0;i<a.size();i++){
		if(!(a[i]>='a'&&a[i]<='z')){
			s[++n] = a[i] - '0';
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i = 1;i<=n;i++){
		cout<<s[i];
	}
	return 0;
}
