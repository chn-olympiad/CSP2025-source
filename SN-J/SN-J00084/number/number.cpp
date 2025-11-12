#include<bits/stdc++.h>
using namespace std;
string s,r;
const int N=1e6+5;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0' && s[i]<='9'){
			r+=s[i];
		}
	} 
	int lenr=r.size();
	cout<<lenr<<endl;
	for(int i=0;i<lenr;i++){
		a[i]=r[i];
		cout<<a[i]<<' ';
	}
	cout<<endl;
	sort(a,a+lenr+1,cmp);
	for(int i=0;i<lenr;i++){
		cout<<char(a[i]);
	}
	return 0;
}
