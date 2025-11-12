#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 1000005
using namespace std;

string s;
int a[MAXN];
int cx=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.length();
	for(int i=0;i<lens;i++){
	    if(s[i]>='0'&&s[i]<='9'){
	    	a[cx++]=s[i]-'0';
		}
	} 
	sort(a,a+cx+1);
	for(int i=cx;i>0;i--){
		cout<<a[i]; 
	} 
	return 0;
} 
