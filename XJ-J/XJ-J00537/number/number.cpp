#include<bits/stdc++.h>
using namespace std;
string s;
string s1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1[i]=s[i];
			x++;
		}
	}
	for(int i=0;i<x;i++){
		int y=1;
		if(x==1){
			cout<<s1[i]<<endl;
			return 0;
		}
		for(int j=0;j<x;j++){
			if(s1[i]<s1[i+y]){
				s1[i]=s1[i+y];
				s1[i+y]=s1[i];
			}
			y++;
			cout<<s1[i];
		}	
	}
	for(int i=0;i<x;i++){
		cout<<s1[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
