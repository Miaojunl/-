#include<iostream>
using namespace std;
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
