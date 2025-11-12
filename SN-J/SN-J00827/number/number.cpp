#include<bits/stdc++.h> 
using namespace std;
int main(){freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int cnt0=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0,cnt9=0;//记各个数字出现的次数的计数器 
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='0')++cnt0;
if(a[i]=='1')++cnt1;	
	if(a[i]=='2')++cnt2;
		if(a[i]=='3')++cnt3;
			if(a[i]=='4')++cnt4;
				if(a[i]=='5')++cnt5;
					if(a[i]=='6')++cnt6;
						if(a[i]=='7')++cnt7;
							if(a[i]=='8')++cnt8;
								if(a[i]=='9')++cnt9;
	}//统计各数字出现的次数 
	for(int i=0;i<cnt9;i++)cout<<"9";
	for(int i=0;i<cnt8;i++)cout<<"8";
    for(int i=0;i<cnt7;i++)cout<<"7";
	for(int i=0;i<cnt6;i++)cout<<"6";
	for(int i=0;i<cnt5;i++)cout<<"5";
	for(int i=0;i<cnt4;i++)cout<<"4";
	for(int i=0;i<cnt3;i++)cout<<"3";
	for(int i=0;i<cnt2;i++)cout<<"2";
	for(int i=0;i<cnt1;i++)cout<<"1";
	for(int i=0;i<cnt0;i++)cout<<"0";//降序输出数字 
return 0;
}
