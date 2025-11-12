#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=1;i<=len;i++){
		if(s[i]%2==1||s[i]%2==0){
			if(s[i]<=10){
				cout<<s;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

