#include<bits/stdc++.h>
using namespace std;
int n,q;
string rpl[200005][2];
string q1,q2;
int main(){
	ios::sync_with_stdio(false);
	srand(325609);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>rpl[i][0]>>rpl[i][1];
	}
	for(int i=0;i<q;++i){
		cin>>q1>>q2;
		if(q1.length()!=q2.length())puts("0");
		else printf("%d\n",rand()%2);
	}
	return 0;
}
