#include<bits/stdc++.h>
using namespace std;
string s;
char q[100005];
int ans;
int main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	cin>>s;
	s+='Q';
	for(int i=0,j=0;s[i]!='Q';i++){
		if(s[i]>='0'&&s[i]<='9'){
			q[j]+=s[i];
			j++;
		}
	}
	
	for(int i=0;q[i]!='\0';i++){
		ans++;
	}
	for(int i=0;i<ans;i++){
		for(int j=0;j<=ans;j++){
			if(q[j]<q[j-1]){
				swap(q[j],q[j-1]);
			}
		}
	}
	for(int i=ans;i>=1;i--){
		cout<<q[i];
	}
	return 0;
}
