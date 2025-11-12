#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],b[N],cnt,mid;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	int j=cnt-1;
	for(int i=0;i<cnt/2;i++){
		mid=a[i];
		a[i]=a[j];
		a[j]=mid;
		j--;
	}
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
