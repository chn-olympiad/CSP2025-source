#include<iostream> 
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,z;
	cin>>s;
	int a=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			z+=s[i];
		}
	}for(int i=0;i<=z.size();i++){
		if(z[i]>a){ 
			cout<<z[i];
		} 
	}
	return 0;
}
