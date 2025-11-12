#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	string s,a;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0' and s[i]<='9'){
			a=a+s[i];
		}  
	}
	int l2=a.size();
	for(int i=0;i<l2;i++){
		for(int j=0;j<i;j++){
			if(a[j]<=a[i]){
				swap(a[i],a[j]);	
			}
			
		}
	}
	cout<<a;
	return 0;
}
