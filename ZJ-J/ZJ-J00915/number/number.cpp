#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long ans=0;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			ans++;
			num[ans]=a[i]-'0';
		}
	}
	sort(num+1,num+ans+1,greater<int>());
	long long cnt=0;
	for(int i=1;i<=ans;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
