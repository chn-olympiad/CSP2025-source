#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10005],id=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[id]=(int)s[i]-48;
			id++;
		}
	}
	sort(a,a+id);
	long long n=0,x=1;
	for(int i=1;i<id;i++){
		x=x*10;
	}
	while(id>0){
		n+=a[id-1]*x;
		x/=10;
		id--;
	}
	cout<<n;
	return 0;
} 
