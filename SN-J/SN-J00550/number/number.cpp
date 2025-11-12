#include<bits/stdc++.h>
using namespace std;
string s;
int num[100005],zz;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>s;
int l=s.length();
for(int i=0;i<l;i++){
	if(s[i]>='0'&&s[i]<='9'){
		num[zz]=s[i]-'0';
		zz+=1;
	}
}
sort(num,num+zz,cmp);
for(int i=0;i<zz;i++){
	cout<<num[i];
}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
