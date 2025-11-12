#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
const int xx=505;
int a[xx];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long t1=1;
	for(int i=n;i>=n-m+1;i--){
		t1*=i;
	} 
	long long t2=1;
	for(int i=m;i>=1;i--){
		t2*=i;
	} 
	cout<<t1/t2<<"\n";
	return 0;
}
