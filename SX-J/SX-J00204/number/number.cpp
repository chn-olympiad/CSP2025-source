#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	  freoepn("number.out","w",stdout);
	  getline(cin,s);
	  long long len=s.size(),p=0;
	  for(long long i=0;i<len;i++){
	  	if(s[i]>='0'&&s[i]<='9'){
	  		p++;
            a[p]=s[i]-'0';
		  }
	  }
      sort(a+1,a+p+1);
      for(long long i=p;i>=1;i--){
      	cout<<a[i];
	  }
}