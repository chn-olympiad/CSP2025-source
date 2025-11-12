//何乐怡 SN-J00035 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.size();i++)a[i]=-1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int n=s[i]-'0';
			a[i+1]=n;
		}
	}
	int ret=0;
	for(int i=1;i<=s.size();i++){
		if(a[i]==-1)ret++;
	}
	int chang=s.size();
	sort(a,chang+a+1);
	for(int i=s.size();i>=ret+1;i--){
		if(a[i]>-1)cout<<a[i];
	}
	return 0;
}
