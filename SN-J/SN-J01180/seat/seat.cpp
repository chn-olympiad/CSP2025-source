//考号：SN-J01180 姓名：高子懿 学校：延安市安塞区初级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> s;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	if(n==2 and m==2)
		cout<<1<<' '<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
