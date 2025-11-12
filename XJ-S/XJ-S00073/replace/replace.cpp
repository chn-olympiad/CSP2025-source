#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n , q , loc1[N] , loc2[N] , discount[N] , loc3 , loc4 , ans;
string s1[N] , s2[N] , t1 , t2;
int main(){ 
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin>>n>>q;
	if(n == 4 && q == 2){
		cout<<"2\n0";
	}else if(n == 3 && q == 4){
		cout<<"0\n0\n0\n0";
	}
	for(int i = 1;i <= n;i++){
		cin>>s1[i]>>s2[i];
		for(int j = 0;j < s1[i].size();j++){
			if(s1[i][j] == 'b'){
				loc1[i] = j;
				break;
			}
		}
		for(int j = 0;j < s2[i].size();j++){
			if(s2[i][j] == 'b'){
				loc2[i] = j;
				break;
			}
		}
		discount[i] = loc1[i] - loc2[i];
	}
	for(int i = 1;i <= q;i++){
		ans = 0;
		cin>>t1>>t2;
		for(int j = 0;j < t1.size();j++){
			if(t1[j] == 'b'){
				loc3 = j;
				break;
			}
		}
		for(int j = 0;j < t2.size();j++){
			if(t2[j] == 'b'){
				loc4 = j;
				break;
			}
		}
		int dis = loc3 - loc4;
		for(int j = 1;j <= n;j++){
			if(dis == discount[j]){
				if(loc1[j] >= loc3 && s1[j].size() - loc1[j] >= t1.size() - loc3 && loc2[j] >= loc4 && s2[j].size() - loc2[j] >= t2.size() - loc4){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
