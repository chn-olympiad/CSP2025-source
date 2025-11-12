#include<bits/stdc++.h>
using namespace std;
char a;
int b[100005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){		
		if(a>='0'&&a<='9'){
			cnt++;
			b[cnt]=a-48;
		}
	}
	sort(b+1,b+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}
	return 0;
}





