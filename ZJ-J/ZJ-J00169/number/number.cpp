#include<bits/stdc++.h>
using namespace std;
string s;
int k[100005];
long long num = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0;i<n;i++){
		char comp = s[i];
		if(comp<'a'){
			num++;
			k[num] = comp;
	}	
}
		sort(k+1,k+num+1);
		char a = 0;
		for(long long i = num;i>0;i--){
			a = k[i];
			cout<<a;
			}
		

	return 0;
}
