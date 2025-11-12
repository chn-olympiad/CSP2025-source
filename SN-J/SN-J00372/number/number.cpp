#include<bits/stdc++.h>
using namespace std;
string s;
string sz;
long long k,a,num;
int main(){	
	freopen("number3.in","r",stdin);
	freopen("number3.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			sz[k]=int(s[i]);
			k++;
			
		}
	}
	for(int h=0;h<k;h++){
		int m=int(sz[0]);
		for(int j=0;j<k;j++){
			if(m<=sz[j]){
				m=sz[j];
				num=j;
			}		
		}
		cout<<char(m);
		sz[num]=' ';
	}
	return 0;
}

