#include <bits/stdc++.h>
using namespace std;
char s[9999];
int q[99999],w[99999];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=9999;i++){
		if(s[i]>='0' and s[i]<='9'){
			q[i]=int(s[i])-48;
		}

	}
	int num=0;
	for(int i=0;i<=99999;i++){
		if(q[i]!=0){
			w[num]=q[i];
			num++;
		}
	}
	sort(w,w+num+1);
	for(int i=num;i>=1;i--){
		cout<<w[i];
	}
}
