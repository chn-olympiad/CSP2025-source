#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
long long cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[cnt]=s[i];
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(long long j=cnt-1;j>=0;j--){
		cout<<a[j];
	}
	return 0;
}
