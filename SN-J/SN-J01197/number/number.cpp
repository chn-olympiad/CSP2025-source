//SN-J01197  魏赫含  西安高新一中沣东中学初中校区 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
string s;
int a[N],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;	
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
