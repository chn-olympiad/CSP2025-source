#include<bits/stdc++.h>
using namespace std;
int ans[1000001];
bool cmp(int x,int y){
	return x>y?1:0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char x;
	int k=0;
	while(x!='\n'){
		x=getchar();
		if(x>='0'&&x<='9'){
			ans[k]=x-'0';
			k++;
		}
	}
	sort(ans,ans+k,cmp);
	for(int i=0;i<k;i++){
		cout<<ans[i];
	}
	return 0;
}
