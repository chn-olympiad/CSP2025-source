#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100]={0},i=0,l=0;

	while(s[i]) {
		a[l]=s[i]-48;
		if(a[l]<10){
			cout<<a[l]<<" ";
			l++;
		}
		
		i++;
	} 
	sort(a,a+l+1);
	for(i=l;i>0;i--){
		cout<<a[i];
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
