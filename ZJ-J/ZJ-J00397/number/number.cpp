#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[1000005];
int l,i,ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a+1;
	l=strlen(a+1);
	for(i=1;i<=l;i++){
		if(a[i]=='1')ans1++;
		else if(a[i]=='2')ans2++;
		else if(a[i]=='3')ans3++;
		else if(a[i]=='4')ans4++;
		else if(a[i]=='5')ans5++;
		else if(a[i]=='6')ans6++;
		else if(a[i]=='7')ans7++;
		else if(a[i]=='8')ans8++;
		else if(a[i]=='9')ans9++;
		else if(a[i]=='0')ans0++;
	}
	if(ans9!=0)
		for(i=1;i<=ans9;i++)cout<<"9";
	if(ans8!=0)
		for(i=1;i<=ans8;i++)cout<<"8";
	if(ans7!=0)
		for(i=1;i<=ans7;i++)cout<<"7";
	if(ans6!=0)
		for(i=1;i<=ans6;i++)cout<<"6";
	if(ans5!=0)
		for(i=1;i<=ans5;i++)cout<<"5";
	if(ans4!=0)
		for(i=1;i<=ans4;i++)cout<<"4";
	if(ans3!=0)
		for(i=1;i<=ans3;i++)cout<<"3";
	if(ans2!=0)
		for(i=1;i<=ans2;i++)cout<<"2";
	if(ans1!=0)
		for(i=1;i<=ans1;i++)cout<<"1";
	if(ans0!=0)
		for(i=1;i<=ans0;i++)cout<<"0";
}



/*
#Shang4Shan3Ruo6Shui4
*/
