#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int length=s.size(),j=0;
	for(int i=0;i<length;i++){
		if(isdigit(s[i])){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--) cout<<a[i];
	return 0;
}
