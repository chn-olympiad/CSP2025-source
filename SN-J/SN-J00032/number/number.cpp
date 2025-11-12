#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	int w=0,maxx[100005]={48,48,48};
	cin>>s;
	if(s.size()<=1&&(s[0]<='9'&&s[0]>='0')){
		cout<<s;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[w]=s[i];
			w++;
		}
	}
	for(int i=0;i<w;i++){
		if(a[i]>maxx[i]){
			maxx[i]=a[i];
		}
		maxx[i]-=48;
	}
	sort(maxx,maxx+1+w);
	for(int i=w;i>0;i--){
		cout<<maxx[i];
	};
	return 0;
} 
