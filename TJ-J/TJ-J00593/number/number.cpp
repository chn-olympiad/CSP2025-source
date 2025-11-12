#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[100010];
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	
	
	sort(a,a+s.size(),greater<int>());
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
