#include<bits/stdc++.h>
using namespace std;
string a;
int an[10000005];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	int o=1;
	for(int i=0;i<n;i++){
		if (a[i]-'0'<=9 && a[i]-'0'>=0){
			an[o]=a[i]-'0';
			o++;
		}
	}
	sort(an+1,an+o+1);
	for (int i=o;i>1;i--){
		cout<<an[i];
	}
	
	return 0;
} 
