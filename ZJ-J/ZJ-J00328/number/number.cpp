#include<bits/stdc++.h>
using namespace std;
string a;
int maxn;
int maxp;
string sum;
int s;
int m;
bool f[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	if(a.size()==1){
		cout<<a;
		return 0;	
	}
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]>='0'&&a[i]<='9') s++;
	}
	while(m!=s){
		for(int i=0;i<=a.size()-1;i++){
			if(f[i]==0&&a[i]>='0'&&a[i]<='9'){
				if((a[i]-'0')>=maxn){
					maxn=(a[i]-'0');
					maxp=i;
				}
			}
		}
		sum+=a[maxp];
		f[maxp]=1;
		maxn=0;
		maxp=0;
		m+=1;
	}
	cout<<sum;
	return 0;
} 

