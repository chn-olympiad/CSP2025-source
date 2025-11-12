#include<bits/stdc++.h>
using namespace std;
int s[1000005],q=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			q++;
			s[q]=a[i]-'0';
		}
	}
	sort(s+1,s+q+1);
	for(int i=q;i>=1;i--) cout<<s[i];
	return 0;
}