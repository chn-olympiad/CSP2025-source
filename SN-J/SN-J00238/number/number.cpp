#include<bits/stdc++.h>
using namespace std;
string s;
int cnt = 1;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i = 0;i<n;i++){
		if(s[i] == '0'){
			b[cnt] += 0;
			cnt++;
			continue;
		}
		else if(s[i] == '1'){
			b[cnt] += 1;
			cnt++;
			continue;
		}
		else if(s[i] == '2'){
			b[cnt] += 2;
			cnt++;
			continue;
		}
		else if(s[i] == '3'){
			b[cnt] += 3;
			cnt++;
			continue;
		}
		else if(s[i] == '4'){
			b[cnt] += 4;
			cnt++;
			continue;
		}
		else if(s[i] == '5'){
			b[cnt] += 5;
			cnt++;
			continue;
		}
		else if(s[i] == '6'){
			b[cnt] = 6;
			cnt++;
			continue;
		}
		else if(s[i] == '7'){
			b[cnt] += 7;
			cnt++;
			continue;
		}
		else if(s[i] == '8'){
			b[cnt] += 8;
			cnt++;
			continue;
		}
		else if(s[i] == '9'){
			b[cnt] += 9;
			cnt++;
			continue;
		}
	}
	sort(b+1,b+1+cnt-1);
	for(int i = cnt-1;i>=1;i--){
		cout<<b[i];
	}
}
