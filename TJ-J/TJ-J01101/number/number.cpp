#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=1;
	string n;	
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' and n[i]<='9'){
			a[cnt]=n[i];
			cnt++;
		}
	}	
	sort(a,a+cnt);
	for(int i=cnt-1;i>=1;i--){
		cout<<a[i]-48;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
