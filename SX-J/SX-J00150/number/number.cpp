#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s;
	cin>>s;
	int sum=0;
	for(int i=1;i<=s;i++){
		if(s>='a'&&s<='s'){
			s=s-s[i];
		}else {
			sum=s;
		}
	}
	sort(sum+1;sum+n+1);
	cout<<sum;
	return 0;
}