#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int t[a.size()]={0};
	int y=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[i]=(int)a[i]-'0';
			y++;
	}
	}
	sort(t,t+a.size());
for(int i=a.size()-1;i>=0;i--){
	if(y>0)
	cout<<t[i];
	y--;
}
	
} 
