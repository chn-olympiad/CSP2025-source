//SN-J00269
//安奭颉
//西安高新一中沣东中学初中校区 
#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string b;
	cin>>b;
	int a_len=b.length();
	for(int i=0;i<=a_len;i++){
		if(b[i]<='9'&&b[i]>='0'){
			a[b[i]-'0']++;
		}
	}
	for(int n=9;n>=0;n--){
		for(int j=1;j<=a[n];j++){
			cout<<n;
		}
	}
	return 0;
}

