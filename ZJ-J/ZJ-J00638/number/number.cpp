//#Shang4Shan3Ruo6Shui4
#include <bits/stdc++.h>
using namespace std;
string s,ans;
int k;
char a[1000010];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			k++;
			a[k]=s[i];
		}
	}
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		ans+=a[i];
	}
	cout<<ans;
	
	return 0;
}
