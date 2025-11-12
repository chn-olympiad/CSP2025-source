#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int main(){
	freopen("number2.in ","r",stdin);
	freopen("number2.out ","w",stdout);
	cin>>s;
	int len=s.size();
	int j=0;
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	} 
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
