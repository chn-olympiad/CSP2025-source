#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,n;
	int f,ans=0;
	cin>>s;
	for(int i =0;i<s.length();i++){
		if (s[i] >= 'a' && s[i] <= 'Z'){
			
		}
		else{
			n[i]=s[i];
			ans++;
		}
	}
	for(int i = 0;i<ans;i++)
	{
		if(n[i] <n[i+1]){
			swap(n[i],n[i+1]);
		}
	}
	for(int i = 0;i<ans;i++){
		if(n[i]<n[i+1]){
			swap(n[i],n[i+1]);
		}
	}
	for(int i = 0;i<ans;i++){
		cout<<n[i];
	}
	return 0;
}
