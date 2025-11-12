#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int a[15],sum,mx=-1,f;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			mx=max(mx,s[i]-'0');
		}
	}
	for(int i=mx;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
			f=1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

