#include <bits/stdc++.h>
using namespace std;
string sc;
char ch[1001];
int sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sc;
	for(int i=0;i<sc.size();i++){
		if(sc[i]>='0'&&sc[i]<='9'){
			ch[sum]=sc[i];
			sum++;
		}
	}
	sort(ch,ch+sum+1,greater<char>());
	for(int i=0;i<=sum;i++){
		cout<<ch[i];
	}
	return 0;
}
