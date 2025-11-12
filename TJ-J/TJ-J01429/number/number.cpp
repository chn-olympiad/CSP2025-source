#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+7;
ll a[maxn]={},i,j,len,number_count;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	len = s.size();
	for(i = 0;i < len;i++){
		if(s[i]>='0' && s[i]<='9'){
			if(s[i]=='1'){
				a[i]=1;
			}else if(s[i]=='2'){
				a[i]=2;
			}else if(s[i]=='3'){
				a[i]=3;
			}else if(s[i]=='4'){
				a[i]=4;
			}else if(s[i]=='5'){
				a[i]=5;
			}else if(s[i]=='6'){
				a[i]=6;
			}else if(s[i]=='7'){
				a[i]=7;
			}else if(s[i]=='8'){
				a[i]=8;
			}else if(s[i]=='9'){
				a[i]=9;
			}
			number_count++;
		}
	}
	for(i=1;i<len;i++){
		for(j=0;j<len;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(i=0;i<number_count;i++){
		cout << a[i];
	}
	return 0;
} 


