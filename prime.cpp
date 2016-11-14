#include<iostream>
#define ull unsigned long long
#include<vector>
#define pb push_back
#include<cmath>
#include<algorithm>
#define vit vector<ull>::iterator
using namespace std;
//vector for storing primes
vector<ull> p(1,2);//2- first prime

//generate primes till n
void genn(ull n){
	for(ull i=p.back()+1;i<=n;i++){
		bool f=1;
		for(vit it=p.begin();(*it)<=sqrt(i) && it!=p.end();it++)
			if(i%(*it)==0){
				f=0;break;
			}
		if(f) p.pb(i);
	}
}
//generate primes till vector size becomes n
void gens(ull n){
	for(ull i=p.back()+1;p.size()<=n;i++){
		bool f=1;
		for(vit it=p.begin();(*it)<=sqrt(i) && it!=p.end();it++)
			if(i%(*it)==0){
				f=0;break;
			}
		if(f) p.pb(i);
	}
}
//display vector(option not displayed on console), enter 99 
void dispv(){
	cout<<"Vector of Primes:"<<endl;
	for(vit it=p.begin();it!=p.end();it++)
		cout<<(*it)<<" ";
}
//display primes till n
void dispn(ull n){
	if(n>p.back()) genn(n);
	cout<<"Primes till "<<n<<":"<<endl;
	for(vit it=p.begin();it!=p.end() && (*it)<=n;it++)
		cout<<(*it)<<" ";
}
//display primes between m and n
void dispmn(ull m,ull n){
	if(n>p.back()) genn(n);
	cout<<"Primes between "<<m<<" and "<<n<<":"<<endl;
	for(vit it=p.begin();it!=p.end() && (*it)<=n;it++)
		if((*it)>=m) cout<<(*it)<<" ";
}
//count primes till n
void countn(ull n){
	if(n>p.back()) genn(n);
	ull c=0;
	for(vit it=p.begin();it!=p.end() && (*it)<=n;it++)
		c++;
	cout<<"Number of Primes till "<<n<<": "<<c;
}
//count primes between m and n
void countmn(ull m,ull n){
	if(n>p.back()) genn(n);
	ull c=0;
	for(vit it=p.begin();it!=p.end() && (*it)<=n;it++)
		if((*it)>=m) c++;
	cout<<"Number of Primes between "<<m<<" and "<<n<<": "<<c;
}
//display nth prime
void dispnth(ull n){
	if(n>p.size()) gens(n);
	cout<<n<<"th Prime: "<<p[n-1];
}
//check whether n is prime
void chk(ull n){
	if(n>p.back()) genn(n);
	if(find(p.begin(),p.end(),n)!=p.end())
		cout<<n<<" is Prime";
	else cout<<n<<" is NOT Prime";
}
int main(void){
	genn(100);//generate primes till 100 initially
	//dispv();cout<<endl; enter 99 to display
	cout<<"***Prime Calculator***"<<endl<<"This is simple program for generating and checking primes."<<endl<<"Author- Sagar Pathare"<<endl<<"sspathare97@gmail.com"<<endl<<endl;
	int c;int n;int m;
	do{
		cout<<"1. Check whether N is prime\n2. Display primes till N\n3. Count primes till N\n4. Display Nth prime\n";
		cout<<"5. Display primes between M and N (both inclusive)\n6. Count primes between M and N (both inclusive)\n0. Exit\nEnter your choice: ";
		cin>>c;
		if(c==5 || c==6){
			cout<<"Enter M: ";cin>>m;
		}
		if(1<=c && c<=6){
			cout<<"Enter N: ";cin>>n;
		}
		cout<<endl;
		switch(c){
			case 0:break;
			case 1:chk(n);break;
			case 2:dispn(n);break;
			case 3:countn(n);break;
			case 4:dispnth(n);break;
			case 5:dispmn(m,n);break;
			case 6:countmn(m,n);break;
			case 99:dispv();break;//not displayed in options
			default:cout<<"Invalid choice! Try again\n";
		}
		cout<<endl<<endl;
	}while(c);
	return 0;
}
