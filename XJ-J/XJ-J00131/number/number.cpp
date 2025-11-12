#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int a[maxn],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=(int)s[i]-48;
			k++;
		}
	}
	sort(a,a+k+1,greater<int>());
	for(int i=0;i<k;i++){     
		cout<<a[i];
	}
	return 0;
} 
