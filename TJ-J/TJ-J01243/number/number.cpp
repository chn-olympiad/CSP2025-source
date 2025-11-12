#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<10;i++)
	num[i]=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s.substr(i,1)=="9")
		num[9]++;
		if(s.substr(i,1)=="8")
		num[8]++;
		if(s.substr(i,1)=="7")
		num[7]++;
		if(s.substr(i,1)=="6")
		num[6]++;
		if(s.substr(i,1)=="5")
		num[5]++;
		if(s.substr(i,1)=="4")
		num[4]++;
		if(s.substr(i,1)=="3")
		num[3]++;
		if(s.substr(i,1)=="2")
		num[2]++;
		if(s.substr(i,1)=="1")
		num[1]++;
		if(s.substr(i,1)=="0")
		num[0]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++)
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
