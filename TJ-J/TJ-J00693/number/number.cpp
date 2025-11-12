#include <bits/stdc++.h>
using namespace std;
#define int long long
string n;
int a[1000005],top;
bool aaa(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[top++]=n[i]-48;
		}
	}
	sort(a,a+top,aaa);
	for(int i=0;i<top;i++){
		cout<<a[i];
	}
	return 0;
}
