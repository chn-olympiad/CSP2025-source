#include<bits/stdc++.h>
using namespace std;
const int maxx = 1e6 + 5;
int ans[maxx];
bool cmp(int ll , int rr){
	return ll > rr;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int l = s.size();
	int l1 = 0;
	for(int i = 0 ; i < l ; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			l1++;
			ans[l1] = s[i] - '0';
		}
	}
	sort(ans+1,ans+l1+1,cmp);
	for(int i = 1 ; i <= l1 ; i++){
		printf("%d",ans[i]);
	}
    fclose(stdin);fclose(stdout);
	return 0;
}
