#include<string>
#include<queue>
using namespace std;
struct NodeType { 
	string name;
	int at;
	int pt;
	NodeType *next;
}; 
struct OutputQueue {
	string namea;
	string nameb;
	OutputQueue *n;
};
class CashierClass {
public:
	CashierClass();
	~CashierClass();
	int processTime();
	void inc_timer();
	int get_timer();
	void resetTimer();
	void inc_counter();
	int get_counter();
	bool IsEmpty();
	bool IsFull();
	void print(ofstream  &fout);
	NodeType * First();
	NodeType * Last();
	bool Add(NodeType *t);
	bool Remove(NodeType *t);
	bool Addfinal(NodeType *freshNode, NodeType *t);
	void printFinal(ofstream &fout);
private:
	NodeType * front1;
	NodeType *rear;
	OutputQueue *f;
	OutputQueue *r;
	int timer, counter;
};