#include<bits/stdc++.h>
using namespace std;
string a;
long long b[10001],c=0;
long long q=0;
bool cmp(long long q,long long w)
{
	if(q>w);
	return q>w;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++)
	{
		if(int(a[i])>=48 and int(a[i])<=57)
		{
			b[c]=a[i]-48;
			c++;
		}
	}
	
	sort(b,b+c,cmp);
	if(c<=10){
	for(int i=0;i<c;i++){
		q=b[i]+10*q;
	}
	cout<<q;
}
else{
	for(int i=0;i<c;i++){
		cout<<b[i];
}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
