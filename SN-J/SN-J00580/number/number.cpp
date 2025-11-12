#include<bits/stdc++.h>
using namespace std;
string s;
int a[15],ans=0,z;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	z=pow(10,a[0]);
	if(z==0) z=1;
	for(int i=1;i<=9;i++){
		while(a[i]>0){
			ans+=i*z;
			z*=10;
			a[i]--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
