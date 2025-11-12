#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string s;
	int a[1000000],x=1,d=0;
	cin>>s;
	for(int i=1;i<=1000000;i++){
  		if(s[i]>='0'||s[i]<='9'){
			a[x]==s[i];
			d++;
		}
	}
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=d;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}