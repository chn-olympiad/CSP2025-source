#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string a[200005],b[200005],t1,t2,t3;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++) cin >> a[i] >> b[i];
	while (q--){
		long long cnt = 0;
		cin >> t1 >> t2;
		for (int i = 1;i <= n;i++){
			t3 = t1;
			if (a[i].size() > t3.size()) continue;
			for (int j = 0;j <= t3.size()-a[i].size();j++){
				if (t3[j] == a[i][0]){
					for (int k = 0;k < a[i].size();k++)
						if (a[i][k] != t3[j+k]) break;
					for (int k = 0;k < a[i].size();k++) t3[j+k] = b[i][k];
					break;
				}
			}
			if (t3 == t2) cnt++;
		}
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
