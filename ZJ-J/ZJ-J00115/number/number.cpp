#include<bits/stdc++.h>
using namespace std;
int a[10];string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(char&i:s){
		if(isdigit(i)) a[i-48]++;
	}for(int i=9;i>=0;i--){
		while(a[i]--) putchar(i+48);
	}return 0;
}
