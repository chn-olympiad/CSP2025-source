#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010]={0};
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin>>s;
  int m=0;
  for(int i=0;i<=s.size()-1;i++){
  	if(!(s[i]>='a'&&s[i]<='z')){
  	  a[m]=s[i];
  	  m++;
	}
  }
  sort((a-1)+1,a+(m-1)+1);
  for(int i=m-1;i>=0;i--){
  	cout<<(char)a[i];
  }
return 0;
}
