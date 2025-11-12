#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
string s;
int cnt,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	t=s.size();
	int a[t];
	for(int i=0;i<t;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=int(s[i]);
			cnt++;
		}	
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<char(a[i]); 
	} 
	return 0;
}
