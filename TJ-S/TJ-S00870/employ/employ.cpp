#include<bits/stdc++.h>
using namespace std;

string s;
int n , m , a[505];
int b[505];
int t[505];
long long ans = 0;
void huisu(int x , int num , int dis){
	if(x == n+1 && num >= m){
		ans++;
		return;
	}
	
	for(int i = 1;i <= n;i++){
		if(!t[i]){
			t[i] = 1;
			if(dis < b[i] && s[i] == '1'){
				huisu(x+1 , num+1 , dis);
			}else{
				huisu(x+1 , num , dis+1);
			}
			t[i] = 0;
		}
	}
}

int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	
	int num = n;
	for(int i = 1;i <= num;i++){
		cin >> b[i];
	}
	
	huisu(1 , 0 , 0);
	cout<<ans;
	
	return 0;
}
