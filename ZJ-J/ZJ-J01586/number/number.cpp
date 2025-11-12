#include<bits/stdc++.h>
using namespace std;
int sz[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for(int i = 0;i<a.size();i++){
		if(a[i]=='0'){
			sz[0]++;
		}else if(a[i]=='1'){
			sz[1]++;
		}else if(a[i]=='2'){
			sz[2]++;
		}else if(a[i]=='3'){
			sz[3]++;
		}else if(a[i]=='4'){
			sz[4]++;
		}else if(a[i]=='5'){
			sz[5]++;
		}else if(a[i]=='6'){
			sz[6]++;
		}else if(a[i]=='7'){
			sz[7]++;
		}else if(a[i]=='8'){
			sz[8]++;
		}else if(a[i]=='9'){
			sz[9]++;
		}
	}
	for(int i = 9;i>=0;i--){
		while(sz[i]--){
			cout << i;
		}
	}
	return 0;
}