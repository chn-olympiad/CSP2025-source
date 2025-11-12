#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int b[100002];
int sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[sum]=s[i];
			sum++;
		}if(i>=1000000){
			break;
		}
	}	cout<<a[sum];
	return 0;
} 
