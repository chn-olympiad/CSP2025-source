#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],k,t[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			//a[++k] = s[i]-'0';
			t[s[i]-'0']++;
		}
	}
	//sort(a,a+1+k);
	/*
	if(a[k]==0){
		cout << '0';
		return 0;
	}
	
	for(int i=k;i>=1;i--){
		cout << a[i];
	}
	*/
	int fl=0;
	for(int i=9;i>=0;i--){
		if(i!=0 && t[i]>0) fl=1;
		if(i==0 && fl==0){
			t[0]=1;
		}
		while(t[i]--) cout << i;
	}
	return 0;
}
