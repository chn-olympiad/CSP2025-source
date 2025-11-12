//王乙丞 西安滨河学校 SN-J00708 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int Wang1[10000005];
int Wang2 = 1;
string Wang3;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> Wang3;
	for (int i = 0;i < Wang3.size();i++){
		if (Wang3[i] <= '9' && Wang3[i] >= '0'){
			Wang1[Wang2] = Wang3[i] - '0';
			Wang2++;
		}
	}
	Wang2--;
	sort(Wang1+1,Wang1+Wang2+1);
	for (int i = Wang2;i >= 1;i--){
		cout << Wang1[i];
	}
	return 0;
}
