/*龚逸宸 SN-J01221 西安市曲江第一学校 */
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char a='9';
	for(int i=9;i>=0;i--){
		for(int j=0;j<s.size();j++){
			if(s[j]==a){
				cout<<i;
			}
		}
		a-=1;
	}
	return 0 ;
}
