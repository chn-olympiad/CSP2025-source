#include <bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string s1,s2;
}a[1000005];
string s_1,s_2;
int cnt;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i].s1>>a[i].s2;
	} 
	while(q--){
		cnt=0;
		cin>>s_1>>s_2;
		for(int i=0;i<n;i++){
			if(s_1==a[i].s1&&s_2==a[i].s2){
				cnt++;
			}
		}
		int len=s_1.size();
		int lft=0,rgh=0;
		for(int i=0;i<len;i++){
			if(s_1[i]!=s_2[i]){
				lft=i;
				break;
			}
		}
		for(int i=len-1;i>=0;i--){
			if(s_1[i]!=s_2[i]){
				rgh=i;
				break;
			}
		}
		string e,h;
		for(int i=lft;i<=rgh;i++){
			e+=s_1[i];
			h+=s_2[i];
		}
		for(int i=0;i<n;i++){
			if(e==a[i].s1&&h==a[i].s2){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
