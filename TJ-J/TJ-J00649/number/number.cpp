#include<bits/stdc++.h>
using namespace std;
int l,a[1000006],b;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9'){
			b++;
			a[b]=s[i]-'0'+1;	
		}
	}
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--){
		cout<<a[i]-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
