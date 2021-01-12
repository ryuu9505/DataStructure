#include <iostream>
#include <string>
using namespace std;


template <typename Object>
class Stack
{
	int size() const;
	bool isEmpty() const;
	const Object& top() throw(StackEmptyException);
	void push(const Object& obj) throw(StackFullException);
	Object pop() throw(StackEmptyException);
};

class RuntimeException
{
private:
	string errorMsg;
public:
	RuntimeException(const string& err)
	{
		errorMsg = err;
	}
	string getMessage() const
	{
		return errorMsg;
	}
};

inline std::ostream& operator<<(std::ostream& out, const RuntimeException& e)
{
	return out << e.getMessage();
}

class StackEmptyException : public RuntimeException
{
public:
	StackEmptyException(const string& err) : RuntimeException(err){}
};

class StackFullException : public RuntimeException
{
public:
	StackFullException(const string& err) : RuntimeException(err) {}
};

template <typename Object>
int Stack<Object>::size() const
{

}

template <typename Object>
bool Stack<Object>::isEmpty() const
{

}

template <typename Object>
const Object& Stack<Object>::top() throw(StackEmptyException)
{

}

template <typename Object>
Object Stack<Object>::pop() throw(StackEmptyException)
{

}
template <typename Object>
void Stack<Object>::push(const Object& obj) throw(StackFullException)
{

}
