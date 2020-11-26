template <class T>
class ListNode() {
	T val;
	ListNode* next;
	ListNode(T x) : val(x), next(NULL) {}
}

template <class T>
class list() {
public:
	list();
	~list();
	bool push_back(const T &val);
	bool push_front(const T&val);
	T pop_back();
	T pop_front();
	bool remove(const T &val);
	void reverse();
	void unique();
	T front();
	T back();
	bool empty();
private:
	head = NULL;
	tail = NULL;
};

template <class T>
list() {}

template <class T>
~list() {
	delete[] this->head;
}

template <class T>
bool list<T>::empty() {
	return this->head == NULL;
}


template <class T>
bool list<T>::push_back(const T &val) {
	ListNode<T>* node = new ListNode(val);
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
bool list<T>::push_front(const T &val) {
	ListNode<T>* node = new ListNode(val);
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
T list<T>::pop_front() {
	if (this->empty()) {
		throw("list is empty!");
	}

	T ret = this->head->val;

	ListNode<T> *waitDelete = this->head;
	this->head = this->head->next;
	waitDelete->next = NULL;
	delete waitDelete;
	if (this->head == NULL) this->tail = NULL;
	return ret;
}


template <class T>
T list<T>::pop_back() {
	if (this->empty()) {
		throw("list is empty!");
	}

	T ret = this->tail->val;

	ListNode<T> *cur = this->head;
	while (cur->next != this->tail) {
		cur = cur->next;
	}

	ListNode<T> *waitDelete = this->tail;
	this->tail = cur;
	delete waitDelete;
	return ret;
}

template <class T>
T list<T>::front() {
	if (this->empty()) {
		throw("list is empty!");
	}
	return this->head->val;
}

template <class T>
T list<T>::back() {
	if (this->empty()) {
		throw("list is empty");
	}
	return this->tail->val;
}

template <class T>
void list<T>::remove(const T &val) {
	if (this->empty()) return;

	ListNode<int> *cur = this->head;
	while (cur != NULL && cur->val == val) {
		ListNode<T> *waitDelete = cur;
		cur = cur->next;
		waitDelete->next = NULL;
		delete waitDelete;
	}
	this->head = cur;


	while (cur != NULL) {
		if (cur->val == val) {
			ListNode<T> *waitDelete = cur;

		}
	}
}