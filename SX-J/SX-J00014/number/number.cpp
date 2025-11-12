#include<bits/stdc++.h>
using namespace std;
int n;
string s;
struct Node{
	int num;
}a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='0') a[0].num++;
		if(s[i]=='1') a[1].num++;
		if(s[i]=='2') a[2].num++;
		if(s[i]=='3') a[3].num++;
		if(s[i]=='4') a[4].num++;
		if(s[i]=='5') a[5].num++;
		if(s[i]=='6') a[6].num++;
		if(s[i]=='7') a[7].num++;
		if(s[i]=='8') a[8].num++;
		if(s[i]=='9') a[9].num++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i].num;j++){
			cout<<i;
		}
	}
	printf("\n");
	return 0;
}