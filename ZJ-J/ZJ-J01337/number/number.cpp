#include<bits/stdc++.h>
using namespace std;
long long a[10];int i;
char s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	while(cin>>s){
		if('0'<=s && s<='9')a[s-'0']++;
	}
	
	for(i=9;i>=0;i--){
		if(a[i]){
			while(a[i]--)cout<<i;
		}
	}
	
	return 0;
}
