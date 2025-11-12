#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.size();
	int j = 1;
	for(int i = 0;i<l;i++){
		if(s[i] == '0'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '1'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '2'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '3'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '4'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '5'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '6'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '7'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '8'){
			a[j] = s[i]-'0';
			j++;
		}
		if(s[i] == '9'){
			a[j] = s[i]-'0';
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1);
	for(int i = j;i>=1;i--){
		cout<<a[i];
	}
}

