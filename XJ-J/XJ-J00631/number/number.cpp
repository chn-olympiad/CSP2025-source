#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+5;
int a[N],n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0')a[n]=0;
			if(s[i]=='1')a[n]=1;
			if(s[i]=='2')a[n]=2;
			if(s[i]=='3')a[n]=3;
			if(s[i]=='4')a[n]=4;
			if(s[i]=='5')a[n]=5;
			if(s[i]=='6')a[n]=6;
			if(s[i]=='7')a[n]=7;
			if(s[i]=='8')a[n]=8;
			if(s[i]=='9')a[n]=9;
		n++;
		}
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<n;i++)cout<<a[i];
	return 0;
}
