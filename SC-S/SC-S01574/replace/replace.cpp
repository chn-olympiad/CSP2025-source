#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string s[n][2];
	string a[q][2];
	for(int i=0;i<n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	int an[q]={0};
	for (int i=0;i<q;i++){
		cin >> a[i][0] >> a[i][1];
		for (int j=0;j<n;j++){
			if(s[j][0]==a[i][0] && s[j][1]==a[i][1]){
				an[i]++;
			}
		}
	}
	for(int i=0;i<q;i++){
		cout << 2*an[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}