#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	bool is_all_zero=1;
	string s;
	vector<int> cnt(20,0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]!='0'){
				is_all_zero=0;
			}
			cnt[s[i]-'0']++;
		}
	}
	if(is_all_zero){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
}
