#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int a[n+1]={},ans=0;
	if(n==1){
		cout<<s[0];
		return 0; 
	}
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ans]=s[i]-'0';
			ans++;
		} 
	}
	for(int i=0;i<ans;i++){
		for(int j=i+1;j<ans;j++){
			if(a[i]<a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	} 
	for(int i=0;i<ans;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
