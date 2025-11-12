#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bx[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9') bx[s[i]-'0']++;
	bool fg=0;
	for(int i=9;i>=1;i--)
		if(bx[i]!=0){
			fg=1;
			while(bx[i]--) printf("%d",i);
		}
	if(!fg) printf("0");
	else {
		while(bx[0]--) printf("0");
	}
	return 0;
}
