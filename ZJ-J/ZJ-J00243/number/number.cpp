#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string k;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>k;
	int lk=k.length();
	int la=1;
	for(int i=0;i<lk;i++){
		if('0'<=k[i] and k[i]<='9'){
			a[la++]=k[i]-'0';
		}
	}
	la--;
	sort(a+1,a+la+1);
	for(int i=la;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
