#include<bits/stdc++.h>
using namespace std; 
const int N=1e6+5;
string s;
long long a[10];
int m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=1;i++){
		if(s[i]>='0' && s[i]<='9')
		a[s[i-'0']]++;
	}
	int w = 9;
	while(w!=0){
		if(a[w]>0){
			m = m*10+w;
		}
		else w--;
	}
	cout<<m;
	return 0;
}
