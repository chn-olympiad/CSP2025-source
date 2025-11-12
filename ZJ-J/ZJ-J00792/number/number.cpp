#include<bits/stdc++.h>
using namespace std;
string s;
int t[15];
bool flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0){
			if(flag==1){
				while(1){
					if(t[i]==0){
						break;
					}else{
						cout<<i;
						t[i]--;
					}
				}
			}else{
				continue;
			}
		}else{
			while(1){
				if(t[i]==0){
					break;
				}else{
					cout<<i;
					t[i]--;
					flag=1;
				}
			}
		}
		
	}
	return 0;
}

