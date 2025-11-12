#include<bits/stdc++.h>
using namespace std;
string s;
long long l,a[1000005],idx=0,ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[idx]=s[i]-'0';
			idx++;
		}
	}
	sort(a,a+idx);
	for(int i=idx-1;i>=0;i--){
		cout<<(char)(a[i]+'0');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
