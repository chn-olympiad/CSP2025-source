#include <bits/stdc++.h>
#include <cstdio> 
using namespace std;
const long long N=2000010;
long long a[N];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long ae=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ae++;
			a[ae]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+1+ae,cmp);
	for(int i=1;i<=ae;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
