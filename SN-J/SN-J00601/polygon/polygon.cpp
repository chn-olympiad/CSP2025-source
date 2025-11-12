#include<bits/stdc++.h>
#include<string>
using namespace std;
int s[5010],a,tot;
int main(){
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	cin>>a>>tot;
	for(int i=0;i<=a;i++){
		if(s[2*a]>s[a]||(a+3)/2*a){
			tot++;
		}
	}
	cout<<tot<<endl;
	return 0;
}
