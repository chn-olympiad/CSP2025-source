#include<bits/stdc++.h>

using namespace std;

int a[200009]={0};
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int q=-1;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			q++;
			a[q]=s[i]-'0';
		}
	}
	sort(a,a+q+1,cmp);
	for(int i=0;i<=q;i++){
		cout<<a[i];
	}
	return 0;
} 
