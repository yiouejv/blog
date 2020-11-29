template <class T>
class ListNode {
public:
	T val;
	ListNode<T>* next;
	ListNode(const T &val);
	~ListNode();
};

template <class T>
ListNode<T>::ListNode(const T& val) {
	this->val = val;
	next = NULL;
}

template <class T>
ListNode<T>::~ListNode() {
	
}

template <class T>
class List {
public:
	List();
	~List();
	bool push_back(const T &val);
	bool push_front(const T &val);
	T pop_back();
	T pop_front();
	bool remove(const T &val);
	void reverse();
	void unique();
	T front();
	T back();
	bool empty();
private:
	ListNode<T>* head = NULL;
	ListNode<T>* tail = NULL;
};

template <class T>
List<T>::List() {}

template <class T>
List<T>::~List() {
	delete[] this->head;
}

template <class T>
bool List<T>::empty() {
	return this->head == NULL;
}


template <class T>
bool List<T>::push_back(const T &val) {
	ListNode<T>* node = new ListNode<T>(val);
	if (node == NULL) return false;

	if (this->head == NULL) {
		this->head = node;
		this->tail = node;
		return true;
	}

	this->tail->next = node;
	this->tail = node;
	return true;
}

template <class T>
bool List<T>::push_front(const T& val) {
	ListNode<T>* node = new ListNode<T>(val);
	if (node == NULL) return false;

	if (this->head == NULL) {
		this->head = node;
		this->tail = node;
		return true;
	}

	node->next = this->head;
	this->head = node;
	return true;
}

template <class T>
T List<T>::pop_front() {
	if (this->empty()) {
		throw("List is empty!");
	}

	T ret = this->head->val;

	ListNode<T>* waitDelete = this->head;
	this->head = this->head->next;
	waitDelete->next = NULL;
	delete waitDelete;
	if (this->head == NULL) this->tail = NULL;
	return ret;
}


template <class T>
T List<T>::pop_back() {
	if (this->empty()) {
		throw("List is empty!");
	}

	T ret = this->tail->val;

	ListNode<T>* cur = this->head;
	while (cur->next != this->tail) {
		cur = cur->next;
	}

	ListNode<T>* waitDelete = this->tail;
	this->tail = cur;
	cur->next = NULL;
	delete waitDelete;
	if (this->tail == NULL) this->head = NULL;
	return ret;
}

template <class T>
T List<T>::front() {
	if (this->empty()) {
		throw("List is empty!");
	}
	return this->head->val;
}

template <class T>
T List<T>::back() {
	if (this->empty()) {
		throw("List is empty");
	}
	return this->tail->val;
}

template <class T>
bool List<T>::remove(const T& val) {
	if (this->empty()) return false;

	ListNode<T>* cur = this->head;
	while (cur != NULL && cur->val == val) {
		ListNode<T>* waitDelete = cur;
		cur = cur->next;
		waitDelete->next = NULL;
		delete waitDelete;
	}
	this->head = cur;
	ListNode<T>* pre = cur;
	cur = cur->next;

	while (cur != NULL) {
		if (cur->val == val) {
			ListNode<T>* waitDelete = cur;
			cur = cur->next;
			waitDelete->next = NULL;
			delete waitDelete;
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	pre->next = NULL;
	this->tail = pre;
	return true;
}