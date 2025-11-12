#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,l[5005],s=0,c=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>l[i];
	}
	for (int i=n;i>=0;i--){
		s=l[i];
		for(int j=i-1;j>=0;j--){
			s += l[j];
			if(s>l[i]*2) {
				c++;
			}
		}
	}
	cout<<c;
	return 0;
}
