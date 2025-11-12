#include<bits/stdc++.h>
using namespace std;
const int N=1e6+12;
int n=0;char s[N];
priority_queue<int> a;
void read(){
	for(int i=0;i<=strlen(s);i++){
		int x=int(s[i]-'0');
		if(x <= 9 && x>=0){a.push(x);n++;}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	read();
	for(int i=1;i<=n;i++){
		int x=a.top();a.pop();
		cout<<x;
	}
	return 0;
} 
