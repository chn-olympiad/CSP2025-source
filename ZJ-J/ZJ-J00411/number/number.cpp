#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[10],m=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			if(m==0)return 0;
			a[i]--;
			cout<<i;
			if(m==-1)m=i;
		}
	}
	return 0;
}
