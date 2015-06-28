#include<iostream>
using namespace std;
#define N 10
class Allsort{
	virtual void  sort(int *a,int size) =0;
	friend class Mysort;
};



/*class Headsort:public Allsort{
  public:
  void sort(int *a,int n){`
  return;
  }

  };
 */

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
			cout<<"quick"<<endl;
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
			cout<<"this is bubble"<<endl;
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

	return 0;
}





