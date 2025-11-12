#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=0;
	cin>>n;
	int stk[5050];
	int flag=0,fans=0;
	for(int i=1;i<=n;i++){
		cin>>stk[i];
		if(stk[i]!=stk[1]) flag++;
	}
	sort(stk+1,stk+n+1);
	if(n==3){
		if(stk[1]+stk[2]>stk[3]) cout<<1;
		else cout<<0;
	}else if(!flag){
		for(int i=1;i<=n-2;i++){
			fans+=(i*(i+1))/2;
		}
		cout<<fans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
