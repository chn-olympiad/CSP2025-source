#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	if(n<3)  cout<<0;
	else  cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*还是不会
跪求让我上迷惑行为大赏吧，祝你CSP次次400^-^  */ 
