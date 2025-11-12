#include<bits/stdc++.h>
using namespace std;
string s1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char c;
    while(cin>>c){
    	if(isdigit(c)) s1+=c;
	}
	sort(s1.begin(),s1.end());
	reverse(s1.begin(),s1.end());
	cout<<s1;
    return 0;
}
