#include<bits/stdc++.h>
using namespace std;
const int N=11;
string s;
int tot,a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			a[i]--;
			printf("%d",i);
		}
	}
	return 0;
}
