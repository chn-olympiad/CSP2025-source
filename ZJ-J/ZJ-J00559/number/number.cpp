#include<bits/stdc++.h>
using namespace std;
int y[1000010];
bool abc(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string x;
	cin>>x;
	int s=x.size();
	int i=0;
	for(int c=0;c<s;c++){
		if(x[c]>='0'&&x[c]<='9'){
			y[i++]=x[c]-'0';
		}
	}
	sort(y,y+i,abc);
	if(y[0]==0){
		cout<<"0";
	}
	else{
		for(int c=0;c<i;c++){
			cout<<y[c];
		}
	}
	return 0;
}