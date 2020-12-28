#include <iostream>
#include <vector>
using namespace std;

/*
struct Node {
	Node* next;
	int data;
	Node() {
		next = NULL;
		data = 0;
	}
};

struct List {
	Node* head;
	List() {
		head = NULL;
	}
};

void addNode(List* list, int n) { // ������ ��忡 �� ��� �߰��ϴ� ���
	Node* new_node = new Node();
	new_node->data = n;
	if (list->head == NULL)
		list->head = new_node;
	else {
		Node* temp = list->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

int removeNode(List* list) { // ����� ���� ���(target) ����� ���
	Node* temp = list->head->next;
	int value = temp->data;

	list->head->next = list->head->next->next;

	delete temp;

	return value;
}

int main() {
	List myList;
	vector<int> result;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) 
		addNode(&myList, i);
	
	// ������ ���� ù��° ��� �ձ�
	Node* temp = myList.head;
	while (temp->next != NULL)
		temp= temp->next;
	temp->next = myList.head;

	// ���� �����ϱ�
	while (result.size() != N) {
		if (K == 1) { // K�� 1�� ��
			Node* tmp_node = myList.head;
			result.push_back(tmp_node->data);
			myList.head = myList.head->next;
			delete tmp_node;
		}
		else { // K�� 1�� �ƴ� ��
			for (int j = 1; j < K - 1; j++)
				myList.head = myList.head->next;
			result.push_back(removeNode(&myList));
			myList.head = myList.head->next;
		}
	}

	// ���
	cout << "<";
	for (int m = 0; m < N; m++) {
		if (m == N - 1)
			cout << result[m] << ">";
		else cout << result[m] << ", ";
	}
	return 0;
}
*/

/*
struct Node {
	int elem;
	Node* next;
	Node() {
		elem = 0;
		next = NULL;
	}
};

struct List {
	Node* head;
	List() {
		head = NULL;
	}
};

void addNode(List* list, int n) {
	Node* node = new Node();
	node->elem = n;
	if (list->head == NULL) {
		list->head = node;
	}
	else {
		Node* temp = list->head;
		while (temp->next != NULL) 
			temp = temp->next;
		temp->next = node;
	}
}

int removeNode(List* list) { // ����� ���� ��带 ����
	if (list->head == NULL) return -1;
	else {
		Node* temp = list->head->next;
		int ret = list->head->next->elem; // ��ȯ�� elem ��
		list->head->next = list->head->next->next;
		delete temp;
		return ret;
	}
}

int main() {
	int N, K;
	List myList;
	vector<int> vec;

	cin >> N >> K;
	
	for (int i = 1; i <= N; i++)
		addNode(&myList, i);

	Node* temp = myList.head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = myList.head;

	if (N == 1) {
		cout << "<1>";
		return 0;
	}
	else {
		if (K == 1) {
			for (int j = 1; j <= N; j++)
				vec.push_back(j);
		}
		else {
			while (vec.size() < N) {
				if (vec.size() == 0) {
					for (int j = 0; j < K - 2; j++)
						myList.head = myList.head->next;
				}
				else {
					for (int j = 0; j < K - 1; j++)
						myList.head = myList.head->next;
				}
				vec.push_back(removeNode(&myList));
			}
		}

		// ���
		cout << '<';
		for (int k = 0; k < N; k++) {
			if (k != N - 1) cout << vec[k] << ", ";
			else cout << vec[k] << '>';
		}
		return 0;
	}
}
*/

class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int a) {
		data = a;
		next = NULL;
	}
};

class List {
public:
	Node* head;
	Node* tail;
	List() {
		head = NULL;
		tail = NULL;
	}

	void addNode(int a) {
		Node* node = new Node(a);
		if (head == NULL) 
			head = node;		
		else 
			tail->next = node;
		tail = node;
	}
};

List myList;
vector<int> vec;

int main() {
	int N, K;
	cin >> N >> K;

	if (K != 1) {
	for (int i = 1; i <= N; i++) 
		myList.addNode(i);
	
	myList.tail->next = myList.head;

	
		Node* cur = myList.head;
		for (int j = 0; j < K - 2; j++)
			cur = cur->next;
		vec.push_back(cur->next->data);
		cur->next = cur->next->next;

		while (vec.size() < N) {
			for (int m = 0; m < K - 1; m++)
				cur = cur->next;
			vec.push_back(cur->next->data);
			cur->next = cur->next->next;
		}
	}
	else {
		for (int i = 1; i <= N; i++)
			vec.push_back(i);
	}

	cout << '<';
	for (auto n : vec) {
		if(n!=vec[vec.size()-1])
			cout << n << ", ";
		else cout << n << '>';
	}
	
	return 0;
}