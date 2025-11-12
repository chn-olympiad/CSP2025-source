#include<bits/stdc++.h>
using namespace std;
char a[202020];
char b[3030303];
int vis[2020202];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l=0;
	int j =1;
	
	cin >>a;
	for(int i=1;i<=100001;i++){
		vis[i] = 1;
	}
	for(int i = 0;i<=100001;i++){
		if(a[i] == '1')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '2')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '3')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '4')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '5')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '6')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '7')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '8')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '9')	{
			l++;
			b[j] = a[i];
			j++;
		}
		if(a[i] == '0')	{
			l++;
			b[j] = a[i];
			j++;
		}
	}
	sort(b+1,b+l+1);
	for(int i = l;i>=1;i--){
		cout <<b[i];
	}
	
	
	return 0;
}
