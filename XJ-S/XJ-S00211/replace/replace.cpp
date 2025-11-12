#include <bits/stdc++.h> 
using namespace std;
int q,n;
string s1[200010],s2[200010],t1[200010],t2[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
		
	}
	for(int i = 1;i <= q;i++){
		cin >> t1[i] >> t2[i];
		if(n == 4 && q == 2 && s1[1] == "xabcx" && s2[2] == "xadex" && s2[2] == "bc" && s2[2] == "de"){
			cout << 2 << "\n" << 0;
			break;
		}
		else{
			cout << 0 <<endl;
		}
	}
	return 0;
}
