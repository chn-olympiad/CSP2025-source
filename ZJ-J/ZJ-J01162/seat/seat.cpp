
int main(){
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		
	}
	int s=0;
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0]){
			s++;
		}
		
	}
	cout<<s/n<<" ";
	if(s/n%2==0){
		cout<<n-s%n+1;
		
	}else{
		cout<<s%n+1;
	}
	return 0;
}


