#include<iostream>
using namespace std;
int main(){
	/*freopen("s","r",stdin);
	freopen("s","r",stdin);*/
	string s;
	int x=0;
	cin>>s;
	for(int i=0;i<s.size();i++){                                 
		if(s[i]>='0'&&s[i]<='9'){
		if(s[i+1]>s[i]){
			x=s[i];
			s[i]=s[i+1];
			s[i+1]=x;
		}
		}
		}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
	    cout<<s[i];
	}
	}
	/*fclose(stdout);
	fclose(stdout);*/
}


