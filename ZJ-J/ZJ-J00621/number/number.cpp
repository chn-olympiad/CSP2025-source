#include<bits/stdc++.h>
using namespace std;
string s;
long long xz[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9')
			xz[int(s[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		while(xz[i]!=0){
			cout<<i;
			xz[i]--;
		}
	}
	return 0;
}