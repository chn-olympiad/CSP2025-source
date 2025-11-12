#include<bits/stdc++.h>
using namespace std;
string s;
int tot=0,arr[1919810];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			arr[tot]=s[i]-'0';
			tot++;
		}
	}
	sort(arr,arr+tot,cmp);
	if(arr[0]==0){
		cout<<0;
		return 0;
	}else for(int i=0;i<tot;i++)cout<<arr[i];
}