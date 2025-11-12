#include<bits/stdc++.h>
using namespace std;
string a;
int ant,b[1000010];
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			ant++;
			b[ant]=a[i]-'0';
		}
	}
	sort(b+1,b+ant+1,c);
	for(int i=1;i<=ant;i++){
		cout<<b[i];
	}
	return 0;
}
