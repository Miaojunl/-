#define N 10
class Mysort{
	private:
		int a[N];
		Allsort *s;
	public:
		void setnum();
		void display();
		void perform();
		void setsort(Allsort *t);
};
void Mysort::setnum(){
	for(int i=0;i<10;i++)
		cin>>a[i];
}
void Mysort::display(){
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void Mysort::perform(){
	s->sort(a,N);
}
void Mysort:: setsort(Allsort *t){
	s=t;
}


