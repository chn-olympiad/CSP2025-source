#include<bits/stdc++.h>
using namespace std;
int a,b,n[500010],m[500010],x,s1,s2,s[2200000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>n[i];
		m[i]=m[i-1]^n[i];
	}
	s[0]=1;
	for(int i=1;i<=a;i++){
		s2^=n[i];
		if(s[s2^b]){
			s1++;
			for(int j=x;j<i;j++){
				s[m[j]]--;
			}
			x=i;
		}
		s[m[i]]++;
	}
	cout<<s1;
	return 0;
}
