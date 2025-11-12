#include<bits/stdc++.h>
using namespace std;
string a;
int na,b[1000010],t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	na=a.size();
	for(int i=0;i<na;i++){
		if(a[i]>=48&&a[i]<97){
			t++;
			b[t]=a[i]-48;
		}
	}
	sort(b+1,b+t+1);
	for(int i=t;i>=1;i--){
		cout<<b[i];
	}
}