#include <bits/stdc++.h>
using namespace std;
string s;
long long num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		int x=(s[i]-'0');
		if(x>=0&&x<=9) num[x]++;
	}
	for(int i=9;i>=0;i--){
		while(num[i]>0){
			printf("%d",i);
			num[i]--;
		}
	}
	return 0;
}

