#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	int c=0;
	for(int i=0;i<n;i++){
		c+=i+1;
	}
	cout<<c;
	return 0;
}
