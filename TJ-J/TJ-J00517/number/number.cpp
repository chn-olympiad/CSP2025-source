#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string s;
bool cmp(int x,int y){
	return x>y;
}
long long cnt[N],u=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[u]=int(s[i]-'0');
			u++;
		}
	}
	sort(cnt+1,cnt+u+1,cmp);
	for(int i=1;i<u;i++){
		cout<<cnt[i];
	}
	return 0;
} 
