#include<bits/stdc++.h>
using namespace std; 
int n; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	if (n<10){
		cout<<n;
	}else if(n>=10&&n<=99){
		cout<<max(n/10,n%10)*10+min(n/10,n%10);
	}
	return 0;
}
