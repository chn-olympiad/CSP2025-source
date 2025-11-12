#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000005];
int k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>=49&&n[i]<58){
			a[k]=(n[i]-'0');
			k++;
		}
		else if(n[i]==48){
			a[k]=0;
			k++;
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>1;i--){
		cout<<a[i];
	}
	return 0;
} 
