#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000001]; 
long long cnt=0;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("number .in","r",stdin);
	freopen("number .out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			++cnt;
			b[cnt]=a[i]-'0';
		}
	}
	sort(b+1,b+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}
	return 0;
	}

