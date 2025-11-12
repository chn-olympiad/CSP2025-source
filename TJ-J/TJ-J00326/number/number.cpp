#include <bits/stdc++.h> 

using namespace std;
long long a[1000005],cnt;
string s;
int xjb(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<s.size();i++){
		a[i] = -1;
		if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'){
			cnt++;
			a[i] = s[i]-48;
		}		
	}
	sort(a,a+s.size(),xjb);
	for(int i = 0;i<cnt;i++){
		cout<<a[i];
	}
	
	return 0;
}
