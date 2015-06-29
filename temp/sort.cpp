#include<iostream>
using namespace std;
#define N 10
class Allsort{
	virtual void  sort(int *a,int size) =0;
	friend class Mysort;
};

void headadjust(int *a,int element,int size){
	int lchild=2*element;
	int rchild=2*element+1;
	int max=element;
	if(element<=size/2){
		if(a[lchild-1]>a[max-1] && lchild <=size){
			max=lchild;
		}
		if(a[rchild-1]>a[max-1] && rchild <= size){
			max=rchild;
		}
		if(max!=element){
			swap(a[element-1],a[max-1]);
			headadjust(a,max,size);
		}
	}
}
void bighead(int *a,int size){
	for(int i=size/2;i>=1;i--){
		headadjust(a,i,size);
	}
}

void headsort(int *a,int size){
	bighead(a,size);
	for(int i=size;i>=1;i--){
		swap(a[0],a[i-1]);
		headadjust(a,1,i-1);
	}
}

class Headsort:public Allsort{
	public:
		void sort(int *a,int n){
			headsort(a,n);
			cout<<"this is head sort"<<endl;
		}
};


void qsort(int *a,int low,int high){
	if(low>=high) return;
	int first=low;
	int last=high;
	int key=a[first];
	while(first<last){
		while(a[last]>key && last>first ){
			--last;
		}
		a[first]=a[last];
		while(a[first]<=key && first<last){
			++first;
		}
		a[last]=a[first];
	}
	a[first]=key;
	qsort(a,low,first-1);
	qsort(a,first+1,high);	
}

class Qsort:public Allsort{
	public:
		void sort(int *a,int size){
			qsort(a,0,size);
			cout<<"this is quick sort"<<endl;
		}
};



class Selectsort:public Allsort{
	public:
		void sort(int *a,int n){
			int tmp;
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(a[i]>a[j]){
						tmp=a[i];
						a[i]=a[j];
						a[j]=tmp;
					}
				}
			}
			cout<<"this is select sort "<<endl;
		}

};

class Bubblesort:public Allsort{
	public:
		void sort(int *a,int n){
			int i, j, temp;
			for (j = 0; j < n - 1; j++)
				for (i = 0; i < n - 1 - j; i++)
				{
					if(a[i] > a[i + 1])
					{
						temp = a[i];
						a[i] = a[i + 1];
						a[i + 1] = temp;
					}
				} 
			cout<<"this is bubble sort"<<endl;
		}
};

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

int main(){
	Mysort b;
	b.setnum();
	b.setsort(new Bubblesort());
	b.perform();
	b.display();
	b.setsort(new Qsort());
	b.perform();
	b.display();
	b.setsort(new Selectsort());
	b.perform();
	b.display();
	b.setsort(new Headsort());
	b.perform();
	b.display();
	return 0;
}





