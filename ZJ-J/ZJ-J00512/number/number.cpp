#include<bits/stdc++.h>
constexpr int N=1e5+2,ln=0x0d000721;
std::string s;
int cnt[11];
int main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>s;
	for(char i:s){
		if(i>='0' and i<='9'){
			cnt[i-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			std::cout<<i;
		}
	}
}
//uid:942578
