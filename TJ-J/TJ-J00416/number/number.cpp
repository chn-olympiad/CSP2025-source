#include  <bits/stdc++.h>
using namespace std;

bool cnp(int x,int y){
	return x>y;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0,sl=s.size();
	int a[sl+5]={};
	for(int i=0;i<=sl-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=int(s[i]-'0');
			cnt++;
		}
	} 
	sort (a,a+sl,cnp);
	long long sum=0;
	for(int i=0;i<=cnt-1;i++) {
		sum=sum*10;
		sum+=a[i];
	}
	cout<<sum;
	
	
	
	
	return 0;
}
