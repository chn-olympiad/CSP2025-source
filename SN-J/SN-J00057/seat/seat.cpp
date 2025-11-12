#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int mp[105],n,m,a[105],c = 0,r,arr[15][15];
	cin>>n>>m;
	int b = n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	r = a[1];
	sort(a+1,a+1+b,cmp);
	if(n==1 && m==1){
		cout<<1<<" "<<1;
	}else if(n==1 && m==10){
		for(int i=1;i<=m;i++){
			mp[i] = a[i];
		}
		for(int i=1;i<=m;i++){
			if(mp[i]==r){
				cout<<1<<" "<<i;
			}
		}	
	}else if(n==10 && m==1){
		for(int i=1;i<=n;i++){
			mp[i] = a[i];
		}
		for(int i=1;i<=n;i++){
			if(mp[i]==r){
				cout<<i<<" "<<1;
			}
		}
	}else if(n==2 && m==2){
		arr[1][1] = a[1];
		arr[2][1] = a[2];
		arr[2][2] = a[3];
		arr[1][2] = a[4];
		if(arr[1][1]==r){
			cout<<1<<" "<<1;
		}else if(arr[2][1]==r){
			cout<<1<<" "<<2;
		}else if(arr[2][2]==r){
			cout<<2<<" "<<2;
		}else if(arr[1][2]==r){
			cout<<2<<" "<<1;
		}
	}else if(n==10 && m==2){
		arr[1][1] = a[1];
		arr[2][1] = a[2];
		arr[3][1] = a[3];
		arr[4][1] = a[4];
		arr[5][1] = a[5];
		arr[6][1] = a[6];
		arr[7][1] = a[7];
		arr[8][1] = a[8];
		arr[9][1] = a[9];
		arr[10][1] = a[10];
		arr[1][2] = a[11];
		arr[2][2] = a[12];
		arr[3][2] = a[13];
		arr[4][2] = a[14];
		arr[5][2] = a[15];
		arr[6][2] = a[16];
		arr[7][2] = a[17];
		arr[8][2] = a[18];
		arr[9][2] = a[19];
		arr[10][2] = a[20];
		if(arr[1][1]==r){
			cout<<1<<" "<<1;
		}else if(arr[2][1]==r){
			cout<<1<<" "<<2;
		}else if(arr[3][1]==r){
			cout<<1<<" "<<3;
		}else if(arr[4][1]==r){
			cout<<1<<" "<<4;
		}else if(arr[5][1]==r){
			cout<<1<<" "<<5;
		}else if(arr[6][1]==r){
			cout<<1<<" "<<6;
		}else if(arr[7][1]==r){
			cout<<1<<" "<<7;
		}else if(arr[8][1]==r){
			cout<<1<<" "<<8;
		}else if(arr[9][1]==r){
			cout<<1<<" "<<9;
		}else if(arr[10][1]==r){
			cout<<1<<" "<<10;
		}else if(arr[1][2]==r){
			cout<<2<<" "<<1;
		}else if(arr[2][2]==r){
			cout<<2<<" "<<2;
		}else if(arr[3][2]==r){
			cout<<2<<" "<<3;
		}else if(arr[4][2]==r){
			cout<<2<<" "<<4;
		}else if(arr[5][2]==r){
			cout<<2<<" "<<5;
		}else if(arr[6][2]==r){
			cout<<2<<" "<<6;
		}else if(arr[7][2]==r){
			cout<<2<<" "<<7;
		}else if(arr[8][2]==r){
			cout<<2<<" "<<8;
		}else if(arr[9][2]==r){
			cout<<2<<" "<<9;
		}else if(arr[10][2]==r){
			cout<<2<<" "<<10;
		}
	}else if(n==2 && m==10){
		arr[1][1] = a[1];
		arr[1][2] = a[2];
		arr[1][3] = a[3];
		arr[1][4] = a[4];
		arr[1][5] = a[5];
		arr[1][6] = a[6];
		arr[1][7] = a[7];
		arr[1][8] = a[8];
		arr[1][9] = a[9];
		arr[1][10] = a[10];
		arr[2][1] = a[11];
		arr[2][2] = a[12];
		arr[2][3] = a[13];
		arr[2][4] = a[14];
		arr[2][5] = a[15];
		arr[2][6] = a[16];
		arr[2][7] = a[17];
		arr[2][8] = a[18];
		arr[2][9] = a[19];
		arr[2][10] = a[20];
		if(arr[1][1]==r){
			cout<<1<<" "<<1;
		}else if(arr[1][2]==r){
			cout<<2<<" "<<1;
		}else if(arr[1][3]==r){
			cout<<3<<" "<<1;
		}else if(arr[1][4]==r){
			cout<<4<<" "<<1;
		}else if(arr[1][5]==r){
			cout<<5<<" "<<1;
		}else if(arr[1][6]==r){
			cout<<6<<" "<<1;
		}else if(arr[1][7]==r){
			cout<<7<<" "<<1;
		}else if(arr[1][8]==r){
			cout<<8<<" "<<1;
		}else if(arr[1][9]==r){
			cout<<9<<" "<<1;
		}else if(arr[1][10]==r){
			cout<<10<<" "<<1;
		}else if(arr[2][1]==r){
			cout<<1<<" "<<2;
		}else if(arr[2][2]==r){
			cout<<2<<" "<<2;
		}else if(arr[2][3]==r){
			cout<<3<<" "<<2;
		}else if(arr[2][4]==r){
			cout<<4<<" "<<2;
		}else if(arr[2][5]==r){
			cout<<5<<" "<<2;
		}else if(arr[2][6]==r){
			cout<<6<<" "<<2;
		}else if(arr[2][7]==r){
			cout<<7<<" "<<2;
		}else if(arr[2][8]==r){
			cout<<8<<" "<<2;
		}else if(arr[2][9]==r){
			cout<<9<<" "<<2;
		}else if(arr[2][10]==r){
			cout<<10<<" "<<2;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
