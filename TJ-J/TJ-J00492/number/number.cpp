#include <bits/stdc++.h>
#include <string>
using namespace std;

bool cmp(const int a,const int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
string s,num;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num+=s[i];
		}
	}
	sort(num.begin(),num.end(),cmp);
	cout<<num;
	fclose(stdin);
	fclose(stdout);
return 0;
}
