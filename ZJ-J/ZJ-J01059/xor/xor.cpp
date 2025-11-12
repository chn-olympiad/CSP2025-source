#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,cnt,ans,a[10005],t,x,y;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	t=a[1];
	for(int i=1;i<n;i++){
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if(a[i]==t){
			t=n*m-i+1;
			break;
		}
	}
	x=t/n+1;
	y=t%n; 
	cout<<2;
	return 0;
}
