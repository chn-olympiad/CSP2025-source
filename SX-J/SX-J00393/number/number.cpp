#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.begin()+s.size()-1);
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
		}else{
			break;
		}
	}
	for(int i=x-1;i>=0;i--){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}