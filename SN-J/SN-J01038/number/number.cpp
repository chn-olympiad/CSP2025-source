#include<bits/stdc++.h> 
using namespace std;
int sum[1005];
int main()
{
	//freopen('number.in','r',stdin);
	//freopen('number.out','w',stdout);
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<=n-1;i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=1){
		cout<<s[i];
}
}
	return 0;
}
