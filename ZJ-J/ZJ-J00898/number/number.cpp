#include<bits/stdc++.h>
using namespace std;
char ch;
int b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(1){
		ch=getchar();
		if(ch=='\n'||ch==' '){
			break;
		}if(ch<='9'&&ch>='0'){
			b[ch-'0']++;
		}
	}for(int i=9;i>=0;i--){
		while(b[i]--){
			cout<<i;
		}
	}
	return 0;
}

