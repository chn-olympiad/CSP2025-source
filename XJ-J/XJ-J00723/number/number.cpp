#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[100000]={0},la=0;
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
		    a[la]=(int)s[i]-48;
		    la++;
	    }
	}
	
	sort(a+0,a+la);
	for(int i=la-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
