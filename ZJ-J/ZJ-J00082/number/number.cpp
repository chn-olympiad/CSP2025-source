#include<iostream>
#include<cstring>
#include<string>
int tmp[11];
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin>>t;
	int siz=t.size();
	
	for(int i=0;i<siz;i++){
		if(t[i]>='0'&&t[i]<='9'){
			tmp[t[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tmp[i];j++){
			cout<<i;
		}
	}
	return 0;
}
