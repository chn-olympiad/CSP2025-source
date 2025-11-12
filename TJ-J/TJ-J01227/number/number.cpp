#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
	char s1[100];
	char s2[100];
	cin>>s;
	if(s.length()==1){
		cout<<s;
		return 0;
	}
    for(int d=1;d<=s.length();d++){
    	s[d]=s1[d];
	}
    for(int i=0;i<s.length();i++){
        if(s1[i]>='0'&&s1[i]<='9')
           break;
		else
			s1[i]=s2[i];
		cout<<max(s1[i],s2[i]);
		return 0;	
    }
    return 0;
}

