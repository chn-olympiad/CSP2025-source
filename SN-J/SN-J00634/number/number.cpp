#include<bits/stdc++.h>
using namespace std;
long long b[1000005],f=1;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='a' && a[i]<='z'){
		}else{
			b[f]=a[i]-'0';
			f++;
		}
	}
	sort(b+1,b+1+f);
	for(int i=f;i>=1;i--){
		if(i==1){
			b[i]/10;
		}else{
			cout<<b[i];
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
