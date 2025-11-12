#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int cnt=0;
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&'9'>=s[i]){
			a[int(s[i]-'0')]++;
			cnt++;
		}
	}
	if(cnt==a[0]){
		cout<<0;	
	}else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				printf("%d",i);
			}//o(n)
		}
	}	
	return 0;
}
