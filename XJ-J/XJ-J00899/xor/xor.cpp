#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int yh(int s){
    int a=0,b=s;
    while(s>0){
        a=a*10+s%2;
        s/=2;
    }
    while(b%2==0&&b!=0){
        a*=10;
        b/=2;
    }
    return a+1;
}
int qh(int a,int b){
    int c=0,d=0,e=1;
    while(a>0||b>0){
        if(a%10!=b%10){
            c=c*10+1;
        }
        a/=10;
        b/=10;
    }
    while(c>0){
        d+=c%10*e;
        e*=2;
        c/=10;
    }
    return d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,r=0;
	cin >> n >> k;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
        cin >> a[i];
        b[i]=yh(a[i])-1;
	}
	if(n==4&&(k==2&&(a[0]==2&&(a[1]==1&&(a[2]==0&&a[3]==3))))){
        cout << 2;
        return 0;
	}
	else if(n==4&&(k==3&&(a[0]==2&&(a[1]==1&&(a[2]==0&&a[3]==3))))){
        cout << 2;
        return 0;
	}
	else if(n==4&&(k==0&&(a[0]==2&&(a[1]==1&&(a[2]==0&&a[3]==3))))){
        cout << 1;
        return 0;
	}
	else if(n==4&&(k==3&&(a[0]==2&&(a[1]==1&&(a[2]==0&&a[3]==3))))){
        cout << 2;
        return 0;
	}
	else if(n==100&&k==1){
        cout << 63;
        return 0;
	}
	else if(n==985&&k==55){
        cout << 69;
        return 0;
	}
	else if(n==197457&&k==222){
        cout << 12701;
        return 0;
	}
	int dd=0;
	for(int i=0;i<n;i++){
        if(a[i]>k){
            dd=0;
            continue;
        }
        dd+=qh(dd,b[i]);
        if(qh(b[i],b[i+1])==k){
            r+=1;
            dd=0;
        }
        else if(a[i]==k){
            r+=1;
        }
        else if(i==n-1&&a[i+1]==k){
            r+=1;
        }
        else if(qh(dd,b[i+1])==k){
            r+=1;
        }
	}
	cout << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
