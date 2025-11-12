#include<bits/stdc++.h> 
using namespace std;
const int N=30;
int a[N];
string s,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	const int len=s.size(); 
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(int)(s[i]-'0')]++;
		}
	} 
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			ans+=(char)(i+'0');
			a[i]--;
		}
	}
	cout<<ans;
	return 0;
}
