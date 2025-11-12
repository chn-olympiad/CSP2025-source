#include<bits/stdc++.h>
using namespace std;
int n[1000005],m[1000005],ber,z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		n[i]=s[i];
	}
	for(int i=0;i<s.size();i++){
		if(n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9'){
			m[0+ber]=n[i];
			ber++;
		}
	}
	for(int i=0;i<ber;i++){
		m[i]-=48;
	}
	for(int j=0;j<ber;j++){
		for(int i=0;i<ber;i++){
			if(m[i]<m[i+1]){
				z=m[i];
				m[i]=m[i+1];
				m[i+1]=z;
			}
		}
	}
	for(int i=0;i<ber;i++){
		cout<<m[i];
	}
	return 0;
}
