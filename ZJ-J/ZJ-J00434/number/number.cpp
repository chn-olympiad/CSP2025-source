#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x;i<=y;i++)
map<int,int> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	f(i,0,len-1){
		if(s[i]>='0' && s[i]<='9'){
			mp[int(s[i]-'0')]++;
		}
	}
	int l=0;
	for(int i=9;i>=0;i--){
		if(i!=0){
			while(mp[i]>0){
				cout<<i;
				mp[i]--;
				l=1;
			}
		}
		else if(l){
			while(mp[i]>0){
				cout<<i;
				mp[i]--;
			}
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
