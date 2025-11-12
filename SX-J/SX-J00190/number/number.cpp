#include<bits/stdc++.h>
using namespace std;
long long a[100000],j=0,l1;
string s,s1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l1=s.size();
	for(long long i=0;i<l1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}for(long long i=0;i<j;i++){
		for(long long k=i;k<j;k++){
			if(a[k]<a[i]){
				swap(a[k],a[i]);
			}
		}
	}for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}return 0;
}