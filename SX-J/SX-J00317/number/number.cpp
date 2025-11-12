#include<bits/stdc++.h>
using namespace std;
long long a[1000010],ans0=0,ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0,ans7=0,ans8=0,ans9=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]-'0'==0){
			ans0++;
		}
		if(s[i]-'0'==1){
			ans1++;
		}
		if(s[i]-'0'==2){
			ans2++;
		}
		if(s[i]-'0'==3){
			ans3++;
		}
		if(s[i]-'0'==4){
			ans4++;
		}
		if(s[i]-'0'==5){
			ans5++;
		}
		if(s[i]-'0'==6){
			ans6++;
		}
		if(s[i]-'0'==7){
			ans7++;
		}
		if(s[i]-'0'==8){
			ans8++;
		}
		if(s[i]-'0'==9){
			ans9++;
		}
	}
	for(int i=1;i<=ans9;i++) cout << 9;
	for(int i=1;i<=ans8;i++) cout << 8;
	for(int i=1;i<=ans7;i++) cout << 7;
	for(int i=1;i<=ans6;i++) cout << 6;
	for(int i=1;i<=ans5;i++) cout << 5;
	for(int i=1;i<=ans4;i++) cout << 4;
	for(int i=1;i<=ans3;i++) cout << 3;
	for(int i=1;i<=ans2;i++) cout << 2;
	for(int i=1;i<=ans1;i++) cout << 1;
	for(int i=1;i<=ans0;i++) cout << 0;
	return 0;
}