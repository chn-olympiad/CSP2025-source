#include <bits/stdc++.h>
using namespace std;
long long n,m,sum;
string s;
long long a[1000000];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
	return 0;
} 
