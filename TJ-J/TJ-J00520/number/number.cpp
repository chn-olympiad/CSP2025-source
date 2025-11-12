#include<bits/stdc++.h>
using namespace std;
string s;
long long int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s[i] = a[i];
		}
	}
	sort(a+1,a+s.size()+1);
	for(int i=a[i-1];i>=0;i--){
		cout<<i;
	}
	return 0;
} 
