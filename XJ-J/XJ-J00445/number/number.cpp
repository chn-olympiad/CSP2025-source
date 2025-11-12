#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
	char s[1000001];
	cin >>s;
	for(int i=1;i<=1000001;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]<s[i+1])
				sum+=s[i+1]+s[i];
		}
		else
			break;
	}
	cout <<sum<<endl;
	return 0;
}
