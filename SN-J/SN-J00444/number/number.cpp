#include<bits/stdc++.h>
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::string s;
	std::cin>>s;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(c>='0'&&c<='9'){
			int x=c-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			std::cout<<i;
		}
	}
	return 0;
}
