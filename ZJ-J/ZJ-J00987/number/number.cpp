#include<bits/stdc++.h>
using namespace std;
int k,a[1000006];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++)cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

