#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	string s;
	for(int i=1;i<=87;i+=2){
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
				if(int(a[i])>int(a[i-1])){
					s+=a[i];
					s+=a[i-1];
					}
				else{
					s+=a[i-1];
				}
			}
		}
	cout<<s;
	return 0;
}
