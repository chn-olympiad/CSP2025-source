 #include<bits/stdc++.h>
 using namespace std;
 int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	long long  len,t=0;
	getline(cin,str);
	len=str.size();
	int a[len+1]={0};
	for(long long i=0;i<len;i++){
 		if (str[i]>='0'&&str[i]<='9'){
 			a[t]=str[i]-'0';
			t++;
		}
	}
	for(long long i=0;i<len-1;i++){
		for(long long j=i+1;j<len;j++){
			if (a[i]<a[j]){
				int  k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for(long long i=0;i<t;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
