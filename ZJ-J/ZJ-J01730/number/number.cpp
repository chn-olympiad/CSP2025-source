#include<iostream>
#include<cstdio>
using namespace std;
int h[128];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();++i)
		if('0'<=str[i]&&str[i]<='9')
			++h[str[i]];
	int sum=0;
	for(char i='9';i>='0';--i){
		//cout<<i<<' '<<h[i]<<endl;
		if(i=='0'&& !sum){
			cout<<i;
			break;
		}	
		while(h[i]--){
			cout<<i;
			++sum;
		}
	}
	return 0;
}
