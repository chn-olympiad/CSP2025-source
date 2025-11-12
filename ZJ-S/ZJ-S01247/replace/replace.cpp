#include <bits/stdc++.h>
using namespace std;
long long n,q;
string l[200005][2];
int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(long long i = 1;i<=n;i++){
		cin >> l[i][0] >> l[i][1];
	}
	while(q--){
		string str1,str2;
		cin >> str1 >> str2;
		if(str1.size()!=str2.size()){
			cout << "0\n";
			continue;
		}
		bool flag = 0;
		long long finish = 0;
		for(long long i = 0;i<str1.size();i++){
			if(str1[i]!=str2[i]){
				if(i==0 || str1[i-1] == str2[i-1] && flag != 0){
					cout << "0\n";
					break;
				}else{
					flag = 1;
					finish = i;
				}
			}
		}
		if(flag==0){
			continue;
		}
		long long ans = 0;
		for(long long j = 1;j<=n;j++){//l
			for(long long start = 0;start<=finish;start++){
				flag = 1;
				for(long long x=0;x<l[j][0].size();x++){
					if(str1[start+x] == l[j][0][x] && str2[start+x] == l[j][1][x]){
						
					}else{
						flag = 0;
						break;
					}
				}
				if(flag==1){
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
