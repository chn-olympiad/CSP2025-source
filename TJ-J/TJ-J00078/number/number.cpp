#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if("A"<=s[i]&&s[i]<="Z"||"a"<=s[i]&&s[i]<="z"){
			continue;
		}
		sort(a+s[1],a+s[s.size()],cmp);
		
	}
	cout<<s;
}
