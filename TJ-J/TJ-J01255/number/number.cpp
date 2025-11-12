#include<bits/stdc++.h>
using namespace std;
string b;
int x=0;
bool cmp(int a,int b){
	if(a<b) return a>b;
	else return a>b;
}
void func(string a){
	int len=a.size();
	for(int i=0;i<=len-1;i++){
		if(isdigit(a[i])){
			b[x]=int(a[i]);
			x++;
		}
	}
	int q[100005]={};
	for(int i=0;i<=x-1;i++){
		q[i]=b[i]-48;
	}
	sort(q,q+x,cmp);
	for(int i=0;i<=x-1;i++){
		cout<<q[i];
	}
}

int main(){     
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	func(s);
	
	return 0;
}
