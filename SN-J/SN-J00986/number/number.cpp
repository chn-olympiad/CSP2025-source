#include<bits/stdc++.h>
using namespace std;
string s;
int x[1000001],b=0;
main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x[b]=s[i]-'0';
			b++;
		}
	}
	sort(x,x+b);
	for(int i=b-1;i>=0;i--){
		cout<<x[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
