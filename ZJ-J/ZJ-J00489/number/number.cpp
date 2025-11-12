#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int b[1000001],maxx=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-'0';
			maxx++;
		}
	}
	sort(b,b+strlen(a),cmp);
	for(int i=0;i<maxx;i++){
		cout<<b[i];
	}
	
	return 0;
}