#include<bits/stdc++.h>
using namespace std;
const int N=100005;
char a[N];
int main(){
	freopen("number.in","r",stdin);//Ñî×ÓÒµ 
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=0;
	long long j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j]=s[i];
		//cout<<s[i]<<" ";
		//	cout<<a[j]<<" ";
			n++;
			j++;
		}
		
	}

	for(int i=0;i<n;i++){
		a[i]=a[i]-48;
		//cout<<a[i]<<" ";
	}
	sort(a,a+n);
		for(int i=n-1;i>=0;i--){
	
		cout<<(int)(a[i]);
	}
	return 0;
}
