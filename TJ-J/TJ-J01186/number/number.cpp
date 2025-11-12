#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b=0,c=0,maxn=0;
	string s;
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[b]=s[i];
			b++;
		}
	}
	for(int i=0;i<b;i++){
		for(int j=i;j<b;j++){
			if(a[i]<a[j]){
				maxn=max(maxn,a[j]);
					if(maxn==a[j]){
						c=a[i];
						a[i]=maxn;
						a[j]=c;
				}
			}
		}
		maxn=0,c=0;
	}
	for(int i=0;i<b;i++){
		cout<<char(a[i]);
	}
	return 0;
} 
