#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s[1000005],a[1000005];

	for(int i=1;i<=100005;i++){
		cin>>s[i];
    }
    for(int i=1;i<=100005;i++){
    	if(s[i]<="9"&&s[i]>="0"){
    		cout<<s[i];
		}
	}
	return 0;
}