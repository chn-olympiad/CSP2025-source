#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	char c;
	int a[100005];
	int l=s.length(),k=1;
	for(int i=0;i<l;i++){
		c=s[i];
		if(c>='0'&&c<='9'){
			a[k]=c-'1'+1;
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>0;i--){
		cout<<a[i];
	}
	return 0;
}

