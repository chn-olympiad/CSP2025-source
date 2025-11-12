#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string str1[n+5],str2[n+5];
	for(int i=0;i<n+q;i++){
		cin >> str1[i] >> str2[i];
	}
	int cnt = 0;
	for(int i=0;i<n+q;i++){
		for(int j=0;j<str1[i].size();j++){
			if(str1[i][j] != str2[i][j]){
				cnt ++;
			}
		}
	}
	cout << cnt/2;
	return 0; 
} 
