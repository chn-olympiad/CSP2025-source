#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin >> n;
	int m[1010]={};
	int f=0,f1=0;
	for(int i=0;i<=n.size()-1;i++){
		if(n[i]>='0'&&n[i]<='9'){
			f=i;
			f1++;
			m[i]=n[i]-'0';
		}
	}
	sort(m,m+f+1,greater<int>());
	for(int i=0;i<=f1-1;i++){
		cout << m[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
