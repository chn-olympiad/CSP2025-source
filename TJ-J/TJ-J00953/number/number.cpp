#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10000086];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int m=0;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=(s[i]-'0');
			m++;
		}
	} 
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++)cout<<a[i];
	return 0;
}




















//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			if(a[i]>a[j])swap(a[i],a[j]);
//		}
//	}
