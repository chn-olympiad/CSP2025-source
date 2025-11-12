#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],k;
int main(){
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--) cout<<a[i];
	return 0;//#Shang4Shan3Ruo6SHui4
}
