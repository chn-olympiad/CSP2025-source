#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[1010101];
int num[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	int len=strlen(c);
	for(int i=0;i<len;i++){
		if(c[i]>='0'&&c[i]<='9'){
			num[c[i]-'0']++;
		}	
	}
	for(int i=9;i>=0;i--){
		while(num[i]>0){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}