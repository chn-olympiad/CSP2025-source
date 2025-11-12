#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt5=0,cnt6=0,cnt7=0,cnt8=0,cnt9=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			cnt++;
		}
		if(s[i]=='1'){
			cnt1++;
		}
		if(s[i]=='2'){
			cnt2++;
				}
		if(s[i]=='3'){
			cnt3++;
		}
		if(s[i]=='4'){
					cnt4++;
				}
				if(s[i]=='5'){
					cnt5++;
				}
				if(s[i]=='6'){
					cnt6++;
						}
				if(s[i]=='7'){
					cnt7++;
				}
			if(s[i]=='8'){
				cnt8++;
			}
			if(s[i]=='9'){
							cnt9++;
						}
	}
	if(cnt9!=0){
		for(int i=0;i<cnt9;i++){
			cout<<9;
		}
	}
	if(cnt8!=0){
			for(int i=0;i<cnt8;i++){
				cout<<8;
			}
		}
	if(cnt7!=0){
			for(int i=0;i<cnt7;i++){
				cout<<7;
			}
		}
		if(cnt6!=0){
				for(int i=0;i<cnt6;i++){
					cout<<6;
				}
			}
			if(cnt5!=0){
					for(int i=0;i<cnt5;i++){
						cout<<5;
					}
				}
				if(cnt4!=0){
						for(int i=0;i<cnt4;i++){
							cout<<4;
						}
					}
					if(cnt3!=0){
								for(int i=0;i<cnt3;i++){
									cout<<3;
								}
							}
							if(cnt2!=0){
									for(int i=0;i<cnt2;i++){
										cout<<2;
									}
								}
								if(cnt1!=0){
										for(int i=0;i<cnt1;i++){
											cout<<1;
										}
									}
									if(cnt!=0){
											for(int i=0;i<cnt;i++){
												cout<<0;
											}
										}
	return 0;
} 
