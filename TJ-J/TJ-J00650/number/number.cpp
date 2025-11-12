#include<bits/stdc++.h>;
using namespace std;
bool cmp(char c,char d){
	return c>d;
}
char a[10000000];
char b[10000000];
int s=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<sizeof(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[s]+=a[i];
			s++;
		}
	}
	sort(b,b+s+1,cmp);
	for(int i=0;i<=s;i++){
		cout<<b[i];
	}
	cout<<endl;
	return 0;
} 
