//SN-J00049 余炜杰 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
char num[11451419];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			char a=s[i];
			num[cnt]=a;
			cnt++;
		}
	} 
	sort(num,num+cnt+1,cmp);
	for(int i=0;i<cnt+1;i++){
		cout<<num[i];
		
	}
	return 0;
}
