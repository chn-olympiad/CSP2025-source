#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
char a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin>>s;
	int cnt=0;
	if(s.size()==1){
		cout<<s;
	}else if(s.size()>1){
	for(int i=1; i<=N; i++){
		s=a[i];
	if(a[i]){
		cnt+=a[i];
	}else{
		continue;
	}
}
	cout<<cnt;
}
	return 0;
}