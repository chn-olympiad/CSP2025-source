#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,m;
	cin>>s;
	int a = sizeof(s);
	for(int i = 0;i<a;i++){
		if(s[i]>0&&s[i]<98){
			m = s[i];
			cout<<m;													
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
