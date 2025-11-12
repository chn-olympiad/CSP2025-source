//SN-J00692
#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000006],a=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a++;
			num[a]=s[i]-'0';
		}
	}
	sort(num+1,num+1+a);
	for(int i=a;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
