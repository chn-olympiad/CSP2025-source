#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[501];
int c[501];
int yipaozou[501] = {0};
int count;
int ans = 0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>s[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>c[i];
	}
	if(n == m){
			for(int i = 1;i <= n;i++){
			if(s[i] == 1){
				count++
			}
		}
		if (count == n){
		cout<<"1"<<endl;
	}
	else if(m == 1){
			
		for(int i = 1;i <= n;i++){
			if(s[i] == "1"){
				count++
			}
		}
		int paozou = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] = "0"||yipaozou[i] = 1){
				paozou++
				yipaozou[i] = 1
				for(int j = i + 1;j <= n;j++){
				if(paozou >= c[j]){
					yipaozou[j] = 1;
				}
			}
			}
		}
		if(count - paozou){
			ans++;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
