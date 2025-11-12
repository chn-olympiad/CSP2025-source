#include<bits/stdc++.h>
using namespace std;
int n,c;
string str;
int arr[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>c;
	cin>>str;
	for(int i=1;i<=n;i++)cin>>arr[i];
	int i=0;
	int ans=0;
	while(str[i]=='1'&&i<=str.length())ans++,i++;
	cout<<ans;
	return 0;
}
