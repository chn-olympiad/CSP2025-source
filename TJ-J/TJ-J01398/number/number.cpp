#include<bits/stdc++.h>
using namespace std;
int num[1000099],tail=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.length();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			num[tail]=a[i]-'0';
			tail++;
		}
	}
	sort(num,num+tail);
	for(int i=tail-1;i>=0;i--){
		cout<<num[i]; 
	} 
	return 0;
}

