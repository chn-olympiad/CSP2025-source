#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	cin>>str;
	int n=str.size();
	bool fa=0;
	sort(str.begin(),str.end());
	for(int i=n-1;i>=0;i--){
		if(str[i]>='0'&&str[i]<='9'){
			if(str[i]=='0'&&!fa){
				cout<<0;
				return 0;
			}
			else{
				cout<<str[i];
				fa=1;
			}
		}
	}
	if(!fa) cout<<0;
	

	fclose(stdin);
	fclose(stdout);
}
