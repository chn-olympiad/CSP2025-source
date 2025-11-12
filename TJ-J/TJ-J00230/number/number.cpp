#include <bits/stdc++.h>
using namespace std;
int a[1000005],j;
string s,s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>s;
int l=s.size();
for(int i=0;i<l;i++){
	if(s[i]=='0'){
		s0+=s[i];
	}
	if(s[i]=='1'){
		s1+=s[i];
	}
	if(s[i]=='2'){
		s2+=s[i];
	}
	if(s[i]=='3'){
		s3+=s[i];
	}
	if(s[i]=='4'){
		s4+=s[i];
	}
	if(s[i]=='5'){
		s5+=s[i];
	}
	if(s[i]=='6'){
		s6+=s[i];
	}
	if(s[i]=='7'){
		s7+=s[i];
	}
	if(s[i]=='8'){
		s8+=s[i];
	}
	if(s[i]=='9'){
		s9+=s[i];
	}
}
cout<<s9<<s8<<s7<<s6<<s5<<s4<<s3<<s2<<s1<<s0;
return 0;
}
