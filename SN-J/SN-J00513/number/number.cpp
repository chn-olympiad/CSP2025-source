#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string n;
int m[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int ind=0;
	for(int i=0;i<n.length();i++){
		if('0'<=n[i]&&n[i]<='9'){
			m[ind]=int(n[i]-'0');
			ind++;
		}
	}
	sort(m,m+ind+1,cmp);
	for(int i=0;i<ind;i++){
		cout<<m[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
