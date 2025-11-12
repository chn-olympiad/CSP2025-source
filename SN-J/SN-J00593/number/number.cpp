#include<bits/stdc++.h>
using namespace std;
string s;
int a[10001]
int main(){
	speope("number.in","s",stdin);
	speope("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<10001;i++){
		if(s[i]0>=10){
			a[i]=s[i];
			if(a[i]>a[i+1]){
				stop(a[i+1],a[i]);
			}
		}
		for(int j=1;j<10001;j++){
			cout<<a[j];
		}
	}
	return 0;
}
