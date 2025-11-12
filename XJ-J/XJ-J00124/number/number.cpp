#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n[15]={0};
	int i,j,l,max;
	cin>>s;
	l=s.size();
	for(i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[s[i]-'0']++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
