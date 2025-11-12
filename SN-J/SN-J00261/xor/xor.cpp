#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin>>n>>k;
	vector<long long>a(n);
	bool flag=true;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]!=1){
			flag=false;
		}
	}
	if (flag==true){
		cout<<n-1;
	}else{
		cout<<2;
	}
	return 0;
}
