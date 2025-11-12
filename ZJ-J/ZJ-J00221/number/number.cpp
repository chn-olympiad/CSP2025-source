#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
string s;int a[N],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans++]=s[i]-'0';
		}
	}
	sort(a,a+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
