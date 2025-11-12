#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[10000005],j=0,b[1000005];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			if(a[j]==48){
				b[j]=0;
			}
			if(a[j]==49){
				b[j]=1;
			}
			if(a[j]==50){
				b[j]=2;
			}
			if(a[j]==51){
				b[j]=3;
			}
			if(a[j]==52){
				b[j]=4;
			}
			if(a[j]==53){
				b[j]=5;
			}
			if(a[j]==54){
				b[j]=6;
			}
			if(a[j]==55){
				b[j]=7;
			}
			if(a[j]==56){
				b[j]=8;
			}
			if(a[j]==57){
				b[j]=9;
			}
			j++;
		}
	}
	sort(b,b+j);
	for(int i=j-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
