#include<bits/stdc++.h>
using namespace std;
int bj[20];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')bj[1]++;
		else if(s[i]=='2')bj[2]++;
		else if(s[i]=='3')bj[3]++;
		else if(s[i]=='4')bj[4]++;
		else if(s[i]=='5')bj[5]++;
		else if(s[i]=='6')bj[6]++;
		else if(s[i]=='7')bj[7]++;
		else if(s[i]=='8')bj[8]++;
		else if(s[i]=='9')bj[9]++;
		else if(s[i]=='0')bj[0]++;
	}
	for(int i=9;i>=0;i--){
		if(bj[i]!=0)for(int j=1;j<=bj[i];j++)cout<<i;
	}
	return 0;
} 
