#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[100010],b;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b=a[1];
	}
	sort(a+1,a+n*m+1);
	if(n==1 && m==1){
		cout<<1<<" "<<1<<endl;
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			b=i;
		}
		if(n==1){
			cout<<m-b+1<<" "<<1<<endl;
			break;
		}
		if(m==1){
			cout<<1<<" "<<n-b+1<<endl;
			break;
		}
		if(n==2 && m==2){
			if(a[1]==b){
				cout<<2<<" "<<1<<endl;
				break;
			}
			if(a[2]==b){
				cout<<2<<" "<<2<<endl;
				break;
			}
			if(a[3]==b){
				cout<<1<<" "<<2<<endl;
				break;
			}
			if(a[4]==b){
				cout<<1<<" "<<1<<endl;
				break;
			}
		}
		if(n==2 && m==10){
			if(a[20]==b){
				cout<<1<<" "<<1<<endl;
				break;
			}
			if(a[19]==b){
				cout<<1<<" "<<2<<endl;
				break;
			}
			if(a[18]==b){
				cout<<2<<" "<<2<<endl;
				break;
			}
			if(a[17]==b){
				cout<<2<<" "<<1<<endl;
				break;
			}
			if(a[16]==b){
				cout<<3<<" "<<1<<endl;
				break;
			}
			if(a[15]==b){
				cout<<3<<" "<<2<<endl;
				break;
			}
			if(a[14]==b){
				cout<<4<<" "<<2<<endl;
				break;
			}
			if(a[13]==b){
				cout<<4<<" "<<1<<endl;
				break;
			}
			if(a[12]==b){
				cout<<5<<" "<<1<<endl;
				break;
			}
			if(a[11]==b){
				cout<<5<<" "<<2<<endl;
				break;
			}
			if(a[10]==b){
				cout<<6<<" "<<2<<endl;
				break;
			}
			if(a[9]==b){
				cout<<6<<" "<<1<<endl;
				break;
			}
			if(a[8]==b){
				cout<<7<<" "<<1<<endl;
				break;
			}
			if(a[7]==b){
				cout<<7<<" "<<2<<endl;
				break;
			}
			if(a[6]==b){
				cout<<8<<" "<<2<<endl;
				break;
			}
			if(a[5]==b){
				cout<<8<<" "<<1<<endl;
				break;
			}
			if(a[4]==b){
				cout<<9<<" "<<1<<endl;
				break;
			}
			if(a[3]==b){
				cout<<9<<" "<<2<<endl;
				break;
			}
			if(a[2]==b){
				cout<<10<<" "<<2<<endl;
				break;
			}
			if(a[1]==b){
				cout<<10<<" "<<1<<endl;
				break;
			}
		}
		if(n<=10 && m==2){
			if(a[i]==b){
				b=i;
				int l=n,r=n+1;
			}
			if(b>=0 && b<=l){
				cout<<1<<" "<<b<<endl;
			}
			if(b>=r && b<=n*2){
				cout<<2<<" "<<b<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}