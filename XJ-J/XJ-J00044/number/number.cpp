#include <bits/stdc++.h>
using namespace std;
int s,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s>>n;
	if(s>n){
		cout<<s<<n;
	}else{
		cout<<n<<s;
	}
	return 0;
}
