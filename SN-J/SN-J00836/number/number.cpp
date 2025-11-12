#include<bits/stdc++.h>
using namespace std;
string s;
int arr[1000006],id;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			id++;
			arr[id]=s[i]-'0';
		}
	}
	sort(arr+1,arr+id+1);
	for(int i=id;i>=1;i--)cout<<arr[i];
	return 0;
}
