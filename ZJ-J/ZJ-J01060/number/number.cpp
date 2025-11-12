#include<bits/stdc++.h>
using namespace std;
string n;
string sum;
int x;
int f[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int len=n.size();
	for(int i=0;i<len;i++){
		if('0'<=n[i]&&n[i]<='9'){
			f[x]=int(n[i])-48;
			x=x+1;
		}
	}
	sort(f,f+x);
	for(int i=x-1;i>=0;i--){
		char a=char(f[i]+48);
		sum+=a;
	}
	cout<<sum;
	return 0;
}
