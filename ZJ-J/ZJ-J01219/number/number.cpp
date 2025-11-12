#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--) cout<<a[i];
	return 0;
}
