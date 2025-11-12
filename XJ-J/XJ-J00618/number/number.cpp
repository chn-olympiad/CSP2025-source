#include<bits/stdc++.h>
using namespace std;
char cnt[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int se=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[se]=s[i];
			se++;
		}
	}
	sort(cnt,cnt+se);
	for(int i=se;i>=0;i--){
		cout<<cnt[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
