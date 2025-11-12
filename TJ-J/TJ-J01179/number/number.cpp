#include<bits/stdc++.h>
using namespace std;
string s1,ans,tmp1;
int a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]<='9'&&s1[i]>='0'){
			tmp1+=s1[i];
		}
	}
	for(int i=0;i<tmp1.size();i++){
		b=i;
		while(tmp1[b]>tmp1[b-1]&&b!=0){
			swap(tmp1[b],tmp1[b-1]);
			b--;
		}
	}
	cout<<tmp1;
	return 0;
}
