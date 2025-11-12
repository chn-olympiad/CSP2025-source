#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long int a[N];
long long int k;
string s;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]-'0'<=9 && s[i]-'0'>=0){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k,greater<int>());
	string s1;
	for(int i=1;i<=k;i++){
		s1+=a[i]+'0';
	}
	cout<<s1<<endl;
	return 0;
} 
