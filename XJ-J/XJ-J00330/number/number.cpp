#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char n;
	cin>>n;
	int cnt=0;
	for(int i=0;i<=n;i++){
		cnt++;
	}
	if('0'<=cnt<='9'){
			cout<<cnt-49;
		}
	return 0;
}
