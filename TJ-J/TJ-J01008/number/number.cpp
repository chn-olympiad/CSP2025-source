#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("numsber.out","w",stdout); 
	string s;
	cin >> s;
	int n[s.size()+111]={0}, f=0;
	for (int i=0;i<s.size();i++){
		if ('0'<=s[i] && s[i]<='9') {
			n[f]=(int)(s[i]) - 48;
			f++;
			
		}
	}
	sort(n,n+f,cmp);
	for (int i=0;i<f;i++){
		cout << n[i];
	}
	return 0;
} 
