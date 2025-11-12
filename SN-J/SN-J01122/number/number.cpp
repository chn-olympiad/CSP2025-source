#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	cin>>s;
	for(int i=1;i<=s;i++){
		if(s[i]>"1"&&s[i]<=9){
			a[i]=s[i];
		}
		for(int i=2;i<=s;i++){
			a[i]-(a[i],a[i-1]);
		}
	}
	cout<<s;                                                                                                                                        
	return 0;
}
