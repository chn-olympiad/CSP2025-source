#include <bits/stdc++.h>
using namespace std;
string s;
char a[10001]="";
long long r=0,e=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[e]=s[i];
			e++;
		}
	}
	sort(a,a+e+1,greater <int>());
	for(int i=0;i<=e;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
